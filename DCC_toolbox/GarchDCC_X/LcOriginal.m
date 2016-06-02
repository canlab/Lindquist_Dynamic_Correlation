function [ output ] = LcOriginal( epsilon, para )
% Calculate the correlation component in log-likelihood, eq.(29) in ref paper
% Syntax:
%       [ output ] = LcOriginal( epsilon, para )
% Input:
%       epsilon: standardized residual time series, size T-by-K
%       para: 1-by-2 dcc parameter vector
% Output: 
%       a real number proportional to the correlation component in negative log-likelihood( to be minimized )
% Used by:
%       DCC_X.m

T = size(epsilon,1);
K = size(epsilon,2);

%S2 = corr(epsilon);
S2 = cov(epsilon);
SS = S2*(1-sum(para));

Q = S2;
R = diag(1./sqrt(diag(Q)))*Q*diag(1./sqrt(diag(Q)));

output = 0;

if K==2
    % when K = 2, use some complicate expression to speed up
    p = R(1,2);
    for t = 1:T
        output = output + log(1-p^2) + (sum(epsilon(t,:).^2)- p*epsilon(t,1)*epsilon(t,2))/(1-p^2);
        temp = epsilon(t,:).*sqrt(diag(Q))';
        Q = SS + para(1)*(temp'*temp) + para(2)*Q;
        p = Q(1,2)/sqrt(Q(1,1)*Q(2,2));
    end  
else
    for t = 1:T
        output = output + log(det(R)) + epsilon(t,:)/R*epsilon(t,:)';
        temp = epsilon(t,:).*sqrt(diag(Q))';
        Q = SS + para(1)*(temp'*temp) + para(2)*Q;
        R = diag(1./sqrt(diag(Q)))*Q*diag(1./sqrt(diag(Q)));
    end
end

end
