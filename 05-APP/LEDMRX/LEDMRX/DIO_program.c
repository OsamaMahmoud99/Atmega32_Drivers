#include "DIO_interface.h"

void DIO_Init(void)
{
	u8 PinNum_InPort;
	Port_type Port;
	PinStatus_type Status;
	u8 LocalIterator;
	
	for (LocalIterator=0;LocalIterator<TOTAL_PINS;LocalIterator++)
	{
		Status=PinsStatus[LocalIterator];
		Port=LocalIterator/8;
		PinNum_InPort=LocalIterator%8;
		
		switch (Status)
		{
			case OUTPUT:
			switch (Port)
			{
				case PA:
				SET_BIT(DDRA,PinNum_InPort);
				break;
				case PB:
				SET_BIT(DDRB,PinNum_InPort);
				break;
				case PC:
				SET_BIT(DDRC,PinNum_InPort);
				break;
				case PD:
				SET_BIT(DDRD,PinNum_InPort);
				break;
			}
			break;
			case INPULLUP:
			switch (Port)
			{
				case PA:
				CLEAR_BIT(DDRA,PinNum_InPort);
				SET_BIT(PORTA,PinNum_InPort);
				break;
				case PB:
				CLEAR_BIT(DDRB,PinNum_InPort);
				SET_BIT(PORTB,PinNum_InPort);
				break;
				case PC:
				CLEAR_BIT(DDRC,PinNum_InPort);
				SET_BIT(PORTC,PinNum_InPort);
				break;
				case PD:
				CLEAR_BIT(DDRD,PinNum_InPort);
				SET_BIT(PORTD,PinNum_InPort);
				break;
			}
			break;
			case INPUT:
			switch (Port)
			{
				case PA:
				CLEAR_BIT(DDRA,PinNum_InPort);
				CLEAR_BIT(PORTA,PinNum_InPort);
				break;
				case PB:
				CLEAR_BIT(DDRB,PinNum_InPort);
				CLEAR_BIT(PORTB,PinNum_InPort);
				break;
				case PC:
				CLEAR_BIT(DDRC,PinNum_InPort);
				CLEAR_BIT(PORTC,PinNum_InPort);
				break;
				case PD:
				CLEAR_BIT(DDRD,PinNum_InPort);
				CLEAR_BIT(PORTD,PinNum_InPort);
				break;
			}
			break;
		}
		
	}
}

void DIO_WritePort(Port_type Port,u8 Value)
{
	switch (Port)
	{
		case PA:
		ASSIGN_REG(PORTA,Value);
		break;
		case PB:
		ASSIGN_REG(PORTB,Value);
		break;
		case PC:
		ASSIGN_REG(PORTC,Value);
		break;
		case PD:
		ASSIGN_REG(PORTD,Value);
		break;
	}
}
void DIO_WriteBitsInPort(Port_type Port,u8 Value,u8 Mask)
{
	switch (Port)
	{
		case PA:
		CLEAR_BITS_REG(PORTA,Mask);
		SET_BITS_REG(PORTA,Value&Mask);
		break;
		case PB:
		CLEAR_BITS_REG(PORTB,Mask);
		SET_BITS_REG(PORTB,Value&Mask);
		break;
		case PC:
		CLEAR_BITS_REG(PORTC,Mask);
		SET_BITS_REG(PORTC,Value&Mask);
		break;
		case PD:
		CLEAR_BITS_REG(PORTD,Mask);
		SET_BITS_REG(PORTD,Value&Mask);
		break;
	}
}
u8 DIO_ReadPort(Port_type Port)
{
	switch (Port)
	{
		case PA:
		return PINA;
		break;
		case PB:
		return PINB;
		break;
		case PC:
		return PINC;
		break;
		case PD:
		return PIND;
		break;
		default:
		return 0x00;
		break;
	}
}
void DIO_WritePin(PinNum_type Pin,VoltageLevel_type Value)
{
	u8 PinNum_InPort=Pin%8;
	Port_type Port=Pin/8;
	switch (Port)
	{
		case PA:
		if (HIGH==Value)
		{
			SET_BIT(PORTA,PinNum_InPort);
		}
		else
		{
			CLEAR_BIT(PORTA,PinNum_InPort);
		}
		break;
		case PB:
		if (HIGH==Value)
		{
			SET_BIT(PORTB,PinNum_InPort);
		}
		else
		{
			CLEAR_BIT(PORTB,PinNum_InPort);
		}
		break;
		case PC:
		if (HIGH==Value)
		{
			SET_BIT(PORTC,PinNum_InPort);
		}
		else
		{
			CLEAR_BIT(PORTC,PinNum_InPort);
		}
		break;
		case PD:
		if (HIGH==Value)
		{
			SET_BIT(PORTD,PinNum_InPort);
		}
		else
		{
			CLEAR_BIT(PORTD,PinNum_InPort);
		}
		break;
	}
}
void DIO_TogglePin(PinNum_type Pin)
{
	u8 PinNum_InPort=Pin%8;
	Port_type Port=Pin/8;
	switch (Port)
	{
		case PA:
			TOOGLE_BIT(PORTA,PinNum_InPort);
		break;
		case PB:
			TOOGLE_BIT(PORTB,PinNum_InPort);
		break;
		case PC:
			TOOGLE_BIT(PORTC,PinNum_InPort);
		break;
		case PD:
			TOOGLE_BIT(PORTD,PinNum_InPort);
		break;
	}
}
VoltageLevel_type DIO_ReadPin(PinNum_type Pin)
{
	u8 PinNum_InPort=Pin%8;
	Port_type Port=Pin/8;
	switch (Port)
	{
		case PA:
		return CHECK_BIT(PINA,PinNum_InPort);
		break;
		case PB:
		return CHECK_BIT(PINB,PinNum_InPort);
		break;
		case PC:
		return CHECK_BIT(PINC,PinNum_InPort);
		break;
		case PD:
		return CHECK_BIT(PIND,PinNum_InPort);
		break;
		default:
		return 0x00;
		break;
	}
}

/*******************************************************************************************/
/* these function can be used without  calling  DIO_Init();   in main.c    */
/*******************************************************************************************/

/*
void DIO_setpinDirection( Port_type port, u8 pin,PinStatus_type Direction)
{
	switch(port)
	{
		case PA:
		if (Direction==OUTPUT)
		{
			SET_BIT(DDRA,pin);
		}
		else if(Direction==INPUT)
		{
			CLEAR_BIT(DDRA,pin);
		}
		break;
		case PB:
		if (Direction==OUTPUT)
		{
			SET_BIT(DDRB,pin);
		}
		else if(Direction==INPUT)
		{
			CLEAR_BIT(DDRB,pin);
		}
		break;
		case PC:
		if (Direction==OUTPUT)
		{
			SET_BIT(DDRC,pin);
		}
		else if(Direction==INPUT)
		{
			CLEAR_BIT(DDRC,pin);
		}
		break;
		case PD:
		if (Direction==OUTPUT)
		{
			SET_BIT(DDRD,pin);
		}
		else if(Direction==INPUT)
		{
			CLEAR_BIT(DDRD,pin);
		}
		break;
	}
}
void DIO_setpinvalue(Port_type port,u8 pin,u8 value)
{
	switch(port)
	{
		case PA:
		if (1==value)
		{
			SET_BIT(PORTA,pin);
			
		}
		else if (value==0)
		{
			CLEAR_BIT(PORTA,pin);
		}
		break;
		case PB:
		if (value==1)
		{
			SET_BIT(PORTB,pin);
			
		}
		else if (value==0)
		{
			CLEAR_BIT(PORTB,pin);
		}
		break;
		case PC:
		if (value==1)
		{
			SET_BIT(PORTC,pin);
			
		}
		else if (value==0)
		{
			CLEAR_BIT(PORTC,pin);
		}
		break;
		case PD:
		if (value==1)
		{
			SET_BIT(PORTD,pin);
			
		}
		else if (value==0)
		{
			CLEAR_BIT(PORTD,pin);
		}
		break;
		
		
	}
	
}
u8	DIO_readpin(Port_type port,u8 pin)
{
	u8 Local_u8value=0;
	switch(port)
	{
		case PA:
		Local_u8value=CHECK_BIT(PINA,pin);
		break;
		case PB:
		Local_u8value=CHECK_BIT(PINB,pin);
		break;
		case PC:
		Local_u8value=CHECK_BIT(PINC,pin);
		break;
		case PD:
		Local_u8value=CHECK_BIT(PIND,pin);
		break;
	}
	return Local_u8value;
	
	
}

void DIO_voidSetPortDirection(Port_type port , u8 Copy_u8Direction)
{
	switch(port)
	{
		case  PA :
		ASSIGN_REG(DDRA , Copy_u8Direction);
		break;
		
		case  PB :
		ASSIGN_REG(DDRB , Copy_u8Direction);
		break;
		
		case  PC :
		ASSIGN_REG(DDRC , Copy_u8Direction);
		break;
		
		case  PD :
		ASSIGN_REG(DDRD , Copy_u8Direction);
		break;
		
	}
}

void DIO_voidSetPortValue(Port_type port , u8 Copy_u8Value)
{
	switch(port)
	{
		case  PA :
		ASSIGN_REG(PORTA , Copy_u8Value);
		break;
		case  PB :
		ASSIGN_REG(PORTB , Copy_u8Value);
		break;
		case  PC :
		ASSIGN_REG(PORTC , Copy_u8Value);
		break;
		case  PD :
		ASSIGN_REG(PORTD , Copy_u8Value);
	}
}
*/

/*void DIO_higher_nibble_Direction(Port_type portNumber)
{
	switch(portNumber)
	{
		case PA:
		higher_nibble_high(DDRA);
		break;
		case PB:
		higher_nibble_high(DDRB);
		break;
		case PC:
		higher_nibble_high(DDRC);
		break;
		case PD:
		higher_nibble_high(DDRD);
		break;
	}
}
void DIO_lower_nibble_Direction(Port_type  portNumber)
{
	switch(portNumber)
	{
		case PA:
		lower_nibble_high(DDRA);
		break;
		case PB:
		lower_nibble_high(DDRB);
		break;
		case PC:
		lower_nibble_high(DDRC);
		break;
		case PD:
		lower_nibble_high(DDRD);
		break;
	}
}
void DIO_higher_nibble_Value(Port_type portNumber,u8 value)
{
	
	switch(portNumber)
	{
		case PA:
		higher_nibble_value(PORTA,value);
		break;
		case PB:
		higher_nibble_value(PORTB,value);
		break;
		case PC:
		higher_nibble_value(PORTC,value);
		break;
		case PD:
		higher_nibble_value(PORTD,value);
		break;
	}
	
}
void DIO_lower_nibble_value(Port_type  portNumber,u8 value)
{
	
	switch(portNumber)
	{
		case PA:
		lower_nibble_value(PORTA,value);
		break;
		case PB:
		lower_nibble_value(PORTB,value);
		break;
		case PC:
		lower_nibble_value(PORTC,value);
		break;
		case PD:
		lower_nibble_value(PORTD,value);
		break;
		
	}
}
u8   DIO_get_lower_nibble(Port_type port)
{
	u8 Local_u8value = 0;
	switch(port)
	{
		case PA:
		Local_u8value = get_lower_nibble(PINA);
		break;
		case PB:
		Local_u8value = get_lower_nibble(PINB);
		break;
		case PC:
		Local_u8value = get_lower_nibble(PINC);
		break;
		case PD:
		Local_u8value = get_lower_nibble(PIND);
		break;
	}
	return Local_u8value;
}
u8   DIO_get_higher_nibble(Port_type port)
{   
    u8 Local_u8value = 0;
	switch(port)
	{
		case PA:
		Local_u8value = get_higher_nibble(PINA);
		break;
		case PB:
		Local_u8value = get_higher_nibble(PINB);
		break;
		case PC:
		Local_u8value = get_higher_nibble(PINC);
		break;
		case PD:
		Local_u8value = get_higher_nibble(PIND);
		break;
	}
	return Local_u8value;
}
*/