function [ r, H, R ] = generateData( K, T, theta, para, burnIn )
%% generating simulation data from DCC model
%   Syntax:
%       [ r, H, R ] = generateData( K, T, theta, para, burnIn )
%   Input:
%       K = dimension of time series
%       T = length of time series
%       theta = garch(1,1) parameters for volatilities
%       para = [alpha beta] dynamic correlation parameters
%       burnIn = how many initial data to discard
%   Output:
%       r = T-by-K data matrix
%       H: H_1,...,H_T conditional covariance, K*K*T matrix.
%       R: R_1,...,R_T conditional correlation, K*K*T matrix.

%%
alpha = para(1);
beta = para(2);
T0 = T+burnIn;

% initial value 
Q = eye(K);
Rt = eye(K);
mu0 = zeros(1,K);
h = ones(1,K);

%temp = rand(K,K);
%temp = (temp + temp')/2;
%S = eye(K) + 0.1*temp;
S = eye(K);

H = zeros(K,K,T0);
R = ones(K,K,T0);

r = zeros(T0,K);
for t = 1:T0
    epsilon = mvnrnd(mu0,Rt);
    rt = epsilon.*sqrt(h);
    r(t,:) = rt;
    Q = (1-alpha-beta)*S + alpha*(epsilon'*epsilon) + beta*Q; % Q_{t+1}
    Rt = diag(1./sqrt(diag(Q)))*Q*diag(1./sqrt(diag(Q))); % R_{t+1}
    h = theta(1) + theta(2)*rt.^2 + theta(3)*h;  % D_{t+1}
    
    R(:,:,t) = Rt;
    H(:,:,t) = diag(sqrt(h))*Rt*diag(sqrt(h));
end

r = r((burnIn+1):T0,:);
R = R(:,:,(burnIn+1):T0);
H = H(:,:,(burnIn+1):T0);

end

