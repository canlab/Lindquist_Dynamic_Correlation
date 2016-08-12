function [ index, Z ] = featureSelect( Y, eta, index0 )
%UNTITLED8 Summary of this function goes here
%   Detailed explanation goes here
% Input: 
%       Y - n-by-J
%       eta - false positive rate
% Output
%       selections: select nonzero index from J ROIs
n = size(Y,1);

J = size(Y,2);

x = fun1(Y);

m = mean(x);

s = std(x)/sqrt(size(x,1));

temp = m./s;

%index = (abs(temp)>norminv(1-eta/2,0,1));
index = (abs(temp)>tinv(1-eta/2,n-1));
index = index.*index0;

Z = zeros(J,J);
count = J;
for i = 1:J
    for j = i:J
        count = count + 1;
        Z(i,j) = index(count);
        Z(j,i) = Z(i,j);
    end
end

for i = 1:J
    Z(i,i)=1;
    index(j*(J+1-(j-1)/2)) = 1;
end


end

