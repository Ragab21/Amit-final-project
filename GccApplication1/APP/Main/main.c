/*
* Interfacing_NASR57_Modules.c
*
* Created: 9/15/2023 10:19:27 AM
* Author : oraga
*/

#include "main.h"


int main() 
{
	while(1)
	{ICU_Initialize();
	LCD_Initialize();
	LCD_ClearScreen();
	FreqAndDuty results;
	
	results = Get_FreqAndDuty();
	if(results.acceptable == 0)
	{
		LCD_ClearScreen();
		LCD_Display_String("OUT OF RANGE!!");
	}
	char frequency[14];
	char duty_cy[7];
	strcpy(frequency,results.frequency);
	strcpy(duty_cy,results.duty_cy);

	LCD_Display_String("F:");
	LCD_Display_String(results.frequency);
	LCD_Display_String("Hz ");


	LCD_Display_String("D:");
	LCD_Display_String(duty_cy);
	LCD_Display_String("%");
	
	LCD_Display_Location(0,1);
	uint8_t Dash = results.dutyCycle * 14 / 100;
	uint8_t Underscore = 14 - Dash;

	// Draw the impulse wave
	LCD_Display_String("|");
	for (uint8_t i = 0; i < Dash; i++) {
	   LCD_Display_String("-");
	}
	for (uint8_t i = 0; i < Underscore; i++) {
	    LCD_Display_String("_");
	}
	LCD_Display_String("|");
	}
	return 0;
	
}


