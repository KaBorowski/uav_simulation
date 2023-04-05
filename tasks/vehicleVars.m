%% Vehicle Nonlinear Variables
% This file was derived from the work by Peter Corke and Fabian Reither.
% Copyright (C) 1993-2015, by Peter I. Corke
%
% This file is part of The Robotics Toolbox for MATLAB (RTB).
%
% http://www.petercorke.com

% Copyright 2013-2017 The MathWorks, Inc.

% 6DOF
Vehicle.SixDOF.initGreenwich = 0;
Vehicle.SixDOF.quatGain = 1;
% Position on Earth
Vehicle.PositionOnEarth.href = -init.posLLA(3);
Vehicle.PositionOnEarth.FlatEarthToLLA.xAxis = 0;
%% Physical properties
% Airframe
switch (model)
    case 'Mambo'
        Vehicle.Airframe.mass = 0.063;
        Vehicle.Airframe.inertia = diag([0.0000582857 0.0000716914 0.0001]);
    case 'UavMgr'
        Vehicle.Airframe.mass = 1.6;
        % Inertia calculated from 3D model. Parts of the model have wrong material
        % settings and the final mass is not proper. Calculater inertia values were
        % divided by model weight and multiplied by the real weight.
        Vehicle.Airframe.inertia = diag([0.03858 0.04146 0.05935]);
        % Estimated as rectangle 
        % Vehicle.Airframe.inertia = diag([0.0221866 0.0221866 0.04266]); 
    case 'RollingSpider'
        Vehicle.Airframe.mass = 0.068;
        Vehicle.Airframe.inertia = diag([0.0686e-3 0.092e-3 0.1366e-3]);
end
% Vehicle.Airframe.d = 0.0624; % Odleglość od środka do silnika
Vehicle.Airframe.d = 0.285; %OK

Vehicle.Airframe.xy = Vehicle.Airframe.d*sqrt(2)/2; % For diamond rotor set-up - odległość między środkiem a silnikiem wzdłuż x i y
% Vehicle.Airframe.h = -0.015876; % Wysokość od powierzchni ?
Vehicle.Airframe.h = -0.26; 

Vehicle.Airframe.Cdx = 0;
Vehicle.Airframe.Cdy = 0;
% Vehicle.Airframe.diameter = .01; % For drag calculation purposes
Vehicle.Airframe.diameter = .08; % For drag calculation purposes - od spodu do topu ramki, wyłączając nogi, sensory i baterie o ile jest niewielka (wartość zawyżona przez dużą baterię)

% Rotor
Vehicle.Rotor.blades = 2; %OK
% Vehicle.Rotor.radius = 0.033;
% Vehicle.Rotor.radius = 0.128;
Vehicle.Rotor.radius = 0.128;

% Vehicle.Rotor.chord = .008;
Vehicle.Rotor.chord = .027; % szereokość ostrza (zmierzyłem w najszerszym punkcie)

Vehicle.Rotor.flappingOffset = 0;
% Vehicle.Rotor.bladeMass = 3.75e-04;
Vehicle.Rotor.bladeMass = .009; % waga całego śmigła

Vehicle.Rotor.bladeInertia = Vehicle.Rotor.bladeMass*Vehicle.Rotor.radius^2/4;
Vehicle.Rotor.hubMass = 0;
Vehicle.Rotor.hubInertia = 0;
Vehicle.Rotor.inertia = Vehicle.Rotor.hubInertia + Vehicle.Rotor.bladeInertia;
% Vehicle.Rotor.Ct = .0107;
% Vehicle.Rotor.Ct = .019; % GPT na oko, złe dane
% Vehicle.Rotor.Ct = 0.063; % GPT po podaniu parametrów silnika
% Vehicle.Rotor.Ct = 0.042585; % GPT po podaniu średnicy śmigła
% Vehicle.Rotor.Ct = 0.0488; % GPT po podaniu średnicy śmigła, po przeliczeniu prędkości silnika ze śmigłem 170 w zmieniło się na 159 w
% Vehicle.Rotor.Ct = 0.2496; % według wzoru na w2ToThrustGain i znając rzeczywiście te wartość powinno być tyle
Vehicle.Rotor.Ct = 0.0063; % po zmianie jednostek na omega z rps
Vehicle.Rotor.Cq = Vehicle.Rotor.Ct*sqrt(Vehicle.Rotor.Ct/2);
Vehicle.Rotor.solidity = Vehicle.Rotor.chord*Vehicle.Rotor.blades/(pi*Vehicle.Rotor.radius);
Vehicle.Rotor.theta0 = 14.6*(pi/180);
Vehicle.Rotor.thetaTip = 6.8*(pi/180);
Vehicle.Rotor.theta1 = Vehicle.Rotor.thetaTip-Vehicle.Rotor.theta0;
Vehicle.Rotor.theta34 = Vehicle.Rotor.theta0+0.75*Vehicle.Rotor.theta1;
% Vehicle.Rotor.a = 5.5; % Lift slope
Vehicle.Rotor.a = 0.109; % Lift slope - podany przez chatgpt na podstawie airfoil NACA 4412

Vehicle.Rotor.area = pi*Vehicle.Rotor.radius^2;
Vehicle.Rotor.lock = rho*Vehicle.Rotor.a*Vehicle.Rotor.chord*Vehicle.Rotor.radius^4/...
    (Vehicle.Rotor.hubInertia+Vehicle.Rotor.bladeInertia);
Vehicle.Rotor.b = Vehicle.Rotor.Ct*rho*Vehicle.Rotor.area*Vehicle.Rotor.radius^2;
Vehicle.Rotor.k = Vehicle.Rotor.Cq*rho*Vehicle.Rotor.area*Vehicle.Rotor.radius^3;
Vehicle.Rotor.w2ToThrustGain = Vehicle.Rotor.Ct*rho*Vehicle.Rotor.area*Vehicle.Rotor.radius^2;
% Vehicle.Rotor.w2ToThrustGain = 2.4920e-04; % z pomiarów wynika to

% Motors
Vehicle.Motor.maxLimit = 1000;
Vehicle.Motor.minLimit = 30;
% Vehicle.Motor.commandToW2Gain = 13840.8; %motor command for Rolling Spider (0-500) to motorspeed^2
% Vehicle.Motor.commandToW2Gain = 500.8; %motor command for Rolling Spider (0-500) to motorspeed^2
% Vehicle.Motor.commandToW2Gain = 129.9604; %motor command for Rolling Spider (0-500) to motorspeed^2
% Vehicle.Motor.commandToW2Gain = 662.05; %motor command for Rolling Spider % (0-500) to motorspeed^2 - teoretycznie poprawne
% Vehicle.Motor.commandToW2Gain = 58; %motor command for Rolling Spider % (0-500) to motorspeed^2 - teoretycznie poprawne, poprawka na nową prędkość w (omega) plus wcześniej trzeba chyba było pomnożyć przez 10, bo PWM był w procentach a nie promilach
% Vehicle.Motor.commandToW2Gain = 58*5.1148;
Vehicle.Motor.commandToW2Gain = 2294.4;

Vehicle.Motor.thrustToMotorCommand = 1/(Vehicle.Rotor.w2ToThrustGain*Vehicle.Motor.commandToW2Gain);