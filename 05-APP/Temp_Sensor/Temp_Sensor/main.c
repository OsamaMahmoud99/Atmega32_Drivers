/*
 * Temp_Sensor.c
 *
 * Created: 11/7/2020 6:15:57 PM
 * Author : Osama Mahmoud
 */ 

#define  F_CPU      1000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Mem_Map32.h"

#include "DIO_interface.h"
#include "ADC_interface.h"
#include "LCD_interface.h"

int main(void)
{
	DIO_Init();
	LCD_Init();
	adc_init(divfact64 , EXTERNALAVCC);
    
    while (1) 
    {
		/* task 1 */
		/*int x= (adc_read_voltage(ADC4))*101;
		LCD_WriteNumber(x);
		_delay_ms(500);
		LCD_Clear();*/
		
	   /* task 2*/
	   int temp=(adc_read_voltage(ADC4))*101;
	   if (temp>50)
	   {
		  for(int i=0;i<=5;i++)
		  { SEG_voidDisplayNumber( 0 , i);
			  _delay_ms(1000);
		  }
	   }
	   else if (temp<50)
	   {
		    SEG_voidDisplayNumber( 0 , 0);
	   }
	   
	
	
    }
}

