function [C] = DCC(Dat, varargin)
% function C = DCC(dat, ['whiten'])


% -------------------------------------------------------------------------
% DEFAULTS AND INPUTS
% -------------------------------------------------------------------------

% initalize optional variables to default values here.

dowhiten = 0;

% optional inputs with default values
for i = 1:length(varargin)
    if ischar(varargin{i})
        switch varargin{i}

            case {'white', 'whiten'}, dowhiten = 1;
                
            otherwise, warning(['Unknown input string option:' varargin{i}]);
        end
    end
end


% -------------------------------------------------------------------------
% MAIN FUNCTION
% -------------------------------------------------------------------------

[T,p] = size(Dat);
C = ones(p,p,T);

if dowhiten
    
    Mdl = arima(1,0,1);
    
    opts = optimoptions('fmincon');
    opts.Algorithm = 'sqp';
    deltaX = 10^(-5);
    opts.TolX = deltaX;
    opts.TolCon = 10^(-6);
    opts.MaxFunEvals = 1000;
    
    for k=1:size(Dat,2),
        
        EstMdl = estimate(Mdl,Dat(:,k) ,'Display', 'off', 'options', opts);
        
        [res, v] = infer(EstMdl,Dat(:,k));
        Dat(:,k) = res./sqrt(v);
        
    end
    
end


for j=1:(p-1)  
    for k=(j+1):p
  
        [ Ctmat ] = DCCsimple([Dat(:,j) Dat(:,k)]); 
        C(j,k,:) = Ctmat(1,2,:); 
        C(k,j,:) = Ctmat(1,2,:); 

    end
end


