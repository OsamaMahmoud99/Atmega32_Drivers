/*
 * Master.c
 *
 * Created: 11/7/2020 7:01:53 PM
 * Author : Osama Mahmoud
 */ 

#define  F_CPU      8000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Mem_Map32.h"

#include "DIO_interface.h"
#include "SPI_interface.h"



#define  send   DIO_ReadPin(PINB0)

volatile u8 x;
volatile u8 Data = 0;
int main(void)
{
	DIO_Init();
	SPI_voidInit();
	
	
	
	
	
	while(1)
	{
		
		if (send)
		{
			Data = 1;
			x= SPI_u8SendReceive(Data);
		}
		
		
	}
}

