function [ x1_final ] = dccMLE( epsilon, deltaX, M )
% Estimate the MLE for DCC parameter X
%   Input: 
%       epsilon: standardized residual time series, size T-by-K
%       deltaX: precision of parameter X
%       M: number of random starts when using fmincon to find optimized X
%   Output:
%       x1_final: MLE of 1-by-2 dcc parameter X
%   Used by:
%       garchDCC_X.m
%   Function dependency:
%       LcOriginal_mex

if nargin < 3
    M = 5;
end

if nargin < 2
    deltaX = 10^(-4);
end

[version_num, version_name, version_date] = check_matlab_version;
if version_date > datenum('01-Jan-2016')
    
    options = optimoptions('fmincon','Display','off','StepTolerance',deltaX,'Algorithm','interior-point');
    
else
    
    options = optimoptions('fmincon','Display','off','TolX',deltaX,'Algorithm','interior-point');
    
end


x1 = zeros(M,2);
f1 = zeros(M,1);

for m = 1:M
    x0 = rand(1,2);
    while(sum(x0) >= 1)
        x0 = rand(1,2);
    end
    x1(m,:) = fmincon(@(x)LcOriginal_mex(epsilon,x),x0,[1 1],1,[],[],[0 0],[1 1],[],options);
    f1(m) = LcOriginal_mex(epsilon,x1(m,:));
end

[~,index] = min(f1);
x1_final = x1(index,:);

end

