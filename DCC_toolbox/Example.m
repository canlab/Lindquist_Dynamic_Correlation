%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Example script for Dynamic Correlation Toolbox
%
% File created by Martin Lindquist 07/22/14
%
% Makes use of functions from the UCSD_Garch toolbox by Kevin Shepard (Please see license agreement)
%
% Before running this script, begin by adding the DC_toolbox and all its subdirectories to the Matlab path.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Create simulated data set 

% Define data dimensions
p = 3;         % Number of nodes
T = 200;        % Numer of time points

% Generate null data
mu = zeros(p,1);
Sigma = eye(p);
dat=mvnrnd(mu,Sigma,T);     

% Note the input data has dimensions T-by-p (time by #nodes)


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Fit DCC

% Simple quick version that assumes common dynamic across all nodes. Not
% recommended for problems with larger values of p.

[Ct1 ] = DCCsimple(dat);

% Slower, more accurate version
[Ct2 ] = DCC(dat);

% Ct1 is the dynamic correlation matrix 



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Fit sliding-window correlations
windowsize = 20;
[ Ct3 ] = sliding_window(dat,windowsize);

% Ct2 is the sliding window correlation matrix 


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Plot some of the results

figure
subplot 221
imagesc(Ct2(:,:,100), [-1 1])          % Plot the conditional correlation matrix at time 100
colorbar
title('DCC - conditional correlation at time 100')

subplot 222
plot(squeeze(Ct2(1,3,:)))    % Plot the dyanamic correlation between nodes 1 and 3.
ylim([-0.7 0.7])
hold
plot(1:T,zeros(T,1),'-r')    % Plot the true dyanamic correlation between nodes 1 and 3.
title('DCC - dynamic correlation between nodes 1 and 3')


subplot 223
imagesc(Ct3(:,:,100), [-1 1])          % Plot the conditional correlation matrix at time 100
colorbar
title('SWC - conditional correlation at time 10')

subplot 224
plot(squeeze(Ct3(1,3,:)))    % Plot the dyanamic correlation between nodes 1 and 3.
ylim([-0.7 0.7])
hold
plot(1:T,zeros(T,1),'-r')    % Plot the true dyanamic correlation between nodes 1 and 3.
title('SWC - dynamic correlation between nodes 1 and 3')

