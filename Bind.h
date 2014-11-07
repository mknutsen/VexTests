#ifndef BIND_H
#define BIND_H

#define PRESSED 1

/*
 * Input binding functions
 *
 * Used for binding single functions to the joystick
 * axes and buttons of the VEX controller using
 * dynamic memory allocation and queue structures
 *
 * Author: Evan Rittenhouse
 */

// Speed function pointer typedef
typedef void (*SpeedFunction_p)(int);

// Queue node typedef
typedef struct bindNode_t
{
	int* p_source; // Sensor/button/axis to read
	int i_value; // Value to pass
	SpeedFunction_p func; // Function to call
	bindNode_t* t_next = NULL; // Next node in the queue
};

// Define binding queues
bindNode_t t_buttonQueue; // i_value is passed for button bindings
bindNode_t t_threshQueue; // (*p_axis) is passed for joy axis bindings

// Get the last binding in the queue
bindNode_t* getLast(bindNode_t* head)
{
	bindNode_t* currNode = head;

	while (currNode->t_next != NULL)
	{
		currNode = currNode->t_next;
	}

	return currNode;
}

// Bind a button to a function
void buttonBind(int* button, int value, SpeedFunction_p callMe)
{
	// Create a new node
	bindNode_t* binding = malloc(sizeof(bindNode_t));
	binding->p_source = button;
	binding->i_value = value;
	binding->func = callMe;
	binding->t_next = NULL;

	// Add it to the end of the binding queue
	getLast(t_buttonQueue)->t_next = binding;
}

// Bind a joystick axis to a function and pass value
// only when *joyAxis > thresh
void threshBind(int* joyAxis, int thresh, SpeedFuction_p callMe)
{
	// Create a new node
	bindNode_t* binding = malloc(sizeof(bindNode_t));
	binding->p_source = joyAxis;
	binding->i_value = thresh;
	binding->func = callMe;
	binding->t_next = NULL;

	// Add it to the end of the binding queue
	getLast(t_threshQueue)->t_next = binding;
}

void runFunctions()
{
	bindNode_t* currThresh = t_threshQueue.t_next;
	bindNode_t* currButton = t_buttonQueue.t_next;

	int sensorValue;

	// Step through axis bindings
	while (currThresh->t_next != NULL)
	{
		sensorValue = *(currThresh->p_source);

		// If the sensor value is over the threshhold
		if (abs(sensorValue) >  i_value)
		{
			// Call the function, passing the value of the joy axis
			currThresh->func(sensorValue);
		}
		else
		{
			// Otherwise say it's zero
			currThresh->func(0);
		}
	}

	// Step through button bindings
	while (currButton->t_next != NULL)
	{
		// Get the press state of the button
		sensorValue = *(currButton->p_source);

		// If the button is pressed
		if (sensorValue == PRESSED)
		{
			// Call the function, passing the speed specified
			currButton->func( currButton->i_value );
		}
		else
		{
			// Otherwise set the speed to zero
			currButton->func(0);
		}
	}
}

// Included just in case, frees dynamic memory from queues
void clearBindingMemory()
{
	buttonNode_t* removeMe;

	while (t_buttonQueue->t_next != NULL)
	{
		removeMe = t_buttonQueue->t_next;
		t_buttonQueue-> t_next = removeMe->t_next;
		free(removeMe);
	}

	t_buttonQueue->t_next = NULL;

	while (t_threshQueue->t_next != NULL)
	{
		removeMe = t_threshQueue->t_next;
		t_threshQueue->t_next = removeMe->t_next;
		free(removeMe);
	}

	t_threshQueue->t_next = NULL;
}

#endif // BIND_H
