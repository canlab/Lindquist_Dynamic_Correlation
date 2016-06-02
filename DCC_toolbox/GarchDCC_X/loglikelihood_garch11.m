function [ output ] = loglikelihood_garch11( data, theta )
% [Syntax]
%   [ output ] = loglikelihood_garch11( data, theta )
% [Input]
%   data: one dimensional time series 
%   theta: 1-by-3 garch (1,1) parameter vector
% [Output]
%   a real number proportional to the negative log-likelihood of univariate garch model( to be minimized )
% [Used by]
%   DCC_X.m

h = mean(data.^2);
T = size(data,1);
output = 0;

for t = 1:T
    output = output + data(t)^2/h + log(h);
    h = theta(1) + theta(2)*data(t)^2 + theta(3)*h;
end

end

