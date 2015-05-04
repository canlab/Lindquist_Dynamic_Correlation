function [ Ct ] = tapered_sliding_window(dat,windowsize, sigma)
% function [ output ] = tapered_sliding_window(dat,windowsize, sigma)
%
% Tapered sliding window correlation of data
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

b= ones(windowsize,1);
x= -3*sigma:1:3*sigma;
w=normpdf(x,0,sigma);
w = conv(b,w);
w=w./sum(w);
len = length(w);
W = repmat(w,1,p);


Ct = NaN(p,p,T);



for i=(len):T
    
    D = dat((i-len+1):i,:).*W;
    
    Ct(:,:,i)=corr(D);
end

end



