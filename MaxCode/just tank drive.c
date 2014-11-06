#pragma config(Motor,  port1,           frontLeft,     tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           frontRight,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           backLeft,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           backRight,     tmotorVex393_MC29, openLoop)
task main()
{
	motor[frontRight] = 100;
	sleep(1000);
	motor[frontRight]=0;
	int threshold = 10; // threshold is the value that should be considered zero
	int AMOUNT = 1; // AMOUNT is the amount to devide the number by. higher AMOUNT will make the joystick less sensitive.
	while(true){
		/* RIGHT JOYSTICK */
		if(abs(vexRT[Ch2]) > threshold){
//			setRight(vexRT[Ch2]/AMOUNT);
		}
		else{
	//		setRight(0);
		}
		/* LEFT JOYSTICK */
		if(abs(vexRT[Ch3]) > threshold){
		//	setLeft(vexRT[Ch3]/AMOUNT);
		}
		else{
			//setLeft(0);
		}
	}
}
