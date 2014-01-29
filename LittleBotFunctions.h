float rotation = 627.2; //this number of ticks is one full revolution of a 393 high torque motor
float robotDiameter = 13.5;
float wheelDiameter = 5;

void liftJack(int speed){
	motor[liftJack1] = speed;
	motor[liftJack2] = speed;
}
void setRight(int speed){
	motor[frontRight] = speed;
	motor[backRight] = speed;
}
void setLeft(int speed){
	motor[frontLeft] = speed;
	motor[backLeft] = speed;
}
void setArm(int speed){
	motor[arm1] = speed;
	motor[arm2] = speed;
}
void broadTurnCCW(float deg, int speed){
	float distance = (pi*robotDiameter) / (wheelDiameter/2*(wheelDiameter/2)*pi);
	distance = distance * rotation;
	setRight(speed);
	while(getMotorEncoder(frontRight) < distance){
		wait1Msec(2);
	}
	setRight(0);
}
void zeroPointTurnCCW(float deg, int speed){
	float distance = (pi*robotDiameter) / (wheelDiameter/2*(wheelDiameter/2)*pi);
	distance = distance * rotation;
	setRight(speed);
	setLeft(speed*-1);
	while(getMotorEncoder(frontRight) < distance){
		wait1Msec(2);
	}
	setRight(0);
	setLeft(0);
}
void broadTurnCW(float deg, int speed){
	float distance = (pi*robotDiameter);
	distance = distance /(wheelDiameter/2*(wheelDiameter/2)*pi) * rotation;
	setLeft(speed);
	while(getMotorEncoder(frontLeft) < distance){
		wait1Msec(2);
	}
	setLeft(0);
}
void zeroPointTurnCW(float deg, int speed){
	float distance = (pi*robotDiameter) / (wheelDiameter/2*(wheelDiameter/2)*pi);
	distance = distance * rotation;
	setRight(speed*-1);
	setLeft(speed);
	while(getMotorEncoder(frontLeft) < distance){
		wait1Msec(2);
	}
	setRight(0);
	setLeft(0);
}
void move(float distance, int speed){
	distance = distance /(wheelDiameter/2*(wheelDiameter/2)*pi) * rotation;
	setLeft(speed);
	setRight(speed);
	while(getMotorEncoder(frontLeft) < distance){
		wait1Msec(2);
	}
	setLeft(0);
	setRight(0);
}
void armAttack(int speed){
	setArm(speed);
	wait10Msec(50);
	setArm(0);
}
