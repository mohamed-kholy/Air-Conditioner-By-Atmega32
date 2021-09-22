#include"lcd.h"

void EULLCD_voidLCDInit(){
	LCD_CTRL_PORT_DIR |= (1<<RS) | (1<<E) | (1<<RW);
	#if (DATA_BITS_MODE == 8)
		LCD_DATA_PORT_DIR = 0xFF;
		EULCD_voidLCDWriteCommand(TWO_LINES_EIGHT_BITS_MODE);
	#elif (DATA_BITS_MODE == 4)
		#ifdef UPPER_PORT
			LCD_DATA_PORT_DIR |= 0xF0;
		#else
			LCD_DATA_PORT_DIR |= 0x0F;
		#endif
		EULCD_voidLCDWriteCommand(FOUR_BITS_DATA_MODE);
		EULCD_voidLCDWriteCommand(TWO_LINES_FOUR_BITS_MODE);
	#endif
	EULCD_voidLCDWriteCommand(CLEAR_SCREEN);
	EULCD_voidLCDWriteCommand(CURSOR_OFF);

}

void EULCD_voidLCDWriteCommand(uint8 command){
	CLEAR_BIT(LCD_CTRL_PORT, RS);
	CLEAR_BIT(LCD_CTRL_PORT, RW);
	_delay_ms(1);
	SET_BIT(LCD_CTRL_PORT, E);
	_delay_ms(1);
	#if (DATA_BITS_MODE == 8)
		LCD_DATA_PORT = command;
		_delay_ms(1);
		CLEAR_BIT(LCD_CTRL_PORT, E);
		_delay_ms(1);
	#elif (DATA_BITS_MODE == 4)
		#ifdef UPPER_PORT
			LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (command & 0xF0);
			_delay_ms(1);
			CLEAR_BIT(LCD_CTRL_PORT, E);
			_delay_ms(1);
			SET_BIT(LCD_CTRL_PORT, E);
			_delay_ms(1);
			LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (command << 4);
			_delay_ms(1);
			CLEAR_BIT(LCD_CTRL_PORT, E);
			_delay_ms(1);
		#else
			LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | (command >> 4);
			_delay_ms(1);
			CLEAR_BIT(LCD_CTRL_PORT, E);
			_delay_ms(1);
			SET_BIT(LCD_CTRL_PORT, E);
			_delay_ms(1);
			LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | (command & 0x0F);
			_delay_ms(1);
			CLEAR_BIT(LCD_CTRL_PORT, E);
			_delay_ms(1);
		#endif
	#endif
}

void EULCD_voidLCDWriteChar(uint8 character){
	SET_BIT(LCD_CTRL_PORT, RS);
	CLEAR_BIT(LCD_CTRL_PORT, RW);
	_delay_ms(1);
	SET_BIT(LCD_CTRL_PORT, E);
	_delay_ms(1);
	#if (DATA_BITS_MODE == 8)
		LCD_DATA_PORT = character;
		_delay_ms(1);
		CLEAR_BIT(LCD_CTRL_PORT, E);
		_delay_ms(1);
	#elif (DATA_BITS_MODE == 4)
		#ifdef UPPER_PORT
			LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (character & 0xF0);
			_delay_ms(1);
			CLEAR_BIT(LCD_CTRL_PORT, E);
			_delay_ms(1);
			SET_BIT(LCD_CTRL_PORT, E);
			_delay_ms(1);
			LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (character << 4);
			_delay_ms(1);
			CLEAR_BIT(LCD_CTRL_PORT, E);
			_delay_ms(1);
		#else
			LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | (character >> 4);
			_delay_ms(1);
			CLEAR_BIT(LCD_CTRL_PORT, E);
			_delay_ms(1);
			SET_BIT(LCD_CTRL_PORT, E);
			_delay_ms(1);
			LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | (character & 0x0F);
			_delay_ms(1);
			CLEAR_BIT(LCD_CTRL_PORT, E);
			_delay_ms(1);
		#endif
	#endif
}

void EULCD_voidLCDWriteString (uint8 *str){
	while(*str!='\0'){
		EULCD_voidLCDWriteChar(*str);
		str++;
	}
}

void EULCD_voidLCDDisplayInteger (int num){
	char array[16];
	itoa(num, array, 10);
	EULCD_voidLCDWriteString(array);
}

void EULCD_voidLCDGoto (uint8 row, uint8 coloumn){
	switch(row){
		case 0:
			EULCD_voidLCDWriteCommand(coloumn+127);
			break;
		case 1:
			EULCD_voidLCDWriteCommand(coloumn+191);
			break;
	}

}
