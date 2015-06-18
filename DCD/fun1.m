function [ output ] = fun1( Y )
%UNTITLED5 Summary of this function goes here
%   Detailed explanation goes here

n = size(Y,1);
J = size(Y,2);

m = J + J*(J+1)/2;
output = zeros(n,m);

output(:,1:J) = Y;

count = J;
for i = 1:J
    for j = i:J
        count = count + 1;
        output(:,count) = Y(:,i).*Y(:,j);
    end
end


end

