#include "keyboard.h"
#include "utility.h"
#include "sharedVars.h"
#include <unistd.h>

//predefinisane promenljive za dirke na tastaturi
#define ESCAPE 27




void setKeyboardFunc(void) {
  glutKeyboardFunc(on_keyboard);
  glutKeyboardUpFunc(on_release);
}


void on_keyboard(unsigned char key, int x, int y) {

  switch (key) {
    case ESCAPE:
        // Zavrsava se program.
        exit(EXIT_SUCCESS);
    break;

    case 'd':
    case 'D':
      if(animation_ongoing) {        
          pressed_d = true;
          //krecemo se na levu stranu ako mozemo
         
         //Zelimo da se ogranicimo od mogucnosti da se ubrzano krece.
           if(canMoveThisWay('d'))
               playerPosX += playerStepForward;
      }
    break;

    case 'a':
    case 'A':
       if(animation_ongoing) {        
        pressed_a = true;
        //krecemo se na levu stranu ako mozemo
       
       //Zelimo da se ogranicimo od mogucnosti da se ubrzano krece.
         if(canMoveThisWay('a'))
             playerPosX += playerStepBackwards;
        }
    break;

    case 'r':
    case 'R':
      has_been_restarted = true;
      animation_ongoing = true;
      crashed = false;
      playerPosZ = -5;
      playerPosX = 2.5;
      move = 0.1; 
      wallLaps = 0;
      score = 0;
      sleep(1);
    break;

    case 'p':
    case 'P':
      if(pauseStart % 2 == 0)
        animation_ongoing = false;
      else
        animation_ongoing = true;

      pauseStart++;
    break;
  }

}

void on_release(unsigned char key, int x, int y){
    //Radimo switch za nasu dugmad
    switch (key)
    {
        case 'a':
        case 'A':   
              pressed_d = false;
              break;
        case 'd':
        case 'D':
              pressed_a = false;
              break;
    }
}
