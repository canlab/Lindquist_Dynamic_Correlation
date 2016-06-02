function [ epsilon, d ] = rToEpsilon( r, theta )
% auxiliary function, perform eq.(25) line 3 of reference paper:epsilon_t = D_t^(-1)*r_t
% Syntax:
%       [ epsilon, d ] = rToEpsilon( r, theta )
% Input:
%       theta: fitted univaraite garch parameter theta (1-by-3 vector)
%       r: one dimensional time series
% Output: 
%       epsilon: standardized residual vector, same size as r.
%       d: estimated conditional volatility vector, same size as r.
% Used by:
%       DCC_X.m

T = size(r,1);
epsilon = zeros(size(r));
d = zeros(size(r));
d(1) = mean(r.^2);

for t = 1:(T-1)
    epsilon(t) = r(t)/sqrt(d(t));
    d(t+1) = theta(1) + theta(2)*r(t)^2 + theta(3)*d(t);
end

epsilon(T) = r(T)/sqrt(d(T));

end

