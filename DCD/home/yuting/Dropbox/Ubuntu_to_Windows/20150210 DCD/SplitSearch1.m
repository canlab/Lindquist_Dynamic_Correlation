function [ timepointSSS_new ] = SplitSearch1( Y, BIC, Delta, alpha, eta, mask0)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

%%% NEW! mask imposed
[mask,Z] = featureSelect(Y,eta,mask0);
mask = logical(mask);
if sum(mask~=mask0)>0
    %BIC = size(Y,1)* log(det(cov(Y).*Z));
    S = cov(Y);
    Snew = cov(Y).*Z;
    BIC = size(Y,1)* (log(det(Snew)) + trace(Snew\S) );
end
%%%

[ timepoint, minBIC_1, minBIC_2] = Split1( Y, BIC, Delta, alpha, mask, Z );

if timepoint == -1
    timepointSSS_new = [];
    return
else
    t1 = SplitSearch1( Y(1:timepoint,:), minBIC_1, Delta, alpha, eta, mask);
    t2 = SplitSearch1( Y((timepoint+1):end,:), minBIC_2, Delta, alpha, eta, mask);
    t2 = t2 + timepoint;
    timepointSSS_new = [t1 timepoint t2];
end

end