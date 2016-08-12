function [ timepointSSS_new ] = SplitSearch2( Y ,BIC, Delta, alpha)
  
[ timepoint, minBIC_1, minBIC_2] = Split2( Y, BIC, Delta, alpha);

if timepoint == -1
    timepointSSS_new = [];
    return
else
    t1 = SplitSearch2( Y(1:timepoint,:), minBIC_1, Delta, alpha);
    t2 = SplitSearch2( Y((timepoint+1):end,:), minBIC_2, Delta, alpha);
    t2 = t2 + timepoint;
    timepointSSS_new = [t1 timepoint t2];
end


end
