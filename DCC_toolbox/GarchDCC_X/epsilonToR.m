function [ R ] = epsilonToR( epsilon, para )
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
% Used by:
%       DCC_X.m


T = size(epsilon,1);
K = size(epsilon,2);

S2 = corr(epsilon);
SS = S2*(1-sum(para));

Q = S2;

if K==2
    R = zeros(1,T);
    for t = 1:T
        temp = epsilon(t,:).*sqrt(diag(Q))';
        Q = SS + para(1)*(temp'*temp) + para(2)*Q;
        R(t) = Q(1,2)/sqrt(Q(1,1)*Q(2,2));
    end  
else
    R = zeros(K,K,T);
    for t = 1:T
        temp = epsilon(t,:).*sqrt(diag(Q))';
        Q = SS + para(1)*(temp'*temp) + para(2)*Q;
        R(:,:,t) = diag(1./sqrt(diag(Q)))*Q*diag(1./sqrt(diag(Q)));
    end
end


end