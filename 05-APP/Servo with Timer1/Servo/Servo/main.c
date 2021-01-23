/*
 * Servo.c
 *
 * Created: 11/11/2020 6:43:18 PM
 * Author : asss5
 */ 

#define  F_CPU 8000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Mem_Map32.h"

#include "DIO_interface.h"
#include "Timers_interface.h"

#include "Servo_interface.h"


int main(void)
{
    DIO_Init();
	Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8,OCRA_NON_INVERTING,OCRB_NON_INVERTING);
	ICR1=19999;
	
    while (1) 
    {
		SERVO_SetAngle(90);
    }
}

