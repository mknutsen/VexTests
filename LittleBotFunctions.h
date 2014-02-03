float robotDiameter = 13.5;
float wheelDiameter = 5;
float oneTile = .6;
float threeSixty = 3.1;
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
void turnCCW(float deg, float speed){
	int time = threeSixty*(deg/360)*1000;
	//time = time + time*(1-(speed / 127));
	setLeft(-1*speed);
	setRight(speed);
	wait1Msec(time);
	setLeft(0);
	setRight(0);
}
void turnCW(float deg, float speed){
	turnCCW(deg, speed*-1);
}
void move(float distance, float speed){
		int time = (distance) * oneTile * 1000;
		//time = time + time*(1-(abs(speed / 127)));
		setLeft(speed);
		setRight(speed);
		wait1Msec(time);
		setLeft(0);
		setRight(0);
}
