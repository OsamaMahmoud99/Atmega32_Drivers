#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Mem_Map32.h"

#include "DIO_config.h"

#define   INTERNAL_VOLTAGES         ADMUX|=(1<< REFS0 )|(1<< REFS1)
#define   AREF_VOLTAGES             ADMUX&=(~(1<<REFS0))&(~(1<<REFS1))
#define   AVCC_VOLTAGES             SET_BIT(ADMUX,REFS0),CLEAR_BIT(ADMUX,REFS1)
#define   selected_pin(pin)         ADMUX=(ADMUX&0xE0)|((pin)&0x1f)

#define   adc_interruptflag          ADCSRA &=(1<<ADIF)
#define   adc_startconversion        ADCSRA |=(1<<ADSC)

#define   adc_disable                ADCSRA &=(~(1<<ADEN))
#define   adc_enable                 ADCSRA |=(1<<ADEN)

#define   divisionfactor2      CLEAR_BIT(ADCSRA,ADPS0),CLEAR_BIT(ADCSRA,ADPS1),CLEAR_BIT(ADCSRA,ADPS2)
#define   divisionfactor4      CLEAR_BIT(ADCSRA,ADPS0),SET_BIT(ADCSRA,ADPS1),CLEAR_BIT(ADCSRA,ADPS2)
#define   divisionfactor8      SET_BIT(ADCSRA,ADPS0),SET_BIT(ADCSRA,ADPS1),CLEAR_BIT(ADCSRA,ADPS2)
#define   divisionfactor16     CLEAR_BIT(ADCSRA,ADPS0),CLEAR_BIT(ADCSRA,ADPS1),SET_BIT(ADCSRA,ADPS2)                  
#define   divisionfactor32     SET_BIT(ADCSRA,ADPS0),CLEAR_BIT(ADCSRA,ADPS1),SET_BIT(ADCSRA,ADPS2)
#define   divisionfactor64     CLEAR_BIT(ADCSRA,ADPS0),SET_BIT(ADCSRA,ADPS1),SET_BIT(ADCSRA,ADPS2)
#define   divisionfactor128    SET_BIT(ADCSRA,ADPS0),SET_BIT(ADCSRA,ADPS1),SET_BIT(ADCSRA,ADPS2)

typedef enum
{
	ADC0=PINA0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7,
	}INPUT_pins;
	
typedef enum
{
	divfact2,
	divfact4,
	divfact8,
	divfact16,
	divfact32,
	divfact64,
	divfact128,
	
	}division_factor;
	
typedef enum
{
	internal,
	EXTERNALAREF,
	EXTERNALAVCC,
	}used_voltage;

void adc_init(division_factor fact,used_voltage used);
unsigned short adc_read(u8 adc_pin);
float adc_read_voltage(INPUT_pins adc_pin);
void adc_update();
	
	

#endif /* ADC_H_ */
