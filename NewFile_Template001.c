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
#include "LittleBotFunctionsEncoder.h";
int n=0;
task main()
{
	while(true){
		n = sensorValue(redBlueSwitch);
		//while(VexRT[Btn8D] == 0);
		if(sensorValue(redBlueSwitch) <= 249){
			//move(1, 127);
		}
		else{
			//move(1,-127);
		}
	}
}
