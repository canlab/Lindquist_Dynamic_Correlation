function [ para_new ] = F(para,Y0,vecS0)
% Calculate mapping F
%   Input: 
%       para: 1-by-2 DCC parameters
%       Y0,vecS0: a series of vecterized outer product from standardized residual time series
%   Output:
%       para_new: mapping F(para,Y0,vecS0)
%   Function dependency:
%       epsilonToY.m

%% initialization
T = size(Y0,2);
K = floor(sqrt(length(vecS0)*2));
theta = 1-sum(para);

%% update the design matrix via DCC formular with old para

Qdiag = zeros(K,T);
Qdiag(:,1) = 1;

Ydiag = Y0(1:K,:);
Sdiag = vecS0(1:K,1);

for t = 2:T
    temp = Ydiag(:,t-1).*Qdiag(:,t-1);
    Qdiag(:,t) = theta*Sdiag + para(1)*temp + para(2)*Qdiag(:,t-1);
end

VU = epsilonToY( sqrt(Qdiag') );

Y = Y0.*VU;
vecS = mean(Y,2);
Y = Y - vecS*ones(1,T);

U = zeros(K*(K+1)/2,T);
U(:,1) = [ones(1,K) zeros(1,K*(K-1)/2)]' - vecS;
X = zeros(size(Y0,1),2,T);
X(:,1,1) = Y(:,1); X(:,2,1) =  U(:,1);

for t = 2:T
    U(:,t) = para(1)*Y(:,t-1) + para(2)*U(:,t-1);
    X(:,1,t) = Y(:,t);
    X(:,2,t) = U(:,t);
end

%% convex optimization step
b = zeros(2,1);
A = zeros(2,2);

for t = 2:T
    b = b + X(:,:,t-1)'*Y(:,t);
    A = A + X(:,:,t-1)'*X(:,:,t-1);
end

A = A/T;
b = b/T;
%para_new = (inv(A)*b)'; 
para_new = (A\b)';

if ~(para_new(1)>=0 && para_new(2)>=0 && (para_new(1)+para_new(2))<1)
    eta = 10^(-5);
    
    obj = zeros(1,3);
    paraAtBoundary = zeros(3,2);
    % case 1) para = [?, 0]
    p1 = b(1)/A(1,1);
    if p1 < 0
        p1 = eta;
    elseif p1 > 1
        p1 = 1-eta;
    end
    paraAtBoundary(1,:) = [p1 0];
    % case 2) para = [0, ?]
    p2 = b(2)/A(2,2);
    if p2 < 0
        p2 = eta;
    elseif p2 > 1
        p2 = 1-eta;
    end
    paraAtBoundary(2,:) = [p2 0];
    % case 3) para(1)+para(2) = 1
    p1 = ((b(1)-b(2))/2 + A(2,2)-A(1,2))/(A(1,1)-2*A(1,2)+A(2,2));
    if p1 < 0
        p1 = eta;
    elseif p1 > 1
        p1 = 1-eta;
    end
    p2 = 1-p1-eta;
    paraAtBoundary(3,:) = [p1 p2];
    
    for k=1:3
        obj(k) = paraAtBoundary(k,:)*A*paraAtBoundary(k,:)' - 2*paraAtBoundary(k,:)*b;
    end
    
    [val,index] = min(obj);
    if val < 0
        para_new = paraAtBoundary(index,:);
    else
        para_new = [0 0];
    end
end

end