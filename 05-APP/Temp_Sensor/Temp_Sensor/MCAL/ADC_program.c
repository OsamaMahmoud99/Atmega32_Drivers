#include "ADC_interface.h"

static float vref=0;
void adc_init(division_factor fact,used_voltage used)
{
	adc_enable;
	switch(used)
	{
		case internal:     vref=2.56;     INTERNAL_VOLTAGES; break;
		case EXTERNALAVCC: vref=5;        AVCC_VOLTAGES;     break;
		case EXTERNALAREF: vref=5;        AREF_VOLTAGES;     break;
	}
	
	switch(fact)
	{
		case divfact2:          divisionfactor2;break;
		case divfact4:          divisionfactor4;break;
		case divfact8:          divisionfactor8;break;
		case divfact16:         divisionfactor16;break;
		case divfact32:         divisionfactor32;break;
		case divfact64:         divisionfactor64;break;
		case divfact128:        divisionfactor128;break;
	}
}

u16 adc_read(INPUT_pins adc_pin)
{   unsigned short read_val;
	selected_pin(adc_pin);
	adc_startconversion;
	while(ADIF==0){};
	read_val=(ADCL);
	read_val|=(ADCH<<8);	
	return read_val;
}
float adc_read_voltage(INPUT_pins adc_pin)
{
	float adc_val=adc_read(adc_pin);
	adc_val=(adc_val*vref)/1024;
	return adc_val;
}
