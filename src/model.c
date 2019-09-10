#include "model.h"


void drawPlayerModel(float x, float z) {
  // ocito je da pravimo nasu loptu koja ce da se krece po putu.   
	setMaterial("player");
  
  glPushMatrix();
	glTranslatef(x, -0.5, z);
  glRotatef(playerPosZ*100, 1, 0, 0);
	glutWireSphere(playerLength, 10, 10);

  glPopMatrix();
	
}

void drawCoin(float x, float z) {

  setMaterial("coins");
  glPushMatrix();

  glTranslatef(x, -0.5, z);
  glRotatef(playerPosZ*100, 0, 1, 0);
  glutSolidSphere(playerLength, 12, 2);

  glPopMatrix();

}

void drawWall() {
 for(int j = 0; j< 500; j++){

      // dajemo neki random broj od 0 do 1 i ako je manji od 0.3 postojace prepreka u PRVOJ traci
      // zelim da se u startu iscrtaju prepreke zajedno sa linijama na putu, i da vec 10 unapred mogu da vidim da prepreka dolazi
      // a ne da se stvara odjednom i da nestaje dok lopta dolazi do nje kao sto se vidi na GIF-u
      if(brojacZaPut == 0){
        setWall();
        brojacZaPut = 1;
      }
      if(leftWallniz[j] != 0.0 && (int)leftWallniz[j] % 300 != 0){
        setMaterial("wall");
        glPushMatrix();
        glTranslatef((lengthOfRoad-0.9),-0.75, leftWallniz[j]+wallLaps);
        glScalef(lengthOfRoad/3 + 0.25, 0.85, 1);
        glutSolidCube(1);
        glPopMatrix();
      }

      if(midWallniz[j] != 0.0 && (int)midWallniz[j] % 300 != 0){
        setMaterial("wall");
        glPushMatrix();
        glTranslatef(1.22,-0.75, midWallniz[j]+wallLaps);
        glScalef(lengthOfRoad/3 - 0.085, 0.85, 1);
        glutSolidCube(1);
        glPopMatrix();
      }
  
      if(rightWallniz[j] != 0.0 && (int)rightWallniz[j] % 300 != 0){
        setMaterial("wall");
        glPushMatrix();
        glTranslatef(1.85,-0.75, rightWallniz[j]+wallLaps);
        glScalef(lengthOfRoad/3 + 0.1, 0.85, 1);
        glutSolidCube(1);
        glPopMatrix();
      }
  }
}





void setWall() {
  leftWallniz = calloc(500, sizeof(float));
  midWallniz = calloc(500, sizeof(float));
  rightWallniz = calloc(500, sizeof(float));

  if(leftWallniz == NULL || midWallniz == NULL || rightWallniz == NULL) {
    fprintf(stderr, "WALL inizijalizacija\n");
    exit(EXIT_FAILURE);
  }
  int i = 0, k = 0, l = 0;
  for(int j = 20; (float)j> -1000; j--){

      // dajemo neki random broj od 0 do 1 i ako je manji od 0.3 postojace prepreka u PRVOJ traci
      // zelim da se u startu iscrtaju prepreke zajedno sa linijama na putu, i da vec 10 unapred mogu da vidim da prepreka dolazi
      // a ne da se stvara odjednom i da nestaje dok lopta dolazi do nje kao sto se vidi na GIF-u
      if(((rand() % 10000) / 10000.0) < 0.3 && j%7 == 0) {
        leftWallniz[i] = j-23;
        i++;
      }


      //isto tako obradjujem srednju traku.
      if(((rand() % 10000) / 10000.0) < 0.33 && j%7 == 0) {
        midWallniz[k] = j-31;
        k++;
      }
      //prepreke na trecoj traci.
      if(((rand() % 10000) / 10000.0) < 0.3 && j%7 == 0) {
       rightWallniz[l] = j-27;
       l++;
      }
  }
}

void drawCoins() {
  for(int j = 0; j< 300; j++){
    if(brojacZaCoins == 0){
      setCoins();
      brojacZaCoins = 1;
    }
    if(leftCoinbool[j] == false && leftCoinniz[j] != 0.0)
      drawCoin(0.63, leftCoinniz[j] +wallLaps);

    if(midCoinbool[j] == false && midCoinniz[j] != 0.0)
      drawCoin(1.25, midCoinniz[j] +wallLaps);
    
    if(rightCoinbool[j] == false && rightCoinniz[j] != 0.0)
      drawCoin(1.85, rightCoinniz[j] +wallLaps);
    
  }

}


void setCoins() {
  leftCoinniz = calloc(300, sizeof(float));
  midCoinniz = calloc(300, sizeof(float));
  rightCoinniz = calloc(300, sizeof(float));

  leftCoinbool = malloc(300*sizeof(bool));
  midCoinbool = malloc(300*sizeof(bool));
  rightCoinbool = malloc(300*sizeof(bool));

  if(leftCoinniz == NULL || midCoinniz == NULL || rightCoinniz == NULL
    || leftCoinbool == NULL || midCoinbool == NULL || rightCoinbool == NULL) {
    fprintf(stderr, "Coins inizijalizacija\n");
    exit(EXIT_FAILURE);
  }

  for(int i=0; i< 300; i++){
    leftCoinbool[i] = false;
    midCoinbool[i] = false;
    rightCoinbool[i] = false;
  }

  int i = 0, k = 0, l = 0;
  for(int j = 20; (float)j> -1000; j--){

      // dajemo neki random broj od 0 do 1 i ako je manji od 0.3 postojace prepreka u PRVOJ traci
      // zelim da se u startu iscrtaju prepreke zajedno sa linijama na putu, i da vec 10 unapred mogu da vidim da prepreka dolazi
      // a ne da se stvara odjednom i da nestaje dok lopta dolazi do nje kao sto se vidi na GIF-u
      if(((rand() % 10000) / 10000.0) < 0.7 && j%7 == 0) {
        leftCoinniz[i] = j-23;
        i++;
      }


      //isto tako obradjujem srednju traku.
      if(((rand() % 10000) / 10000.0) < 0.8 && j%7 == 0) {
        midCoinniz[k] = j-31;
        k++;
      }
      //prepreke na trecoj traci.
      if(((rand() % 10000) / 10000.0) < 0.75 && j%7 == 0) {
       rightCoinniz[l] = j-27;
       l++;
      }
  }
}
    

void drawRoad(void) {
  float i = 0;
  int j;
  writeScore("score: ");
// Zamisljeno je kao sto vidite u GIF-u da postoje tri trake sirine 0.4 i dve razdelne linije sirine 0.1
// mozda Vam je od znacaja i da kamera prati Playera koji se krece po putu. 
  for(i = -0.5; i < 0.5; i+= 0.5) {

    setMaterial("road");
    //Iscrtavamo svaku traku zasebno
    glPushMatrix();
    glTranslatef((lengthOfRoad+i-0.05),-0.75, -240+playerPosZ+150);
    glScalef(lengthOfRoad, 0.3, 500);
    glutSolidCube(1);
    glPopMatrix();
    
    
    //iscrtavamo isprekidane linije po putu, izmedju traka
    for(j = 10; (float)j> -490; j--){

      

      //zelim da mi se crtice na putu iscrtavaju na svaka dva
      if(j%2 == 0) {
        setMaterial("lines");
        glPushMatrix();
        glTranslatef((lengthOfRoad+i), -0.75, j+wallLaps);
        glScalef(0.05, 0.32, 1);
        glutSolidCube(1);
        glPopMatrix();
      }
      else {
        setMaterial("road");
        glPushMatrix();
        glTranslatef((lengthOfRoad+i), -0.75, j+wallLaps);
        glScalef(0.05, 0.31, 1);
        glutSolidCube(1);
        glPopMatrix();
      }
    }

  }
}


void drawTunel() {
  for(int j = 10; (float)j> -490; j--){
  //hocu da iscrtam prsten oko puta, kao mini tunel.
      if(j%10 == 0) {
        setMaterial("tunel");
        glPushMatrix();

       /* //TREBA POGLEDATI KAKO DA ISECEM OVAJ TUNEL DA BUDE KAKO TREBA!
        double clip_plane[] = {0.9, 0.2, 0.1, 1.0};
        //double clip_plane1[] = {1, 0, 0, lengthOfRoad - 3};
        glClipPlane(GL_CLIP_PLANE0, clip_plane);
        glEnable(GL_CLIP_PLANE0);*/
       /* glClipPlane(GL_CLIP_PLANE1, clip_plane1);
        glEnable(GL_CLIP_PLANE1);*/
        glTranslatef((lengthOfRoad - 0.3),-0.75, j+wallLaps);
        glutSolidTorus(lengthOfRoad+5, 14, 30, 30);
        //glDisable(GL_CLIP_PLANE1);
       // glDisable(GL_CLIP_PLANE0);
        glPopMatrix();
      }
    }


}

void drawTheets() {
setMaterial("theets");  
glBegin(GL_TRIANGLES);
glColor3f(1, 1, 1);
glVertex3f( 2, 0.9, playerPosZ-2);
glVertex3f( 4, 0.9, playerPosZ-2);
glVertex3f(3, -0.2, playerPosZ-2);
glEnd();


glBegin(GL_TRIANGLES);
glColor3f(1, 1, 1);
glVertex3f(-1.5, 0.9, playerPosZ-2);
glVertex3f(0.5, 0.9, playerPosZ-2);
glVertex3f(-0.5, -0.2, playerPosZ-2);
glEnd();

}

    

void writeScore() {
    char *s = malloc(200 * sizeof(char));
    if(s == NULL) {
      fprintf(stderr, "writeScore\n");
      exit(EXIT_FAILURE);
    }  
    sprintf (s, "SCORE: %i!", score);

    setMaterial("score");  
    glRasterPos3f( 0.97, 0.3, playerPosZ-2);
    char * ch;
    for( ch = s; *ch; ch++ ) {
        glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, (int)*ch );
    }

    free(s);
}