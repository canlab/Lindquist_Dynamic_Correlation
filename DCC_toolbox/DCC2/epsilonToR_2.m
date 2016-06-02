function [ R, S0 ] = epsilonToR_2( epsilon, para )
% auxiliary function, calculate time-varying conditional correlation matrix
% from standardized returns.
%
% Syntax:
%       [ R ] = epsilonToR( epsilon, para )
% Input:
%       epsilon: standardized residual time series, size T-by-K
%       para: 1-by-2 dcc parameter vector
% Output:
%       R: K-by-K-by-T conditional correlation matrix, when K = 2, only
%          output the off-diagonal element of R_t to save space, so R is 1-by-T matrix 
%       S0: K-by-K matrix, unconditional correlation matrix
% Used by:
%       garchDCC_X.m


T = size(epsilon,1);
K = size(epsilon,2);

S2 = corr(epsilon);
SS = S2*(1-sum(para));

Q = S2;

S0 = zeros(K,K);

R = zeros(K,K,T);
    for t = 1:T
        temp = epsilon(t,:).*sqrt(diag(Q))';
        temp2 = temp'*temp;
        S0 = S0 + temp2;
        Q = SS + para(1)*temp2 + para(2)*Q;
        R(:,:,t) = diag(1./sqrt(diag(Q)))*Q*diag(1./sqrt(diag(Q)));
    end

S0 = S0/T;


end