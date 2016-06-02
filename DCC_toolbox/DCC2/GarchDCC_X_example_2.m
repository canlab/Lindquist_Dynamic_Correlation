%% Step (1) Generate Data from Garch-DCC model
K = 2; % dimension of time series
T = 2000; % time series length
burnIn = 500;

% parameters for modelling the volatility of each dimension as a Garch(1,1) process
theta = [0.01 0.05 0.9]; 
% parameters for conditional correlations
para = [0.1 0.8];
% generate data with true DCC model
%       r = T-by-K data matrix
%       H0: K*K*T matrix containing H_1,...,H_T, where H_t is the true conditional covariance matrix at time t. 
%       R0: K*K*T matrix containing R_1,...,R_T, where R_t is the true conditional correlation matrix at time t. 
[ r, H0, R0 ] =   generateData( K, T, theta, para, burnIn );

%% Step (2) Run garchDCC_X under different Parameter Settings
% (2.1) original dcc MLE estimator
method = 0; 
deMean = 1;
tic
[ X1, timeX1, dat1 ] = garchDCC_X( r, method, deMean );
toc

% (2.2) new moment estimator
method = 1; 
deMean = 1;
tic
[ X2, timeX2, dat2 ] = garchDCC_X( r, method, deMean );
toc

%% Step (3) compare estimate H,R with true value H0,R0
i = 4;
j = 5;

figure
subplot 121
plot(1:T,squeeze(H0(i,j,:)),'k.-',1:T,squeeze(dat1.H(i,j,:)),'b.-',1:T,squeeze(dat2.H(i,j,:)),'r.-')
xlabel('time')
title('Compare an element in time varying covariance matrix ')
legend('truth','MLE','new')

subplot 122
plot(1:T,squeeze(R0(i,j,:)),'k.-',1:T,squeeze(dat1.R(i,j,:)),'b.-',1:T,squeeze(dat2.R(i,j,:)),'r.-')
xlabel('time')
title('Compare an element in time varying correlation matrix ')
legend('truth','MLE','new')