% % Script to use Martin Lindquist's dynamic connectivity toolbox to create
% % correlation matrices at each point in time instead of across an entire
% % block or chunk of a block
% % See /home/despo/jrcohen/matlab/DC_toolbox/Example.m
% % Made by JRC 9-1-14
% 
% clear all;
% 
% % Define paths/variables
% basedir = '/home/despo/kki_adhd/';
% scriptdir = [basedir '/scripts/'];
% analdir = [basedir '/analyses/03_rest_corr_4-22-13_KKIproc_restonly/'];
% corrdir = 'corr_';
% atlases={'dosenbach_all'}; % 'aal',dosenbach_all'
% corrtypedir = '/roi2roi/';
% corrmatdir = '/DC_TXTfiles/';
% timesdir = '/timeseries/';
% windowsize = 20; % If do sliding window correlations
% 
% tstart=tic; % So can timestamp how long everything takes, with toc(tstart)
% 
% for a=1:length(atlases),
%     atlas=atlases{a};
%     fulldcdir=[analdir corrdir atlas corrtypedir corrmatdir]; % Output dir for dynamic connectivity correlation matrices
%     if ~exist(fulldcdir),
%         system(['mkdir ' fulldcdir]);
%     end;
%     fulltimesdir=[analdir corrdir atlas corrtypedir timesdir];
%     timesfiles=dir([fulltimesdir,'*mat']);
    for t=1:length(files),
    %for t=203:length(timesfiles), % Running after sub 125/195/202, since those subs failed
    %for t=1:4, % Shorr for trouble-shooting
%         tstart2=tic; % So can timestamp how long everything takes, with toc(tstart)    
%         tname=timesfiles(t).name;
%         tmp=strsplit(tname,'_');
%         sub=tmp{1};
%         fprintf('\n=====\n%s\n=====\n',sub);
%         pause(1); % Insert a pause so I can see the time and what sub we're on
%         tseries=load([fulltimesdir,tname]);
% 
%         load(files(t,:))
%         data=tseries.data;
        
        data = load(files{t});
        % Define data dimensions
        p = size(data,2); % Number of nodes
        T = size(data,1); % Numer of time points
        % Demean and standardize data (separately for each node)
        % Trying different options to get the most reasonable output
        %%%%% STANDARDIZING IS BEST (the output corrs make the most sense)
        data_demeaned=zeros(size(data));
        data_stand=zeros(size(data));
        for roi=1:size(data,2),
            data_demeaned(:,roi)=data(:,roi)-mean(data(:,roi));
            data_stand(:,roi)=zscore(data(:,roi));
        end;
        % Check for ROIs with all 0s (meaning they don't exist), and 
        % remove them temporarily for DCC calc
        empty=[];
        for roi=1:size(data_stand,2),
            if sum(data_stand(:,roi))==0, 
                %fprintf('%d\n',roi); % To make sure indexing correctly
                empty=cat(2,empty,roi); % Keep a list of empty ROIs
            end;
        end;
        data_stand(:,empty)=[];
        % Fit DCC
        [corrmat, covmat] = DCC(data_stand); % corrmat = dynamic correlation matrix; covmat = dynamic covariance matrix
        % Fit sliding window correlations--NOT DOING THIS FOR NOW!!
        %[sw_corrmat] = sliding_window(data_stand,windowsize); % sw_corrmat = sliding window correlation matrix 
        % Save output correlation matrix--each timepoint separately
%         for n=1:size(corrmat,3), 
%             % Save each timepoint separately
%             corrmatname=sprintf('%s%s_Sess1_Block%03d.txt',fulldcdir,sub,n);
%             %fprintf('%s\n',corrmatname); % To make sure I'm naming correctly
%             corrmat_1vol=corrmat(:,:,n);
%             % Re-insert any ROIs that were temporarily removed for DCC calc
%             % (with values of NaN)
%             % First fill in empty rows
%             corrmat_fullrows_1vol=NaN(p,size(corrmat_1vol,2));
%             count=1;
%             for r=1:p,
%                 if isempty(find(empty==r)),
%                     corrmat_fullrows_1vol(r,:)=corrmat_1vol(count,:);
%                     count=count+1;
%                 end;
%             end;
%             % Second fill in empty columns
%             corrmat_full_1vol=NaN(p,p);
%             count=1;
%             for c=1:p,
%                 if isempty(find(empty==c)),
%                     corrmat_full_1vol(:,c)=corrmat_fullrows_1vol(:,count);
%                     count=count+1;
%                 end;
%             end;
% %             save(corrmatname,'corrmat_full_1vol','-ascii');
%         end;
%        fprintf('    Time elapsed for %s: %.2f minutes for sub, %.2f minutes total.\n',t,toc(tstart2)/60,toc(tstart)/60);
%        pause(1); % Insert a pause so I can see the time and what sub we're on
t
    end; % End timesfile loop
% end; % End atlas loop