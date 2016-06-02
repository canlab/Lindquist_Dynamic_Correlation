function [ H,R,Theta,X ] = DCC_X( r, allpair, parallel )
%% Original DCC algorithm
%   Ref: 
%       Engle R. Dynamic conditional correlation: A simple class of multivariate generalized autoregressive conditional heteroskedasticity models
%       [J]. Journal of Business & Economic Statistics, 2002, 20(3): 339-350.
%
%   Syntax:
%       [ H,R,Theta,X ] = DCC_X( r, allpair, parallel )
%
%   Input: 
%       r = T-by-K time series matrix
%       allpair = 0 Original DCC
%       allpair != 0 all pairs of bivariate DCC
%       parallel = 0 Don't use parallel, otherwise using parfor when allpair != 0
%   Output:
%       H: H_1,...,H_T estimate conditional covariance, K*K*T matrix.
%       R: R_1,...,R_T estimate conditional correlation, K*K*T matrix.
%       Theta: K-by-3 garch(1,1) parameters for volatilities
%       X: (allpair = 0, original DCC) 1-by-2 DCC parameters
%          (allpair != 0, all bivariate pairs) K*(K-1)/2-by-2 MLE for DCC parameters
%   Function dependency:
%       rToEpsilon.m
%       loglikelihood_garch11.m
%       LcOriginal.m
%       epsilonToR.m
%
% (Last modified by: Yuting Xu)

%% Initialization
% Input dimension
T = size(r,1);
K = size(r,2);
r = r-repmat(mean(r),T,1);  %demean

% Output space
H = zeros(K,K,T);
R = ones(K,K,T);
Theta = zeros(K,3);

% intermediate parameters
epsilon = zeros(size(r));
D = zeros(size(r));

% parameters for fmincon function
A = [0 1 1];
B = 1;
LB = [0 0 0];

A2 = [1 1];
LB2 = [0 0];

options = optimoptions('fmincon','Display','off');

%% fit a univariate GARCH process for each dimension
if parallel == 0
    for k = 1:K
        theta0 = rand(1,3)/2;
        para = fmincon(@(x)loglikelihood_garch11(r(:,k),x),theta0,A,B,[],[],LB,[],[],options);
        [ ep, d ] = rToEpsilon( r(:,k), para );
        Theta(k,:) = para;
        epsilon(:,k) = ep;
        D(:,k) = d;
    end
else
    parfor k = 1:K
        theta0 = rand(1,3)/2;
        para = fmincon(@(x)loglikelihood_garch11(r(:,k),x),theta0,A,B,[],[],LB,[],[],options);
        [ ep, d ] = rToEpsilon( r(:,k), para );
        Theta(k,:) = para;
        epsilon(:,k) = ep;
        D(:,k) = d;
    end     
end

%% estimate parameter X, which related to dynamic correlation matrix

if allpair==0
    x0 = rand(1,2)/2;
    X = fmincon(@(x)LcOriginal(epsilon,x),x0,A2,B,[],[],LB2,[],[],options);
    if K==2
         temp = epsilonToR( epsilon, X );
         R(1,2,:) = temp;
         R(2,1,:) = temp;
    else
        R = epsilonToR( epsilon, X );
    end
    
else
    X = zeros(K,K,2);
    
    if parallel == 0
        
        for i = 1:(K-1)
            for j = (i+1):K
                x0 = rand(1,2)/2;
                x = fmincon(@(x)LcOriginal(epsilon(:,[i j]),x),x0,A2,B,[],[],LB2,[],[],options);  
                X(i,j,:) = x;
                temp = epsilonToR( epsilon(:,[i j]), x );
                R(i,j,:) = temp;
                R(j,i,:) = temp;
            end
        end
        
    else    
        
        M = K*(K-1)/2;
        Index = zeros(M,2);
        count = 0;
        for i = 1:(K-1)
            for j = (i+1):K
                count = count + 1;
                Index(count,:) = [i j];
            end
        end
        RR = zeros(M,T);
        XX = zeros(M,2);
        parfor m = 1:M
                tempIndex = Index(m,:);
                %i = Index(m,1);
                %j = Index(m,2);
                x0 = rand(1,2)/2;
                x = fmincon(@(x)LcOriginal(epsilon(:,tempIndex),x),x0,A2,B,[],[],LB2,[],[],options);  
                XX(m,:) = x;
                RR(m,:) = epsilonToR( epsilon(:,tempIndex), x );
        end
        
        for m = 1:M
            i = Index(m,1);
            j = Index(m,2);
            R(i,j,:) = RR(m,:);
            R(j,i,:) = RR(m,:);
            X(i,j,:) = XX(m,:);
        end
        
        
    end
    
end

%% Calculate output conditional ovariance matrix H_1,...H_T
if parallel==0
    for t = 1:T
        H(:,:,t) = diag(sqrt(D(t,:)))*R(:,:,t)*diag(sqrt(D(t,:)));
    end
else
    parfor t = 1:T
        H(:,:,t) = diag(sqrt(D(t,:)))*R(:,:,t)*diag(sqrt(D(t,:)));
    end        
end

end