# mbed6 LCDi2c library for HD47780

This library is for the HD47780 LCDs with I2C interface for use with mbed 6


## Installation

1. "Download":https://github.com/sstaub/mbedLCDi2c/archive/master.zip the Master branch from GitHub.
2. Unzip and modify the folder name to "mbedLCDi2c"
3. Move the modified folder on your Library folder.


## Example
Here is a simple example which shows the capabilities of the display

```cpp
// example for mbed6 LCD library

#include "mbed.h"
#include "LCDi2c.h"

// special chars
uint8_t upArrow[8] = {  
	0b00100,
	0b01010,
	0b10001,
	0b00100,
	0b00100,
	0b00100,
	0b00000,
	};

uint8_t downArrow[8] = {
	0b00000,
	0b00100,
	0b00100,
	0b00100,
	0b10001,
	0b01010,
	0b00100,
	};

uint8_t rightArrow[8] = {
	0b00000,
	0b00100,
	0b00010,
	0b11001,
	0b00010,
	0b00100,
	0b00000,
	};

uint8_t leftArrow[8] = {
	0b00000,
	0b00100,
	0b01000,
	0b10011,
	0b01000,
	0b00100,
	0b00000,
	};

//LCD_I2C lcd(I2C_SDA, I2C_SCL, LCD16x2, 0x27); // SDA, SCL, device address, LCD type
LCDi2c lcd(I2C_SDA, I2C_SCL);

int main() {
	
	lcd.create(0, downArrow);
	lcd.create(1, upArrow);
	lcd.create(2, rightArrow);
	lcd.create(3, leftArrow);
	
	lcd.cls();
	lcd.locate(0, 0);
	lcd.printf("Hello World!\n");
	lcd.character(0, 1, 0);
	lcd.character(3, 1, 1);
	lcd.character(5, 1, 2);
	lcd.character(7, 1, 3);

	ThisThread::sleep_for(2s);
	lcd.cls();
	lcd.locate(0, 0);
	lcd.printf("Hello World!\n");
	
	ThisThread::sleep_for(2s);
	lcd.display(BACKLIGHT_OFF);
	ThisThread::sleep_for(2s);
	lcd.display(BACKLIGHT_ON);
	ThisThread::sleep_for(2s);
	lcd.display(DISPLAY_OFF);
	ThisThread::sleep_for(2s);
	lcd.display(DISPLAY_ON);
	ThisThread::sleep_for(2s);
	lcd.display(CURSOR_ON);
	ThisThread::sleep_for(2s);
	lcd.display(BLINK_ON);
	ThisThread::sleep_for(2s);
	lcd.display(BLINK_OFF);
	ThisThread::sleep_for(2s);
	lcd.display(CURSOR_OFF);

	while(1) {
		for (uint8_t pos = 0; pos < 13; pos++) {
    	// scroll one position to left
    	lcd.display(SCROLL_LEFT);
    	// step time
    	ThisThread::sleep_for(500ms);
  		}

  	// scroll 29 positions (string length + display length) to the right
  	// to move it offscreen right
  	for (uint8_t pos = 0; pos < 29; pos++) {
  	  // scroll one position to right
  	  lcd.display(SCROLL_RIGHT);
  	  // step time
  	  ThisThread::sleep_for(500ms);
  		}

  	// scroll 16 positions (display length + string length) to the left
  	// to move it back to center
  	for (uint8_t pos = 0; pos < 16; pos++) {
  	  // scroll one position to left
  	  lcd.display(SCROLL_LEFT);
  	  // step time
  	  ThisThread::sleep_for(500ms);
  		}
 
		ThisThread::sleep_for(1s);
		}
	}
```

# Documentation

## Display types
following display types are supported

- **LCD16x2** 16x2 LCD panel (default)
- **LCD20x2** 20x2 LCD panel
- **LCD20x4** 20x4 LCD panel
- **LCD40x2** 40x2 LCD panel


## Constructor
create a LCD object

```ccp
LCDi2c::LCDi2c(PinName sda, PinName scl, lcd_t type = LCD16x2, int deviceAddress = 0x27);
LCDi2c::LCDi2c(lcd_t type, int deviceAddress = 0x27);
```

- **sda** I2C SDA pin
- **scl** I2C SCL pin
- **deviceAddress** I2C device address
- **type** display type

**Example**

```cpp
LCDi2c lcd(I2C_SDA, I2C_SCL);
LCDi2c lcd(LCD16x2); // using standard I2C pins I2C_SDA, I2C_SCL
```

## Class Functions

### Clear Screen

```cpp
void LCDi2c::cls()
```
clears the screen, set cursor to home

**Example**

```cpp
lcd.cls();
```

### Display Modes

```cpp
void LCDi2c::display(modes_t mode)
```

set the modes of the display

- DISPLAY_ON turn the display on
- DISPLAY_OFF turn the display off
- CURSOR_ON turn the underline cursor on
- CURSOR_OFF turn the underline cursor off
- BLINK_ON turn the blinking cursor on
- BLINK_OFF turn the blinking cursor off
- SCROLL_LEFT these command scroll the display without changing the RAM
- SCROLL_RIGHT these command scroll the display without changing the RAM
- LEFT_TO_RIGHT this is for text that flows Left to Right
- RIGHT_TO_LEFT this is for text that flows Right to Left
- AUTOSCROLL_ON this will 'right justify' text from the cursor
- AUTOSCROLL_OFF this will 'left justify' text from the cursor
- BACKLIGHT_ON turn the backlight on
- BACKLIGHT_OFF turn the backlight off

**Example**

```cpp
lcd.display(CURSOR_ON);
```

### Cursor Location

```cpp
void LCDi2c::locate(uint8_t column, uint8_t row)
```

set poition of the cursor

- **column** position column
- **row** position row

**Example**

```cpp
lcd.locate(0, 0);
```

### Cursor Home

```cpp
void LCDi2c::home()
```
set cursor to home position (0/0)

**Example**

```cpp
lcd.home();
```

### User defined chars

```cpp
void LCDi2c::create(uint8_t location, uint8_t charmap[])
```

Create a user defined char object allows us to fill the first 8 CGRAM locations with custom characters

- **loacation** number 0 - 7
- **charmap** array which contains the char

**Example**

```cpp
uint8_t upArrow[8] = {  
	0b00100,
	0b01010,
	0b10001,
	0b00100,
	0b00100,
	0b00100,
	0b00000,
	};

lcd.create(0, downArrow);
```

### Character

```cpp
void LCDi2c::character(uint8_t column, uint8_t row, uint8_t c) 
```

draw a single character on given position, usefull for user chars

- **column** position column
- **row** position row
- **c** number of the user char

**Example**

```cpp
lcd.character(0, 1, 0);
```

## Helper Function

### I2C address parser

```cpp
void parseI2C()
```

Is a helper function for scanning the I2C address of the device if is unknown.

**Example**

```cpp
parseI2C();
```