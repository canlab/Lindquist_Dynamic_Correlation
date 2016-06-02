% Simulate true and false positive rates for DCC versions and options

% -------------------------------------------------------------------------
% DEFAULTS AND INPUTS
% -------------------------------------------------------------------------

% Data parameters
data_options.rval = .8;    % correlation for true pos region (in time)
data_options.smooth = 1;    % induce temporal autocorrelation or not

% Simulation parameters
sim_options.iter = 10;
sim_options.models = {'DCC' 'DCC whitened' 'DCCx' 'SlidingWindow'}; 

sim_results.models = {};
[sim_results.tpr, sim_results.fpr] = deal([]);

% -------------------------------------------------------------------------
% ITERATIONS
% -------------------------------------------------------------------------

for i = 1:sim_options.iter

[regions, wh_true_timepoints] = dcc_sim_generate_data1(data_options);

modelnum = 1;

% original DCC
wh = strcmp(sim_options.models, 'DCC');
if any(wh)
    sim_results.models(modelnum) = sim_options.models(wh);
    
    C = DCC(regions);
    estimates = (squeeze(C(1, 2, :)));
    
    % get columns of true and false positives, iterations x models
    [sim_results.tpr(i, modelnum) sim_results.fpr(i, modelnum)] = dcc_sim1_get_tpr_fpr(estimates, wh_true_timepoints);
    
    modelnum = modelnum + 1;
end

% original DCC with autocorrelation modeling
wh = strcmp(sim_options.models, 'DCC whitened');
if any(wh)
    sim_results.models(modelnum) = sim_options.models(wh);
    
    C = DCC(regions, 'whiten');
    estimates = (squeeze(C(1, 2, :)));
    
    % get columns of true and false positives, iterations x models
    [sim_results.tpr(i, modelnum) sim_results.fpr(i, modelnum)] = dcc_sim1_get_tpr_fpr(estimates, wh_true_timepoints);
    
    modelnum = modelnum + 1;
end

wh = strcmp(sim_options.models, 'DCCx');
if any(wh)
    sim_results.models(modelnum) = sim_options.models(wh);
    
    [HR,C] = DCC_X( regions, 1, 0 );
    estimates = (squeeze(C(1, 2, :)));
    
    % get columns of true and false positives, iterations x models
    [sim_results.tpr(i, modelnum) sim_results.fpr(i, modelnum)] = dcc_sim1_get_tpr_fpr(estimates, wh_true_timepoints);
    
    modelnum = modelnum + 1;
end

wh = strcmp(sim_options.models, 'SlidingWindow');
if any(wh)
    sim_results.models(modelnum) = sim_options.models(wh);
    
    estimates = time_varying_estimate('gaussian',regions, 12);
    
    % get columns of true and false positives, iterations x models
    [sim_results.tpr(i, modelnum) sim_results.fpr(i, modelnum)] = dcc_sim1_get_tpr_fpr(estimates, wh_true_timepoints);
    
    modelnum = modelnum + 1;
end

end % iterations

% -------------------------------------------------------------------------
% PLOT RESULTS
% -------------------------------------------------------------------------

create_figure('barplots', 1, 2);
colors = bucknerlab_colors;

barplot_columns(sim_results.tpr, 'colors', colors, 'nofig');
title('True positive rate');
set(gca, 'XTick', 1:length(sim_results.models), 'XTickLabel', sim_results.models);

subplot(1, 2, 2);
barplot_columns(sim_results.fpr, 'colors', colors, 'nofig');
title('False positive rate');
set(gca, 'XTick', 1:length(sim_results.models), 'XTickLabel', sim_results.models);
plot_horizontal_line(.01);





