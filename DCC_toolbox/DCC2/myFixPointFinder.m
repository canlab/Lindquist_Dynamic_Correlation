function [ x ] = myFixPointFinder( epsilon,deltaX,x0 )
%% Efficiently find the solution for fixed point x: F(x,Y0,vecS0)=x
%   Syntax:
%       [ x ] = myFixPointFinder( epsilon,deltaX,x0 )
%   Input: 
%       epsilon: standardized residual time series, size T-by-K
%       deltaX: precision of parameter X
%       x0: initial value
%   Output:
%       x: MLE of 1-by-2 dcc parameter X
%   Used by:
%       garchDCC_X.m
%   Function dependency:
%       F_mex
%       G_mex

%%
Y0 = epsilonToY(epsilon);
vecS0 = mean(Y0,2);

if nargin < 3
    x0 = rand(1,2);
    while sum(x0) >= 1
        x0 = rand(1,2);
    end
end

if nargin < 2
    deltaX = 10^(-4);
end

options = optimoptions('fmincon','Display','off','StepTolerance',deltaX,'Algorithm','sqp');

for q = 1:50
    temp = F_mex(x0,Y0,vecS0)-x0;
    if max(abs(temp))< deltaX
        break
    else
        x0 = x0 + rand()*temp;
    end
end

if q==50
    x = fmincon(@(para)G_mex(para,Y0,vecS0),x0,[1 1],1,[],[],[0 0],[1 1],[],options);
else
    x = x0;
end


end

