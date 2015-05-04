function [C] = DCC(Dat)
% function [Ct, Ht] = DCC(dat)

[T,p] = size(Dat);
C = ones(p,p,T);

for j=1:(p-1),    
    for k=(j+1):p,
  
        [ Ctmat ] = DCCsimple([Dat(:,j) Dat(:,k)]); 
        C(j,k,:) = Ctmat(1,2,:); 
        C(k,j,:) = Ctmat(1,2,:); 

    end
end


