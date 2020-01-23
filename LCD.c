#include "LCD.h"
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

// flags for backlight control

#define LCD_NOBACKLIGHT 0x00
#define Bl 0b00001000
#define En 0b00000100  // Enable bit
#define Rw 0b00000010  // Read/Write bit
//#define Rs 0b00000001  // Register select bit

#define LCD 0x3F
void LCDWrite(uint8_t date, uint8_t Rs)
{	
	uint8_t data2=date;
	data2 &= 0xF0;
	I2C_write(LCD, (data2) | Bl | Rs |  En);
	I2C_write(LCD, (data2)| Bl | Rs);
	I2C_write(LCD, (date << 4) | Bl | Rs |  En);
	I2C_write(LCD, (date << 4)| Bl | Rs);
}

void LCDFirstRow()
{
	LCDWrite(0b10000000,0);
}
void LCDSecondRow()
{
	LCDWrite(0b11000000,0);
}




// 0b	0		0		0		0		0		0		0		0						0b	0		0		0		0		0		0		0		0
//		DB7	DB6	DB5	DB4	BL	E		R/W	RS					DB3	DB2	DB1	DB0	BL	E		R/W	RS
void LCDInit() 
{
	I2C_write(0x3F, 0b00000000);

	for (int i = 0; i<419400; i++)
	{}
	I2C_write(0x3F, 0b00000000);	
	
	I2C_write(0x3F, 0b00110100);
	I2C_write(0x3F, 0b00110000);
		
	for (int i = 0; i<19250; i++)
	{}	
	;
	I2C_write(0x3F, 0b00110100);
	I2C_write(0x3F, 0b00110000);
		
	for (int i = 0; i<19250; i++)
	{}		
	
	I2C_write(0x3F, 0b00110100);
	I2C_write(0x3F, 0b00110000);

	for (int i = 0; i<9017; i++)
	{}
	
	I2C_write(0x3F, 0b00100100);
	I2C_write(0x3F, 0b00100000);
		
	I2C_write(0x3F, 0b00100000);
	I2C_write(0x3F, 0b00100100);
	I2C_write(0x3F, 0b00100000);

	
	I2C_write(0x3F, 0b10000100);
	I2C_write(0x3F, 0b10000000);
		
	
	I2C_write(0x3F, 0b00000100);
	I2C_write(0x3F, 0b00000000);
		
	
	I2C_write(0x3F, 0b11000100);
	I2C_write(0x3F, 0b11000000);
	
	
	I2C_write(0x3F, 0b00000100);
	I2C_write(0x3F, 0b00000000);
	
	
	I2C_write(0x3F, 0b00010100);
	I2C_write(0x3F, 0b00010000);
	
	for (int i = 0; i<8723; i++)
	{}
	
	I2C_write(0x3F, 0b00000100);
	I2C_write(0x3F, 0b00000000);

	
	I2C_write(0x3F, 0b11000100);
	I2C_write(0x3F, 0b11000000);
		
	
	I2C_write(0x3F, 0b00000100);
	I2C_write(0x3F, 0b00000000);
	
	
	I2C_write(0x3F, 0b00000100);
	I2C_write(0x3F, 0b00000000);
		
	for (int i = 0; i<8723; i++)
	{}	
	I2C_write(0x3F, 0b00001000);			//koniec inicjalizacji
		
		
	LCDFirstRow();
	LCDWrite(0b01000100,1);				//d
	LCDWrite(0b01011001,1);				//y
	LCDWrite(0b01010011,1);				//s
	LCDWrite(0b01010100,1);				//t	
	LCDWrite(0b01000001,1);				//a
	LCDWrite(0b01001110,1);				//n
	LCDWrite(0b01010011,1);				//s
	LCDWrite(0b00111010,1);				//:
	LCDSecondRow();
		
	for (int i=0;i<15;i++) {
		LCDWrite(0b11111111,1);
		delay_mc(100);
	}
	LCDFirstRow();
	LCDWrite(0b00000000,0);
	
}