function [tpr, fpr] = dcc_sim1_get_tpr_fpr(r, wh_true_timepoints)
% r is a timeseries of correlation values.
%
% Get results (naive TPR, FPR) from sim1.  Options (t) hard-coded to match
% dcc_sim_generate_data1.m


pcrit = .001;
t = 500;

% Note: may later want to
% eliminate first and last 20 time points so sliding window is not unfairly
% advantaged (it returns NaNs - but tor's version does not...deal with later)


truevec = false(t, 1); 
truevec(wh_true_timepoints) = true;

% approx p < pcrit not correcting for autocorrelation, correcting for mult
% comps, two-tailed

zcrit = norminv(1 - (pcrit / (2*t) ));

z = fisherz(r);
se = 1 ./ sqrt(t - 3);

sig = z - zcrit * se > 0 | z + zcrit * se < 0;


tpr = sum(sig(truevec)) ./ sum(truevec);
fpr = sum(sig(~truevec)) ./ sum(~truevec);

end % function

