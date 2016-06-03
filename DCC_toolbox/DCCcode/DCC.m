function C = DCC(Dat, varargin)
% Standard text for function documentation
%
% Estimate time-varying Dynamic Conditional Correlations (DCC) across pairs of time series variables
%
% :Usage:
% ::
%
%     [outputs] = function_name(inputs, [optional inputs])
%     C = DCC(dat, ['whiten'], ['residualize'], [model matrix X])
% ..
%     Author and copyright information:
%
%     Copyright (C) 2016 Martin Lindquist
%
%     This program is free software: you can redistribute it and/or modify
%     it under the terms of the GNU General Public License as published by
%     the Free Software Foundation, either version 3 of the License, or
%     (at your option) any later version.
%
%     This program is distributed in the hope that it will be useful,
%     but WITHOUT ANY WARRANTY; without even the implied warranty of
%     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
%     GNU General Public License for more details.
%
%     You should have received a copy of the GNU General Public License
%     along with this program.  If not, see <http://www.gnu.org/licenses/>.
%
% Updated 6/2/2016 by Martin Lindquist and Tor Wager to add
% options/whitening
% ..
%
% :Inputs:
%
%   **Dat:**
%        [time points x variables] data matrix
%
% :Optional Inputs:
%   **'whiten':**
%        Use ARMA(1, 1) model to autocorrelation
%
%   **'residualize':**
%        Followed by model matrix X, [time points x predictors], to remove
%        prior to whitening and dynamic correlation estimation
%
% :Outputs:
%
%   **C:**
%        Correlation matrix, [variables x variables x time points] 
%
% :Examples:
% ::
%    
%    regions = dcc_sim_generate_data1(struct('rval', .5, 'smooth', true));
%    C = DCC(regions);
%    rseries = squeeze(C(1, 2, :));
%    figure; plot(rseries);
%
%    % Now remove nuisance matrix X and whiten
%    X = randn(length(regions), 1);  X(:, end+1) = 1;
%    C = DCC(regions, 'whiten', 'residualize', X);
%    rseries = squeeze(C(1, 2, :));
%    hold on; plot(rseries); 
%
% :References:
%   Lindquist (2015).  Neuroimage.
%
% :See also:
%   DCCx.m, time_varying_estimate.m, slidingwindow.m,
%   canlab_connectivity_predict.m, xcorr_multisubject.m
%

% ..
%    Programmers' notes:
%    2016 June 2: Tor added documentation, resid option. Martin+Tor added
%    autocorrelation estimate, simulations.
% ..


% -------------------------------------------------------------------------
% DEFAULTS AND INPUTS
% -------------------------------------------------------------------------

% initalize optional variables to default values here.

dowhiten = 0;
doresid = 0;

% optional inputs with default values
for i = 1:length(varargin)
    if ischar(varargin{i})
        switch varargin{i}

            case {'white', 'whiten'}, dowhiten = 1;
                
            case {'resid', 'residualize', 'X', 'model'}
                doresid = 1; 
                X = varargin{i + 1}; varargin{i + 1} = [];
                
            otherwise, warning(['Unknown input string option:' varargin{i}]);
        end
    end
end


% -------------------------------------------------------------------------
% MAIN FUNCTION
% -------------------------------------------------------------------------

[T,p] = size(Dat);
C = ones(p,p,T);

if doresid
   
    % break up for efficiency - otherwise Matlab slows down with large
    % matrices...or at least it used to...
    px = pinv(X);
    pxy = px * Dat;
    xpxy = X * pxy;
    Dat = Dat - xpxy; % X * pinv(X) * y;
    
end

if dowhiten
    
    Mdl = arima(1,0,1);
    
    opts = optimoptions('fmincon');
    opts.Algorithm = 'sqp';
    deltaX = 10^(-5);
    opts.TolX = deltaX;
    opts.TolCon = 10^(-6);
    opts.MaxFunEvals = 1000;
    
    indx = 0;
    fprintf('ARMA(1,1) on %d variables: %05d', p, indx);

    for k=1:p
        
        EstMdl = estimate(Mdl, Dat(:,k), 'Display', 'off', 'options', opts);
        
        [res, v] = infer(EstMdl,Dat(:,k));
        Dat(:,k) = res./sqrt(v);
        
        indx = indx + 1;
        fprintf('\b\b\b\b\b%05d', indx);
    end
    
    fprintf('\n');
    
end

% Loop through pairs and estimate
% -------------------------------------------------------------------------

n = p*(p-1) ./ 2;
indx = 0;

starttime = clock;

% create time to complete string
[day, hour, minute, second, display_string] = estimate_time_to_complete(starttime, 1, 1, 0);
bspace = repmat('\b', 1, length(display_string));

fprintf('Running %d pairs: Estimated complete in %s, %05d', n, display_string, indx);


for j=1:(p-1)  
    for k=(j+1):p
  
        [ Ctmat ] = DCCsimple([Dat(:,j) Dat(:,k)]); 
        C(j,k,:) = Ctmat(1,2,:); 
        C(k,j,:) = Ctmat(1,2,:); 

        indx = indx + 1;
        
        if indx == 1 || mod(indx, 10) == 0
            
            % Update time to complete
            fprintf('\b\b\b\b\b\b\b');  % remove number + 2 chars
            fprintf(bspace);            % remove old string
            
            [day, hour, minute, second, display_string] = estimate_time_to_complete(starttime, indx, n, 1);

            fprintf(', %05d', indx);
        else
            % Just update counter
            fprintf('\b\b\b\b\b%05d', indx);
        end
        
    end
end

fprintf('\n');

    
end % function

