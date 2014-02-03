float rotation = 300; //this number of ticks is one full revolution of a 393 high torque motor
float robotDiameter = 14;
float wheelDiameter = 2.5;

void liftJack(int speed){
	motor[liftJack1] = speed;
	motor[liftJack2] = speed;
}
void setRight(int speed){
	motor[right] = speed;
}
void setLeft(int speed){
	motor[frontLeft] = speed;
	motor[backLeft] = speed;
}
void setArm(int speed){
	motor[arm1] = speed;
	motor[arm2] = speed;
}
void armAttack(int speed){
	setArm(speed);
	wait10Msec(50);
	setArm(0);
}
void turnCCW(float deg, int speed){
	resetMotorEncoder(frontLeft);
	float distance = deg/360*(pi*robotDiameter);
	distance = distance /(2*wheelDiameter*pi) * rotation;
	setRight(speed);
	setLeft(speed*-1);
	while(abs(nMotorEncoder[frontLeft]) <  distance){
		wait1Msec(2);
	}
	setRight(0);
	setLeft(0);
}

void turnCW(float deg, int speed){
	turnCCW(deg,-1*speed);
}
void move(float distance, int speed){
	resetMotorEncoder(frontLeft);
	distance = distance*24 /(2*wheelDiameter*pi) * rotation;
	setLeft(speed);
	setRight(speed);
	while(abs(nMotorEncoder[frontLeft]) < distance);
	setLeft(-10);
	setRight(-10);
	wait10Msec(2);
	setLeft(0);
	setRight(0);
}
