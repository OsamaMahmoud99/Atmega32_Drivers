/*
 * LEDMRX.c
 *
 * Created: 11/2/2020 10:55:27 AM
 * Author :Osama Mahmoud
 */ 

#define  F_CPU         1000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Mem_Map32.h"

#include "DIO_interface.h"
#include "LEDMRX_interface.h"

//u8 arr[8]={0, 0, 38, 42, 50, 0, 0,0};
	
u8 name[] = {0,0,24,36,36,24,0,0,  0,0,50,42,38,0,0,0,  0,124,18,18,18,124,0,0, 0,0,28,2,30,2,28,0, 0,124,18,18,18,124,0,0};

int main(void)
{
    LEDMRX_voidInit();
	

	
    while (1) 
    {
		
			LEDMRX_voidAnimation(name);
			
	
    }
}

