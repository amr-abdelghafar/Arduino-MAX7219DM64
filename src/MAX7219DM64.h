/*
 *    MAX7219DM64.h - A library for controling Leds with a MAX7219
 *    Copyright (c) 2019 Amr Abdelghafar
 * 
 *    Permission is hereby granted, free of charge, to any person
 *    obtaining a copy of this software and associated documentation
 *    files (the "Software"), to deal in the Software without
 *    restriction, including without limitation the rights to use,
 *    copy, modify, merge, publish, distribute, sublicense, and/or sell
 *    copies of the Software, and to permit persons to whom the
 *    Software is furnished to do so, subject to the following
 *    conditions:
 * 
 *    This permission notice shall be included in all copies or 
 *    substantial portions of the Software.
 * 
 *    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *    OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef MAX7219DM64_h
#define MAX7219DM64_h

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif
#include <avr/pgmspace.h>

PROGMEM const unsigned char CH[] = {
B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, //  
B10000000, B10000000, B10000000, B10000000, B10000000, B00000000, B10000000, B00000000, //  
B10100000, B10100000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, //  
B00000000, B01010000, B11111000, B01010000, B11111000, B01010000, B00000000, B00000000, //  
B00100000, B01110000, B10000000, B01100000, B00010000, B11100000, B01000000, B00000000, //  
B11001000, B11001000, B00010000, B00100000, B01000000, B10011000, B10011000, B00000000, //  
B01000000, B10100000, B10100000, B01000000, B10101000, B10010000, B01101000, B00000000, //  
B10000000, B10000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, //  
B00100000, B01000000, B10000000, B10000000, B10000000, B01000000, B00100000, B00000000, //  
B10000000, B01000000, B00100000, B00100000, B00100000, B01000000, B10000000, B00000000, //  
B00000000, B00100000, B00100000, B11111000, B01010000, B10001000, B00000000, B00000000, //  
B00000000, B00100000, B00100000, B11111000, B00100000, B00100000, B00000000, B00000000, //  
B00000000, B00000000, B00000000, B00000000, B11000000, B11000000, B01000000, B10000000, //  
B00000000, B00000000, B00000000, B11110000, B00000000, B00000000, B00000000, B00000000, //  
B00000000, B00000000, B00000000, B00000000, B00000000, B11000000, B11000000, B00000000, //  
B00010000, B00100000, B00100000, B01000000, B01000000, B10000000, B10000000, B00000000, //  
B01100000, B10010000, B10010000, B10010000, B10010000, B10010000, B01100000, B00000000, //  
B01000000, B11000000, B01000000, B01000000, B01000000, B01000000, B11100000, B00000000, //  
B01100000, B10010000, B00010000, B00100000, B01000000, B10000000, B11110000, B00000000, //  
B01100000, B10010000, B00010000, B00100000, B00010000, B10010000, B01100000, B00000000, //  
B00010000, B00110000, B01010000, B10010000, B11110000, B00010000, B00010000, B00000000, //  
B11110000, B10000000, B11100000, B00010000, B00010000, B10010000, B01100000, B00000000, //  
B01100000, B10000000, B10000000, B11100000, B10010000, B10010000, B01100000, B00000000, //  
B11110000, B00010000, B00010000, B00100000, B01000000, B10000000, B10000000, B00000000, //  
B01100000, B10010000, B10010000, B01100000, B10010000, B10010000, B01100000, B00000000, //  
B01100000, B10010000, B10010000, B01110000, B00010000, B00010000, B01100000, B00000000, //  
B00000000, B00000000, B00000000, B00000000, B10000000, B00000000, B10000000, B00000000, //  
B00000000, B00000000, B00000000, B00000000, B01000000, B00000000, B01000000, B10000000, //  
B00000000, B00000000, B00100000, B01000000, B10000000, B01000000, B00100000, B00000000, //  
B00000000, B00000000, B11100000, B00000000, B11100000, B00000000, B00000000, B00000000, //  
B00000000, B00000000, B10000000, B01000000, B00100000, B01000000, B10000000, B00000000, //  
B01100000, B10010000, B00010000, B01100000, B01000000, B00000000, B01000000, B00000000, //  
B01110000, B10001000, B10111000, B11011000, B10110000, B10000000, B01110000, B00000000, //  
B01100000, B10010000, B10010000, B10010000, B11110000, B10010000, B10010000, B00000000, //  
B11100000, B10010000, B10010000, B11100000, B10010000, B10010000, B11100000, B00000000, //  
B01100000, B10010000, B10000000, B10000000, B10000000, B10010000, B01100000, B00000000, //  
B11100000, B10010000, B10010000, B10010000, B10010000, B10010000, B11100000, B00000000, //  
B11110000, B10000000, B10000000, B11100000, B10000000, B10000000, B11110000, B00000000, //  
B11110000, B10000000, B10000000, B11100000, B10000000, B10000000, B10000000, B00000000, //  
B01100000, B10010000, B10000000, B10110000, B10010000, B10010000, B01110000, B00000000, //  
B10010000, B10010000, B10010000, B11110000, B10010000, B10010000, B10010000, B00000000, //  
B11100000, B01000000, B01000000, B01000000, B01000000, B01000000, B11100000, B00000000, //  
B00110000, B00010000, B00010000, B00010000, B10010000, B10010000, B01100000, B00000000, //  
B10010000, B10010000, B10100000, B11000000, B10100000, B10010000, B10010000, B00000000, //  
B10000000, B10000000, B10000000, B10000000, B10000000, B10000000, B11110000, B00000000, //  
B10001000, B11011000, B10101000, B10101000, B10001000, B10001000, B10001000, B00000000, //  
B10001000, B10001000, B11001000, B10101000, B10011000, B10001000, B10001000, B00000000, //  
B01100000, B10010000, B10010000, B10010000, B10010000, B10010000, B01100000, B00000000, //  
B11100000, B10010000, B10010000, B11100000, B10000000, B10000000, B10000000, B00000000, //  
B01100000, B10010000, B10010000, B10010000, B10010000, B10010000, B01100000, B00010000, //  
B11100000, B10010000, B10010000, B11100000, B10010000, B10010000, B10010000, B00000000, //  
B01100000, B10010000, B10000000, B01100000, B00010000, B00010000, B11100000, B00000000, //  
B11111000, B00100000, B00100000, B00100000, B00100000, B00100000, B00100000, B00000000, //  
B10010000, B10010000, B10010000, B10010000, B10010000, B10010000, B01100000, B00000000, //  
B10001000, B10001000, B10001000, B10001000, B01010000, B01010000, B00100000, B00000000, //  
B10001000, B10001000, B10001000, B10101000, B10101000, B10101000, B01010000, B00000000, //  
B10001000, B10001000, B01010000, B00100000, B01010000, B10001000, B10001000, B00000000, //  
B10001000, B10001000, B10001000, B01010000, B00100000, B00100000, B00100000, B00000000, //  
B11110000, B00010000, B00010000, B00100000, B01000000, B10000000, B11110000, B00000000, //  
B11000000, B10000000, B10000000, B10000000, B10000000, B10000000, B11000000, B00000000, //  
B10000000, B01000000, B01000000, B00100000, B00100000, B00010000, B00010000, B00000000, //  
B11000000, B01000000, B01000000, B01000000, B01000000, B01000000, B11000000, B00000000, //  
B01000000, B10100000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, //  
B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B11110000, B00000000, //  
B10000000, B01000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, //  
B00000000, B00000000, B01100000, B00010000, B01110000, B10010000, B01110000, B00000000, //  
B10000000, B10000000, B11100000, B10010000, B10010000, B10010000, B11100000, B00000000, //  
B00000000, B00000000, B01100000, B10010000, B10000000, B10010000, B01100000, B00000000, //  
B00010000, B00010000, B01110000, B10010000, B10010000, B10010000, B01110000, B00000000, //  
B00000000, B00000000, B01100000, B10010000, B11110000, B10000000, B01100000, B00000000, //  
B00100000, B01000000, B11100000, B01000000, B01000000, B01000000, B01000000, B00000000, //  
B00000000, B00000000, B01100000, B10010000, B10010000, B01110000, B00010000, B11100000, //  
B10000000, B10000000, B11100000, B10010000, B10010000, B10010000, B10010000, B00000000, //  
B01000000, B00000000, B11000000, B01000000, B01000000, B01000000, B11100000, B00000000, //  
B00010000, B00000000, B00110000, B00010000, B00010000, B00010000, B10010000, B01100000, //  
B10000000, B10000000, B10010000, B10100000, B11000000, B10100000, B10010000, B00000000, //  
B11000000, B01000000, B01000000, B01000000, B01000000, B01000000, B11100000, B00000000, //  
B00000000, B00000000, B11110000, B10101000, B10101000, B10101000, B10101000, B00000000, //  
B00000000, B00000000, B11100000, B10010000, B10010000, B10010000, B10010000, B00000000, //  
B00000000, B00000000, B01100000, B10010000, B10010000, B10010000, B01100000, B00000000, //  
B00000000, B00000000, B11100000, B10010000, B10010000, B11100000, B10000000, B10000000, //  
B00000000, B00000000, B01110000, B10010000, B10010000, B01110000, B00010000, B00010000, //  
B00000000, B00000000, B10110000, B11000000, B10000000, B10000000, B10000000, B00000000, //  
B00000000, B00000000, B01110000, B10000000, B01100000, B00010000, B11100000, B00000000, //  
B01000000, B01000000, B11100000, B01000000, B01000000, B01000000, B00100000, B00000000, //  
B00000000, B00000000, B10010000, B10010000, B10010000, B10010000, B01110000, B00000000, //  
B00000000, B00000000, B10001000, B10001000, B10001000, B01010000, B00100000, B00000000, //  
B00000000, B00000000, B10101000, B10101000, B10101000, B10101000, B01010000, B00000000, //  
B00000000, B00000000, B10001000, B01010000, B00100000, B01010000, B10001000, B00000000, //  
B00000000, B00000000, B10010000, B10010000, B10010000, B01110000, B00010000, B11100000, //  
B00000000, B00000000, B11100000, B00100000, B01000000, B10000000, B11100000, B00000000, //  
B00100000, B01000000, B01000000, B10000000, B01000000, B01000000, B00100000, B00000000, //  
B10000000, B10000000, B10000000, B10000000, B10000000, B10000000, B10000000, B00000000, //  
B10000000, B01000000, B01000000, B00100000, B01000000, B01000000, B10000000, B00000000, //  
B00000000, B00000000, B01010000, B10100000, B00000000, B00000000, B00000000, B00000000, //
};



class MAX7219DM64
{
  private :
    /* The array for shifting the data to the devices */
    byte spidata[16];
    /* Send out a single command to the device */
    void spiTransfer(int addr, byte opcode, byte data);

    /* We keep track of the led-status for all 8 devices in this array */
    byte status[64];
    /* Data is shifted out of this pin*/
    int SPI_MOSI;
    /* The clock is signaled on this pin */
    int SPI_CLK;
    /* This one is driven LOW for chip selectzion */
    int SPI_CS;
    /* The maximum number of devices we use */
    int maxDevices;

  public:
      /* 
        * Create a new controler 
        * Params :
        * dataPin		pin on the Arduino where data gets shifted out
        * clockPin		pin for the clock
        * csPin		pin for selecting the device 
        * numDevices	maximum number of devices that can be controled
        */
      MAX7219DM64(int dataPin, int clkPin, int csPin, int numDevices=1, int intensity=8);

      /*
        * Gets the number of devices attached to this MAX7219DM64.
        * Returns :
        * int	the number of devices on this MAX7219DM64
        */
      int getDeviceCount();

      /* 
        * Set the shutdown (power saving) mode for the device
        * Params :
        * addr	The address of the display to control
        * status	If true the device goes into power-down mode. Set to false
        *		for normal operation.
        */
      void shutdown(int addr, bool status);

      /* 
        * Set the number of digits (or rows) to be displayed.
        * See datasheet for sideeffects of the scanlimit on the brightness
        * of the display.
        * Params :
        * addr	address of the display to control
        * limit	number of digits to be displayed (1..8)
        */
      void setScanLimit(int addr, int limit);

      /* 
        * Set the brightness of the display.
        * Params:
        * addr		the address of the display to control
        * intensity	the brightness of the display. (0..15)
        */
      void setIntensity(int addr, int intensity);

      /* 
        * Switch all Leds on the display off. 
        * Params:
        * addr	address of the display to control
        */
      void clearDisplay(int addr);

      /* 
        * Set the status of a single Led.
        * Params :
        * addr	address of the display 
        * row	the row of the Led (0..7)
        * col	the column of the Led (0..7)
        * state	If true the led is switched on, 
        *		if false it is switched off
        */
      void setLed(int addr, int row, int col, boolean state);

      /* 
        * Set all 8 Led's in a row to a new state
        * Params:
        * addr	address of the display
        * row	row which is to be set (0..7)
        * value	each bit set to 1 will light up the
        *		corresponding Led.
        */
      void setRow(int addr, int row, byte value);

      /* 
        * Set all 8 Led's in a column to a new state
        * Params:
        * addr	address of the display
        * col	column which is to be set (0..7)
        * value	each bit set to 1 will light up the
        *		corresponding Led.
        */
      void setColumn(int addr, int col, byte value);
    
      /*
        * Display a character.
        * There are only a few characters that make sense here :
        *	'0','1','2','3','4','5','6','7','8','9','0',
        *  'A','b','c','d','E','F','H','L','P',
        *  '.','-','_',' ' 
        * Params:
        * addr	address of the display
        * value	the character to be displayed. 
        */
      void setChar(int addr, char value);
};

#endif
