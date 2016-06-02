function [ X, timeX, dat] = garchDCC_X( Y, method, deMean, CI )
%% Garch DCC algorithm
%   Ref: 
%       Engle R. Dynamic conditional correlation: A simple class of multivariate generalized autoregressive conditional heteroskedasticity models
%       [J]. Journal of Business & Economic Statistics, 2002, 20(3): 339-350.
%
%   Syntax:
%       [ X, timeX, dat] = garchDCC_X( Y, method, deMean, CI )
%
%   Input: 
%       Y = T-by-K time series matrix, length T, dimension K.
%       method = 0, Original DCC (MLE); 
%              = 1, our new RobustDCC moment estimator.
%       deMean = 1/0, whitening based on ARMA(1, 1) using ARIMA Matlab toolbox; AR1+white noise
%               0(default)/1,  remove autocorrelation-conditional mean (whiten) from each univariate time series
%
%       CI = 0(default)/1, whether compute the confidence interval for DCC parameters
%
%   Output:
%       X:  1-by-2 DCC parameters, [ARCH_parameter, GARCH_parameter].
%       timeX: CPU time for estimating parameter X. 
%       dat: a structure array contains the following fileds:
%           dat.H: H_1,...,H_T estimate conditional covariance, K*K*T matrix.
%           dat.R: R_1,...,R_T estimate conditional correlation, K*K*T matrix.
%           dat.S0: estimate unconditional correlation, K*K matrix.
%           dat.D: T-by-K matrix, estimate conditional variance by Garch(1,1) model
%           dat.epsilon: T-by-K residual after 'deMean' process
%           dat.Theta: K-by-3 Garch(1,1) parameters for volatilities, [Constant, ARCH_parameter, GARCH_parameter]
%
%   Function dependency:
%       dccMLE.m
%           LcOriginal_mex
%       myFixPointFinder.m
%           F_mex
%               epsilonToY.m
%           G_mex_mex
%       epsilonToR_2.m
%
% (Last modified by: Yuting Xu)

%% Initialization

% set default input arguments
if nargin < 4
    CI = 0;
end

if nargin < 3
    deMean = 0;
end

% Input dimension
T = size(Y,1);
K = size(Y,2);

% set precision of parameter X
deltaX = 10^(-5);

% ARMA(1,1) and GARCH(1,1) composite model for prewhitening each dimension in
% multivariate time series
Mdl = arima(1,0,1);
Mdl.Variance = garch(1,1);


opts = optimoptions('fmincon');
opts.Algorithm = 'sqp';

[version_num, version_name, version_date] = check_matlab_version;
if version_date > datenum('01-Jan-2016')
    
    opts.StepTolerance = deltaX;
    opts.ConstraintTolerance = 10^(-6);
    opts.MaxFunctionEvaluations = 1000;
    
else
    opts.TolX = deltaX;
    opts.TolCon = 10^(-6);
    opts.MaxFunEvals = 1000;
end

% create Output variables
dat = struct;
dat.H = zeros(K,K,T);
dat.R = ones(K,K,T);
dat.D = zeros(size(Y));
dat.epsilon = zeros(size(Y));
dat.Theta = zeros(K,3);


%% fit a univariate GARCH process for each dimension
if deMean == 1 % whitening based on ARMA(1, 1) using ARIMA Matlab toolbox; AR1+white noise
    for k = 1:K
        try
            EstMdl = estimate(Mdl,Y(:,k),'Display','off','options',opts);
            dat.Theta(k,:) = [EstMdl.Variance.Constant EstMdl.Variance.ARCH{1} EstMdl.Variance.GARCH{1}];
        catch
            EstMdl = estimate(arima('ARLags',1),Y(:,k),'Display','off','options',opts);
            dat.Theta(k,:) = [EstMdl.Variance 0 0];            
        end
        [res, v] = infer(EstMdl,Y(:,k));
        dat.epsilon(:,k) = res./sqrt(v);
        dat.D(:,k) = v;
    end
else
    dat.epsilon = Y - repmat(mean(Y),T,1); % simple demean
    dat.Theta = NaN;
    dat.D = NaN;
    dat.H = NaN;
end

%% estimate parameter X, which related to dynamic correlation matrix
tic;
if method == 0
    % Original DCC (MLE);
    X = dccMLE( dat.epsilon, deltaX);
else
    % our new RobustDCC moment estimator.
    X = myFixPointFinder( dat.epsilon,deltaX );
end
timeX = toc;

%% Calculate output conditional correlation matrix R_1,...R_T
[dat.R, dat.S0] = epsilonToR_2( dat.epsilon, X );

%% Calculate output conditional covariance matrix H_1,...H_T
if deMean == 1
    for t = 1:T
        dat.H(:,:,t) = diag(sqrt(dat.D(t,:)))*dat.R(:,:,t)*diag(sqrt(dat.D(t,:)));
    end
end

%% confidence interval
if CI == 1
    dat.Xnew = zeros(100,2);
    for rep = 1:100
        r = generateData_corr( K, T, X, floor(T/5), dat.S0 );
        dat.Xnew(rep,:) = myFixPointFinder( r,deltaX, X);
    end
    %  calculate 95% CI
    dat.CIalpha = [X(1)-1.96*std(dat.Xnew(:,1)),X(1)+1.96*std(dat.Xnew(:,1))];
    dat.CIbeta = [X(2)-1.96*std(dat.Xnew(:,2)),X(2)+1.96*std(dat.Xnew(:,2))];
end

end