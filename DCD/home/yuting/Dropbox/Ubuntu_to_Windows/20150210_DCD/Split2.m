function [ timepoint, minBIC_1, minBIC_2] = Split2( Y, BIC, Delta, alpha )
% For recursively find one split point for input series
% INPUT:
%   Y: timelength-by-ROIs matrix
%   current optimized penalty parameter lambda
%   current minimized BIC
%   Delta: minimum distance between splits
%   lambda_list: a list of candidate lambdas
% OUTPUT
%   timepoint: candidate time point for splitting Y 
%                into [1,timepoint] and [timepoint + 1, end]
%              If timepoint = -1, means no further splitting available


T = size(Y,1);  % time length
%J = size(Y,2);  % number of ROIs

% auxiliary variables
largest_decrease = 0;
minBIC_t = 0;
minBIC_1 = 0;
minBIC_2 = 0;

if T < 2*Delta
    timepoint = -1;
else
    for t = Delta : T-Delta
        Y1 = Y(1:t,:);
        Y2 = Y(t+1:T,:);
        n1 = size(Y1,1);
        n2 = size(Y2,1);
        
        S1 = cov(Y1);
        S2 = cov(Y2);
             
        b1 = n1*log(det(S1));
        b2 = n2*log(det(S2));
     
        % modified
        temp = BIC - (b1+b2);
        if temp > largest_decrease
            largest_decrease = temp;
            minBIC_t = t;
            minBIC_1 = b1;
            minBIC_2 = b2;
        end
        
    end
    
    
    if minBIC_t == 0
        timepoint = -1;
    else
        timepoint = minBIC_t;
        SignificantIndicator = SignificantSingle2( Y, timepoint, alpha);
        if SignificantIndicator==0
            timepoint = -1;
            return
        end
        
    end
end


end
