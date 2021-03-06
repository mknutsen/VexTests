#pragma config(Sensor, in1,    lineFollower,   sensorLineFollower)
#pragma config(Sensor, in2,    redBlueSwitch,  sensorPotentiometer)
#pragma config(Sensor, dgtl1,  bump,           sensorTouch)
#pragma config(Sensor, dgtl2,  ,               sensorQuadEncoder)
#pragma config(Motor,  port1,           backLeft,      tmotorVex393_HBridge, openLoop, reversed, encoderPort, None)
#pragma config(Motor,  port2,           right,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           frontLeft,     tmotorVex393_MC29, openLoop, encoderPort, dgtl2)
#pragma config(Motor,  port4,           hook,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           arm1,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           arm2,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           extender,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           wench,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           liftJack1,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          liftJack2,     tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(60)
#pragma userControlDuration(60)
#include "LittleBotFunctionsEncoder.h"
#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////
int SWITCH = 2000;
bool red = false;
void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false

  bStopTasksBetweenModes = true;
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
	if(sensorValue(redBlueSwitch) < SWITCH){
		red = true;
	}
	else{
		red = false;
	}
	if(red){
		motor[hook] = -127;
		wait10Msec(60);
		motor[hook] = 64;
		wait10Msec(200);
		motor[hook] = 0;
		turnCW(159, 127);
		wait10Msec(1);
		move(1.3,127);
		wait10Msec(1);
		turnCCW(161, 127);
		wait10Msec(1);
		move(1.1,127);
		wait10Msec(1);
		move(.7,-127);
		wait10Msec(1);
		turnCW(125,127);
		wait10Msec(1);
		move(1.1,127);
		wait10Msec(1);
		turnCCW(125,127);
		wait10Msec(1);
		move(1.4,127);
		wait10Msec(1);
		move(.7,-127);
		wait10Msec(1);
		turnCCW(45,127);
		wait10Msec(1);
		move(1.5,127);
		wait10Msec(1);
	}
	else{
		motor[hook] = -127;
		wait10Msec(60);
		motor[hook] = 64;
		wait10Msec(200);
		motor[hook] = 0;
		turnCCW(159, 127);
		wait10Msec(1);
		move(1.3,127);
		wait10Msec(1);
		turnCW(161, 127);
		wait10Msec(1);
		move(1.1,127);
		wait10Msec(1);
		move(.7,-127);
		wait10Msec(1);
		turnCCW(125,127);
		wait10Msec(1);
		move(1.1,127);
		wait10Msec(1);
		turnCW(125,127);
		wait10Msec(1);
		move(1.4,127);
		wait10Msec(1);
		move(.7,-127);
		wait10Msec(1);
		turnCW(45,127);
		wait10Msec(1);
		move(1.5,127);
		wait10Msec(1);
	}
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
	int AMOUNT = 1;
	while(true){
		if(abs(vexRT[Ch2]) > threshold){
			setRight(vexRT[Ch2]/AMOUNT);
		}
		else{
			setRight(0);
		}
		if(abs(vexRT[Ch3]) > threshold){
			setLeft(vexRT[Ch3]/AMOUNT);
		}
		else{
			setLeft(0);
		}
		if(vexRT[Btn7L] == 1){
			setArm(127);
			while(vexRT[Btn7L] == 1);
			setArm(0);
		}
		else if(vexRT[Btn7D] == 1){
			setArm(-127);
			while(vexRT[Btn7D] == 1);
			setArm(0);
		}
		if(vexRT[Btn7U] == 1){
			setArm(127);
			motor[wench] = 127;
			while(vexRT[Btn7U] == 1);
			setArm(0);
			motor[wench] = 0;
		}
		else if(vexRT[Btn7R] == 1){
			motor[wench] = 127;
			while(vexRT[Btn7R] == 1);
			motor[wench] = 0;
		}
		if(vexRT[Btn8D] == 1){
			motor[extender] = 127;
			while(vexRT[Btn8D] == 1);
			motor[extender] = 0;
		}
		else if(vexRT[Btn8R] == 1){
			motor[extender] = -127;
			while(vexRT[Btn8R]==1);
			motor[extender] = 0;
		}
		if(vexRT[Btn6D] == 1){
			motor[hook] = 64;
			while(vexRT[Btn6D]==1);
			motor[hook] = 0;
		}
		else if(vexRT[Btn6U] == 1){
			motor[hook] = -64;
			while(vexRT[Btn6U]==1);
			motor[hook] = 0;
		}
		if(vexRT[Btn5D] == 1){
			liftJack(127);
			while(vexRT[Btn5D]==1);
			liftJack(0);
		}
		else if(vexRT[Btn5U] == 1){
			liftJack(-127);
			while(vexRT[Btn5U]==1);
			liftJack(0);
		}
	}
}
