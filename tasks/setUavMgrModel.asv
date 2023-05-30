function setUavMgrModel
% SETUAVMGRMODEL Helper function to set the quadcopter properties to the
% UavMgr model.

% Obtain current project
p = slproject.getCurrentProject;
% Obtain project root
projectRoot = p.RootFolder;
% Set UavMgr model
model = 'UavMgr';
% Save variabe to .MAT fie for persistence
save(fullfile(projectRoot,'mainModels','modelParrot.mat'),'model');
% Update title
mainModel = 'asbQuadcopter';
load_system(mainModel);
ah = find_system(mainModel, ...
                FindAll='on', ...
                MatchFilter=@Simulink.match.allVariants, ...
                Type='annotation', ...
                Tag='ModelTitle');
ao = get_param(ah,'object');
modelTitle = 'Quadcopter Flight Simulation Model - UavMgr';
if ~strcmp(modelTitle,ao.Text)
    ao.Text = modelTitle;
    save_system(mainModel);
end
% Assign variables according to UavMgr
% Total mass of the uav
evalin('base','Vehicle.Airframe.mass = 1.6;');
% Inertia calculated from 3D model. Parts of the model have wrong material
% settings and the final mass is not proper. Calculater inertia values were
% divided by model weight and multiplied by the real weight.
evalin('base','Vehicle.Airframe.inertia = diag([0.03858 0.04146 0.05935]);');
% Not used
evalin('base','Estimator.pos.opticalFlowToVelocityGain = 1;');
% Not used
evalin('base','Sensors.velocityToOpticalFlowGain = 1;');
% Gain during starting procedure - not used in FW
evalin('base','Controller.takeoffGain = 0.1;');
assignin('base','model',model);
