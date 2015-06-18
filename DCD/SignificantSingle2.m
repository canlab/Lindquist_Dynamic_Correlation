function [ SignificantIndicator] = SignificantSingle2( Y, candidateTime, alpha)
%	Input: 
%       Y: data time-by-ROI
%       candidateTime: candidate split time point
%       alpha: significance level
%   Output:
%       SignificantIndicator: 0 - NO  1 - YES

SignificantIndicator = 0;

if isempty(candidateTime)
    return
else
    Y1 = Y(1:candidateTime,:);
    Y2 = Y(candidateTime+1:end,:);
    
    x1 = fun1(Y1);
    x2 = fun1(Y2);

    m1 = mean(x1);
    m2 = mean(x2);

    n1 = size(x1,1);
    n2 = size(x2,1);
    
    J = size(x1,2);
    
    temp1 = x1-ones(n1,1)*m1;
    temp2 = sum(temp1.*temp1)/(n1-1);

    temp3 = x2-ones(n2,1)*m2;
    temp4 = sum(temp3.*temp3)/(n2-1);

    stat = (m1 - m2)./sqrt(temp2/n1 + temp4/n2);
    %q = norminv((1-alpha/J),0,1);
    q = tinv(1-alpha/2/J,n1+n2-2);
    
    SignificantIndicator = (max(abs(stat))>q);
   
end


end