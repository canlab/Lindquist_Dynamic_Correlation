function [regions, wh] = dcc_sim_generate_data1(data_options)
% Simple data generation process for two time series with a correlated section (region) of data
% and zero correlation before and after.  Fixed time points and windows
%
% regions = t x 2 matrix of two time series
% wh = which time points have TRUE inter-region correlations
%
% Requires data_options structure with rval and smooth fields
%
% Example:
% regions = dcc_sim_generate_data1(struct('rval', .5, 'smooth', true));
%

t = 500;
wh = 151:350; % window

regions = zeros(t, 2);

regions(1:150, :) = mvnrnd([0 0], [1 0; 0 1], 150);
regions(351:t, :) = mvnrnd([0 0], [1 0; 0 1], 150);
regions(151:350, :) = mvnrnd([0 0], [1 data_options.rval; data_options.rval 1], 200);

if data_options.smooth  % arbitrary smoothing.  Later versions could more precisely control this.
    for i = 1:2
        regions(:, i) = smooth(regions(:, i));
    end
    
    for i = 1:2
        regions(:, i) = smooth(regions(:, i));
    end
end

end % function




