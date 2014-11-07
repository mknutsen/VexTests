#ifndef MOTOR_FUNCTIONS_H
#define MOTOR_FUNCTIONS_H

#define MOTOR_MAX 127

/*
 * Mecanum wheel drive function
 * Author: Evan Rittenhouse <emanguy1@gmail.com>
 */

// Store motors here for easy access
int* frontRight;
int* frontLeft;
int* backRight;
int* backLeft;

static struct
{
	int i_forward;
	int i_rotate;
	int i_strafe;
} t_axisSetting;

// Gets references to bot motors
// In order, params are Front Right, Front Left,
// Bottom Right, Bottom Left
void initMotors(int* FR, int* FL, int* BR, int* BL)
{
	frontRight = FR;
	frontLeft = FL;
	backRight = BR;
	backLeft = BL;
}

// Ensure the value is not greater than the maximum motor value
void threshhold(int& value)
{
	if (abs(value) > MOTOR_MAX)
	{
		// Set to +/- MOTOR_MAX based on sign of value
		value = MOTOR_MAX * abs(value) / value;
	}
}

// Set the forward movement speed
void setForward(int speed)
{
	threshhold(speed);
	t_axisSetting.i_forward = speed;
}

// Set the strafe movement speed
void setStrafe(int speed)
{
	threshhold(speed);
	t_axisSetting.i_strafe = speed;
}

// Set the rotation speed
void setRotate(int speed)
{
	threshhold(speed);
	t_axisSetting.i_rotate = speed;
}

// Run this continuously to drive
void mecanumDrive()
{
	*frontRight = t_axisSetting.i_forward - t_axisSetting.i_rotate - t_axisSetting.i_strafe;
	*backRight = t_axisSetting.i_forward - t_axisSetting.i_rotate + t_axisSetting.i_strafe;
	*frontLeft = t_axisSetting.i_forward + t_axisSetting.i_rotate + t_axisSetting.i_strafe;
	*backLeft = t_axisSetting.i_forward + t_axisSetting.i_rotate - t_axisSetting.i_strafe;
}

#endif // MOTOR_FUNCTIONS_H
