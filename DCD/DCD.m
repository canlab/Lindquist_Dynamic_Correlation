function [ splitPoints, Delta ] = DCD( Y, alpha, beta, eta )
% Complete DCD program
%  [Inputs] 
%  Y: data matrix, dimsion T-by-J, T = time length, J = # of ROIs
%  alpha: type I error rate of comparing two splits, default = 0.05.
%  beta: type II error rate of comparing two splits, default = 0.05;
%  eta: false positive rate of feature selection, default = 0.02;
%  [Outputs]
%  splitPoints: Estimate split points.
%  calculated minimum segment length

T = size(Y,1);
J = size(Y,2);

if ~exist('alpha','var')
    alpha = 0.05;
elseif alpha < 0 || alpha > 1
    error('invalid valud of alpha')
end

if ~exist('beta','var')
    beta = 0.05;
elseif beta < 0 || beta > 1
    error('invalid valud of beta')
end

if ~exist('eta','var')
    eta = 0.02/J;
elseif eta < 0 || eta > 1
    error('invalid valud of eta')
else
    eta = eta/J;
end

% Decide minimum length of splits Delta
% through sample size calculation in power analysis of two sample t-test

beta = beta/(J^2);
Delta = 10;
temp_beta = 100;
while temp_beta > beta
    Delta = Delta + 1;
    temp_beta = tcdf(tinv(1-alpha/2/J,Delta*2-2)-1/sqrt(2/Delta), Delta*2-2);
end

if Delta > T/2
    error('insufficient time series length under current parameter setting!')
end

% Decide whether to use feature selection method or not
method = 0; % default, no feature selection
if J > 15 || J > Delta*0.6
    method = 1; % with feature selection
end


mask0 = ones(1,J + J*(J+1)/2);

if method == 1 
    % with feature selection
    bic0 = size(Y,1)* (log(det(cov(Y)))+ J);
    splitPoints = SplitSearch1( Y, bic0, Delta, alpha, eta, mask0);
else
    % no feature selection
    bic0 = size(Y,1)* log(det(cov(Y)));
    splitPoints = SplitSearch2( Y ,bic0, Delta, alpha);
end


end

