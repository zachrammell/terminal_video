#include <stdio.h>
#include <windows.h>

#define KEYPRESSED -32768
#define LIMITSCANCODE 255

int kbhit(char *ch){
int i=0, keystate=0;
int exitFlag=0, ok=0;
char oldch=0;

  oldch = *ch;
  //Run through all key scancodes from 0 to 255
  do{
    keystate = GetAsyncKeyState(i);
    if (keystate == KEYPRESSED) {
            //A key has been pressed
            exitFlag = 1;
            ok=1;
    }
    if (i == LIMITSCANCODE) {
            //Exit if we got to the end
            exitFlag = 1;
            ok=0;
    }
    if (keystate == 0) i++; 
  } while(exitFlag != 1);
  //return key pressed
  *ch = i;
  if (*ch == oldch) {
   //Reset if we have the same value as before.
        ok = 0;
  }
  return ok;
}