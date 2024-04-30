/*
 * Final Project Demo.c
 *
 * Created: 4/18/2024 1:42:22 PM
 * Author : apitts2
 */ 

#include <avr/io.h>
#include "C:\Users\apitts2\Desktop/UR1/MRE_lib/F_cpu_lib.h"
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>
#include "C:\Users\apitts2\Desktop\UR1\MRE_lib\Motor_PWM_lib.h"
#include "C:\Users\apitts2\Desktop/UR1/MRE_lib/LCD_lib.h"
#include "C:\Users\apitts2\Desktop\UR1\MRE_lib\Serial_lib2.h"

#define LEFT_MOTOR 0
#define RIGHT_MOTOR 1


int main(void) {
	char stringArray[20];
	uint8_t serialPosition;
	uint8_t state = 0; // Initialize state
	HBridgeInit();
	LCD_init();
	LCDGoToPosition(1, 1);
	sprintf(stringArray, "Message");
	LCDSendString(stringArray);
	_delay_ms(1000);

	USART_vInit();
	sei();
	LCDClearScreen();

	while (1) {
		serialPosition = USART_vReceiveByte();
		LCDClearScreen();
		LCDGoToPosition(1, 1);
		sprintf(stringArray, "%c", serialPosition);
		LCDSendString(stringArray);
		LCDGoToPosition(1, 2);
		sprintf(stringArray, "%d", state); // Print state as integer
		LCDSendString(stringArray);

		switch (state) {
			case 1: // sharp left
			HBridgeCommand(LEFT_MOTOR, 20, 0); // left
			HBridgeCommand(RIGHT_MOTOR, 120, 0); // right
			if (serialPosition == '1')
			{
				state = 1;
			}else if (serialPosition == '2')
			{
				state = 2;
			}else if (serialPosition == '3')
			{
				state = 3;
			}else if (serialPosition == '4')
			{
				state = 4;
			}else if (serialPosition == '5')
			{
				state = 5;
			}
			if (serialPosition == '6')
			{
				state = 6;
			}
			break;

			case 2: // soft left
			HBridgeCommand(LEFT_MOTOR, 20, 0); // HBridgeCommand(motor, spd, direction)
			HBridgeCommand(RIGHT_MOTOR, 100, 0); // HBridgeCommand(motor, spd, direction)
			if (serialPosition == '1')
			{
				state = 1;
			}else if (serialPosition == '2')
			{
				state = 2;
			}else if (serialPosition == '3')
			{
				state = 3;
			}else if (serialPosition == '4')
			{
				state = 4;
			}else if (serialPosition == '5')
			{
				state = 5;
			}
			if (serialPosition == '6')
			{
				state = 6;
			}
			break;

			case 3: // forward
			HBridgeCommand(LEFT_MOTOR, 60, 0); // HBridgeCommand(motor, spd, direction)
			HBridgeCommand(RIGHT_MOTOR, 69, 0); // HBridgeCommand(motor, spd, direction)
			if (serialPosition == '1')
			{
				state = 1;
			}else if (serialPosition == '2')
			{
				state = 2;
			}else if (serialPosition == '3')
			{
				state = 3;
			}else if (serialPosition == '4')
			{
				state = 4;
			}else if (serialPosition == '5')
			{
				state = 5;
			}
			if (serialPosition == '6')
			{
				state = 6;
			}
			break;

			case 4: // soft right
			HBridgeCommand(LEFT_MOTOR, 120, 0); // HBridgeCommand(motor, spd, direction)
			HBridgeCommand(RIGHT_MOTOR, 20, 0); // HBridgeCommand(motor, spd, direction)
			if (serialPosition == '1')
			{
				state = 1;
			}else if (serialPosition == '2')
			{
				state = 2;
			}else if (serialPosition == '3')
			{
				state = 3;
			}else if (serialPosition == '4')
			{
				state = 4;
			}else if (serialPosition == '5')
			{
				state = 5;
			}
			if (serialPosition == '6')
			{
				state = 6;
			}
			break;

			case 5: // sharp right
			HBridgeCommand(LEFT_MOTOR, 110, 0); // HBridgeCommand(motor, spd, direction)
			HBridgeCommand(RIGHT_MOTOR, 20, 0); // HBridgeCommand(motor, spd, direction)
			if (serialPosition == '1')
			{
				state = 1;
			}else if (serialPosition == '2')
			{
				state = 2;
			}else if (serialPosition == '3')
			{
				state = 3;
			}else if (serialPosition == '4')
			{
				state = 4;
			}else if (serialPosition == '5')
			{
				state = 5;
			}
			
			if (serialPosition == '6')
			{
				state = 6;
			}
			break;
			
			case 6:
			_delay_ms(1450);
			HBridgeCommand(LEFT_MOTOR, 0, 0); // HBridgeCommand(motor, spd, direction)
			HBridgeCommand(RIGHT_MOTOR, 0, 0); // HBridgeCommand(motor, spd, direction)
			state = 6;
		}
		
		

		// Update state based on received character
		if (serialPosition >= '1' && serialPosition <= '5') {
			state = serialPosition - '0'; // Convert char to int
		}
	}
}
