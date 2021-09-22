#ifndef LCD_H_
#define LCD_H_

#include"std_types.h"
#include"micro_config.h"
#include"common_macros.h"

#define DATA_BITS_MODE 		4
#define UPPER_PORT
//#undef  UPPER_PORT

#define LCD_DATA_PORT_DIR 		DDRB
#define LCD_DATA_PORT 		PORTB

#define LCD_CTRL_PORT_DIR DDRB
#define LCD_CTRL_PORT PORTB

#define RS 0
#define RW 1
#define E 2
#define TWO_LINES_EIGHT_BITS_MODE 	0x38
#define ONE_LINE_EIGHT_BITS_MODE 	0x30
#define TWO_LINES_FOUR_BITS_MODE 	0x28
#define ONE_LINE_FOUR_BITS_MODE 	0x20
#define FOUR_BITS_DATA_MODE			0x02

#define CLEAR_SCREEN 				0x01
#define CURSOR_OFF 					0x0C
#define SET_CURSOR_LOCATION 		0x80

void EULLCD_voidLCDInit();
void EULCD_voidLCDWriteChar(uint8 character);
void EULCD_voidLCDWriteString (uint8 *str);
void EULCD_voidLCDWriteCommand(uint8 command);
void EULCD_voidLCDDisplayInteger (int num);
void EULCD_voidLCDGoto (uint8 row, uint8 coloumn);

#endif /* LCD_H_ */
