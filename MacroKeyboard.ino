#include "Keyboard.h"

// Right now our "keyboard" has one key
#define KEY_LEFT 3 //Red Button Left
#define KEY_MIDDLE 4 //White Button Middle right
#define KEY_RIGHT 5 //Blue Button right

void setup() {  
  pinMode(KEY_LEFT, INPUT_PULLUP);
  pinMode(KEY_MIDDLE, INPUT_PULLUP);
  pinMode(KEY_RIGHT, INPUT_PULLUP);
  Keyboard.begin();
  
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
      if(KeyPressed(KEY_RIGHT)){          
          Mute_Windows();
      }else if(KeyPressed(KEY_LEFT)){
          Mute_Apple();        
      }
}

bool KeyPressed(int the_pin)
{
  if (digitalRead(the_pin) == LOW)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void Mute_Apple()
{
  //Apple command + d
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('d');
  delay(200);
  Keyboard.releaseAll();
}
void Mute_Windows()
{
  //Windows ctrl + d
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('d');
  delay(200);
  Keyboard.releaseAll();
 
}