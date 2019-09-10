#include "callback.h"
#include "sharedVars.h"
#include "model.h"


void set_callback(void) {
    setKeyboardFunc(); //iz keyboard.h
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);
    glutTimerFunc(1000/dnFPS, on_timer, 0);
}



void on_display(void) {
    //cistimo bafere
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Podesava se viewport
    glViewport(0, 0, window_width, window_height);

    // Podesava se projekcija. 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
  //  gluPerspective(60, window_width/(float)window_height,1,-1.5); 
     gluPerspective(60, window_width/(float)window_height, 0.7, 10);

    // Podesava se vidna tacka
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();   
    //podesavamo gde ce nam kamera gledati, ondnosno iz koje pespektive
    gluLookAt(1.2, 0.5, playerPosZ+2, 1.2, 0, playerPosZ+1, 0, 1, 0);
/*    gluLookAt(1, 0.5, 3, 1, 0, 0, 0, 1, 0);
*/
    srand(time(NULL));
    glColor3f(1,0,0);
    
    // Skaliramo sve za koeficijent, po svim osama, u ovom slucaju ne skaliramo, ali ipak cu ostaviti da mi bude lakse kasnije da ne razmisjljam
    glScalef(1, 1, 1);
   	
   	//Iscrtavamo igraca
   	drawPlayerModel((float)(playerPosX / 2), playerPosZ);
    drawCoins();
    if(is_coin_collected()) {
      score += 1; 
    }
    drawWall();
    drawTunel();
    drawTheets();
    drawRoad();
      if(is_crashed()) {
      animation_ongoing = false;
      crashed = true;
    }
   //ispisujemo skor  
    writeScore();




   glutSwapBuffers();
}




void on_timer(int value) {  




  if(animation_ongoing) {


   if((int)playerPosZ % 298 == 0){
      return_coin_bools_to_false();
    }
   

   if((int)playerPosZ % 300 == 0){
      wallLaps = playerPosZ;
    }


    // simulira se kretanje lopte po z osi, odnosno ona se tom brzinom krece po putu
    playerPosZ -= move;


    if((int)playerPosZ % 50 == 0){
      move = move + 0.003;
    }

    //if((int)playerPosZ % 20 == 0)
     // generateMoreRoad();

    if(pressed_a) {
       //Ako pritisnemo 'a' zelimo da igrac skrene u levo
     printf("Skreces levo a trenutna pozicija ti je %f\n", playerPosX);
     if(canMoveThisWay('a')) 
        playerPosX += playerStepBackwards;

      pressed_a = false;
      printf("Skrenuo si  levo a trenutna pozicija ti je %f\n\n", playerPosX);
    }
    else if(pressed_d) {
      printf("Skreces desno a trenutna pozicija ti je %f\n", playerPosX);
       //Ako pritisnemo 'd' zelimo da igrac skrene u desno
      if(canMoveThisWay('d'))
          playerPosX += playerStepForward;

      pressed_d = false;
      printf("Skrenuo si desno a trenutna pozicija ti je %f\n\n", playerPosX);
    }  
	}
  
  glutPostRedisplay(); //nanovo ucitavamo prozor u odredjenim intervalima
  glutTimerFunc(1000/dnFPS, on_timer, 0); //podesili smo funkciju on_timer da sama sebe poziva  
  
}





void on_reshape(int width, int height) {
 //Postavlja se viewport. 
  glViewport(0, 0, width, height);

  /* Postavljaju se parametri projekcije. */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, (float) width / height, 1, 1500);

  window_width = width;
  window_height = height;
}




