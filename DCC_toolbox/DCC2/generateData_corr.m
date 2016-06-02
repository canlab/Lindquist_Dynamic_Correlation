function [ r, R ] = generateData_corr( K, T, para, burnIn, S )
%% generating simulation data from reduced_DCC model (no volatility, corr only)
%   Syntax:
%       [ r, R ] = generateData( K, T, theta, para, burnIn )
%   Input:
%       K = dimension of time series
%       T = length of time series
%       para = [alpha beta] dynamic correlation parameters
%       burnIn = how many initial data to discard
%       S = unconditional correlation matrix
%   Output:
%       r = T-by-K data matrix
%       R: R_1,...,R_T conditional correlation, K*K*T matrix.

%%
alpha = para(1);
beta = para(2);
T0 = T+burnIn;

if nargin < 5
    % if no user input unconditional correlation matrix S
    S = eye(K);
end

% initial value 
Q = eye(K);
Rt = eye(K);
mu0 = zeros(1,K);

R = ones(K,K,T0);
r = zeros(T0,K);

for t = 1:T0
    R(:,:,t) = Rt;
    epsilon = mvnrnd(mu0,Rt);
    r(t,:) = epsilon;
    Q = (1-alpha-beta)*S + alpha*(epsilon'*epsilon) + beta*Q; % Q_{t+1}
    Rt = diag(1./sqrt(diag(Q)))*Q*diag(1./sqrt(diag(Q))); % R_{t+1}
end

r = r((burnIn+1):T0,:);
R = R(:,:,(burnIn+1):T0);

end