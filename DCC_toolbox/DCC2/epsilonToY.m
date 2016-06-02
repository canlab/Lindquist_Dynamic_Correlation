function [ Y ] = epsilonToY( epsilon )
%Auxiliary function
%   Input: 
%       epsilon: T-by-K residual time series
%   Output:
%       Y: K*(K+1)/2-by-T matrix, vecterized outer product time series
%   Used by:
%       F.m
    


T = size(epsilon,1);
K = size(epsilon,2);

Y = zeros(K*(K+1)/2,T);


for t = 1:T
    Y(1:K,t) = (epsilon(t,:).^2)';
    count = K;
    for i = 1:K
        for j = (i+1):K
            count = count + 1;
            Y(count,t) = epsilon(t,i)*epsilon(t,j);
        end
    end
end



end

