/*
* LCD1602_4Bit_Private.h
*
* Created: 9/28/2023 5:07:46 PM
*  Author: Belal hassan
*/


#ifndef LCD1602_4BIT_PRIVATE_H_
#define LCD1602_4BIT_PRIVATE_H_

#include "LCD_Configuration.h"

uint32_t Character_Counter;
Bool CursorDirection;
void LCD_Enable(void);
void LCD_Send_Command(uint8_t Command);
void LCD_HomeScreen(void);
void LCD_ClearScreen(void);
void LCD_Initialize(void);
void LCD_Display_Character(uint8_t Character);
void LCD_Display_String(uint8_t String[]);
void LCD_Reverse_String(uint8_t String[], uint8_t Length);
uint8_t LCD_IntToString(uint32_t Number, uint8_t String[], uint8_t Length);
void LCD_Display_Number(uint32_t Number);
void LCD_FloatToString(fint32_t Number, uint8_t String[], uint8_t AfterPoint);
void LCD_Display_FloatNumber(fint32_t Number, uint8_t AfterPoint);
void LCD_Display_Location(uint8_t xAxis, uint8_t yAxis);
void LCD_Send_Special(uint8_t Character);
void LCD_Store_Special(uint8_t Character[], uint8_t Address);

#endif /* LCD1602_4BIT_PRIVATE_H_ */


