
/*  Keypad 2x16 LCD example on Adruino mega 2560  */
 
/* Arduino pin - keypad pin (top side view) */
/*     5               1                    */
/*     6               2                    */
/*     7               3                    */
/*     8               4                    */
/*     2               5                    */
/*     3               6                    */
/*     4               7                    */



/* 2x16 LCD to Arduino 2560 pins            */                            
/* LCD RS pin to digital pin 12             */
/* LCD Enable pin to digital pin 11         */
/* LCD D4 pin to digital pin 53             */
/* LCD D5 pin to digital pin 52             */
/* LCD D6 pin to digital pin 51             */
/* LCD D7 pin to digital pin 50             */
/* LCD R/W pin to ground                    */
/* 10K resistor                             */
/* ends to +5V and ground                   */
/* wiper to LCD VO pin (pin 3)              */


#include <Keypad.h>
#include <LiquidCrystal.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
   {'1','2','3'},
   {'4','5','6'},
   {'7','8','9'},
   {'*','0','#'}
};
 byte rowPins[ROWS] = {5, 6, 7, 8}; //connect to the row pinouts of the keypad
 byte colPins[COLS] = {2, 3, 4}; //connect to the column pinouts of the keypad

 Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

   // initialize the library with the numbers of the interface pins
   LiquidCrystal lcd(12, 11, 53, 52, 51, 50);

   int cursorColumnCount = 0;  //Counts the number of key characters sent to the display.

void setup(){
   // set up the LCD's number of columns and rows:
   lcd.begin(16, 2);
   
   Serial.begin(9600);
   lcd.clear();         //Clear the display and return cursor to top left.
   lcd.cursor();
}

void loop(){
   char key = keypad.getKey();

   if (key != NO_KEY){
      if (cursorColumnCount > 15){    //If cursor reaches end of line on LCD set it back to top left.
          lcd.clear();
          cursorColumnCount = 0;
      }
      lcd.print(key);          //Output to LCD display.
      Serial.println(key);
      cursorColumnCount++;     //Keep track of number of characters sent to the display.
   }
}
