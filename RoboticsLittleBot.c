#pragma config(Sensor, in1,    redBlueSwitch,  sensorPotentiometer)
#pragma config(Sensor, dgtl1,  bump,           sensorTouch)
#pragma config(Motor,  port1,           frontRight,    tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           backRight,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           frontLeft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           backLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           arm1,          tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           arm2,          tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           extender,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           hook,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           liftJack1,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          liftJack2,     tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(60)
#pragma userControlDuration(60)
#include "LittleBotFunctions.h"
#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;
  slaveMotor(frontLeft,backLeft);
  slaveMotor(frontRight,backRight);
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{

}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol(){
	int threshold = 10;
	int extenderDistance = 100;
	int hookDistance = 100;
	while(true){
	//	if(abs(vexRT[Ch1] > threshold){
	//	}
	//	else{
	//	}
		if(abs(vexRT[Ch2]) > threshold){
			motor[frontLeft] = vexRT[Ch2];
			motor[backLeft] = vexRT[Ch2];
		}
		else{
			motor[frontLeft] = 0;
			motor[backLeft]=0;
		}
		if(abs(vexRT[Ch3]) > threshold){
			motor[frontRight] = vexRT[Ch3];
			motor[backRight] = vexRT[Ch3];
		}
		else{
			motor[frontRight]=0;
			motor[backRight] = 0;
		}
		if(abs(vexRT[Ch4]) > threshold){
			motor[arm1] = vexRT[Ch4];
			motor[arm2] = vexRT[Ch4];
		}
		else{
			motor[arm1] = 0;
			motor[arm2] = 0;
		}
		if(vexRT[Btn8L] == 1){
			motor[extender] = 127;
			wait10Msec(extenderDistance);
			motor[extender] = 0;
		}
		else if(vexRT[Btn8R] == 1){
			motor[extender] = -127;
			wait10Msec(extenderDistance);
			motor[extender] = 0;
		}
		if(vexRT[Btn6D] == 1){
			motor[hook] = 127;
			wait10Msec(hookDistance);
			motor[hook] = 0;
		}
		else if(vexRT[Btn6U] == 1){
			motor[hook] = -127;
			wait10Msec(hookDistance);
			motor[hook] = 0;
		}
	}
}
