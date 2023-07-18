Vehicle.Motor.gain = [1.3 1.0 1.1 1.04]; 
Vehicle.Motor.offset = [30 0 15 8]; 
Sensors.IMU.noiseWeights = [500.0 500.0 500.0 50.0 50.0 50.0]; % Mgr UAV update
Sensors.IMU.noisePower = Sensors.IMU.noiseWeights.*[0.0165195073635001 0.0152648883285633 0.0215786550496705 ...
    0.000652733165165932 0.000721701528439517 0.000690781425279554].^2;