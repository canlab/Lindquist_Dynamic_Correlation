function [ Ct ] = sliding_window(dat,windowsize)
% function [ output ] = sliding_window(,windowsize)
%
% Sliding window correlation of data
% 
% INPUTS:
%
%      dat          Zero mean T by p matrix
% 
% OUTPUTS:
%
%      Ct           p by p by T array of conditional correlations
%
%
% File created by Martin Lindquist on 07/22/14
% Last update: 07/22/14

[T,p] = size(dat);

Ct = NaN(p,p,T);

for i=(windowsize):T
    Ct(:,:,i)=corr(dat((i-windowsize+1):i,:));
end

end


