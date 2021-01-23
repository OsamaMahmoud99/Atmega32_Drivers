/*
 * Slave.c
 *
 * Created: 11/7/2020 7:09:36 PM
 * Author : Osama Mahmoud
 */ 

#define  F_CPU  8000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Mem_Map32.h"

#include "DIO_interface.h"
#include "SPI_interface.h"


volatile u8  Data;
volatile u8  x;
int main(void)
{
	DIO_Init();
	SPI_voidInit();
	
	while(1)
	{
		x = SPI_u8SendReceive(Data);
		if (x == 1)
		{
			DIO_TogglePin(PINA0);
		}
		
	}
}