#include "MAX7219DM64.h"

// Please Change these for your choice PINS
#define DATA_PIN 30
#define CS_PIN 31
#define CLK_PIN 32
#define NUM_DEVICES 1
#define INTENSITY 8
/////////////////////////////////////////

MAX7219DM64 ledMtrx = MAX7219DM64(DATA_PIN, CLK_PIN, CS_PIN, NUM_DEVICES, INTENSITY);

int delaytime = 50;
char string1[] = "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z ";
char string2[] = "a b c d e f g h i j k l m n o p q r s t u v w x y z ";
char string3[] = "0 1 2 3 4 5 6 7 8 9 - = ";
char string4[] = "! @ # $ % ¨ & * ( ) _ + ";
char string5[] = "' , . ; ~ ] ´ [ | < > : ^ } ` { / ?  ";
char *theString[] = {string1,string2,string3,string4,string5};

void setup()
{
}

void loop()
{

    // Let the LEDs turned on one by one.
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            for (int address = 0; address < NUM_DEVICES; address++)
            {
                ledMtrx.setLed(address, row, col, true);
                delay(delaytime);
            }
        }
    }
    // Let the LEDs turned Off one by one.
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            for (int address = 0; address < NUM_DEVICES; address++)
            {
                ledMtrx.setLed(address, row, col, false);
                delay(delaytime);
            }
        }
    }

    
    // Check for Charachters 
    for (int address = 0; address < NUM_DEVICES; address++)
    {
        for (int stringNum = 0; stringNum < 5 ; stringNum++) {
            for (int i = 0; theString[stringNum][i] != '\0'; i++) {
            ledMtrx.setChar(address, theString[stringNum][i]);
            delay(delaytime*10);
            }
        }
    }
}
