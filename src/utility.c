#include "utility.h"
#include "sharedVars.h"
#include <stdio.h>
#include "model.h"




//Funkcija kojom cemo proveravati da li mozemo da se krecemo u nekom pravcu ili ne
bool canMoveThisWay(unsigned char key) {
    fflush(stdin);
    float playerCurrentPosition = playerPosX;
    if(key == 'a') {    	
    	if(playerCurrentPosition < 1.8)
    		return false;
    	else
    		return true;
    }
    if(key == 'd') {  //u switch sam stavio da moze i veliko D.
    	if(playerCurrentPosition > 3.2)
    		return false;
    	else
    		return true;
    }

    // //Ako ni jedan uslov nije ispunjen mi mozemo da se krecemo u tom pravcu pa vracamo FALSE
    return false;
}


void setLighting() {	
	//Podesavamo vektore
	GLfloat position [] = {10,10,10,1};
	GLfloat ambient  [] = {0.4,0.4,0.4,1};
	GLfloat diffuse  [] = {1,1,1,1};
	GLfloat specular [] = {1,1,1,1};

	//Inicijalizujemo osobine svetlosti koje zelimo i poziciju osvetljenja
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
}

//funkcija za generisanje novog puta.
void generateMoreRoad(){

}

int is_crashed() {
	int i;
	if(playerPosX < 2.4) {
		for(i=0; i<500; i++)
			if(leftWallniz[i] != 0.0 && (int)leftWallniz[i] % 300 != 0){
				if(playerPosZ <= leftWallniz[i]+wallLaps+0.7 && playerPosZ >= leftWallniz[i]+wallLaps-0.4){
					//printf("USAO U LEVU pozicija: %f\n", leftWallniz[i]+wallLaps);
					return 1;
				}
			}
	}
	else if(playerPosX == 2.5){
		for(i=0; i<500; i++){
			if(midWallniz[i] != 0.0 && (int)midWallniz[i] % 300 != 0){
				if(playerPosZ <= midWallniz[i]+wallLaps+0.7 && playerPosZ >= midWallniz[i]+wallLaps -0.4){
					//printf("USAO U SREDNJU koja je: %f\n", midWallniz[i]+wallLaps);
					return 1;
				}
			}
		}
	}
	else
		for(i=0; i<500; i++){
			if(rightWallniz[i] != 0.0 && (int)rightWallniz[i] % 300 != 0){
				if(playerPosZ <= rightWallniz[i]+wallLaps+0.7 &&playerPosZ >= rightWallniz[i]+wallLaps -0.4) {
					//printf("USAO U DESNU pozicija: %f\n", rightWallniz[i]+wallLaps);
					return 1;
				}
			}
		}
	return 0;
}
void return_coin_bools_to_false() {
for(int i=0; i< 300; i++){
    leftCoinbool[i] = false;
    midCoinbool[i] = false;
    rightCoinbool[i] = false;
  }
}

int is_coin_collected() {
	int i;
	if(playerPosX < 2.4) {
		for(i=0; i<300; i++)
			if(leftCoinniz[i] != 0.0 && leftCoinbool[i] == false){
				if(playerPosZ <= leftCoinniz[i]+wallLaps+0.3 && playerPosZ >= leftCoinniz[i]+wallLaps-0.2){
					//printf("USAO U LEVU pozicija: %f\n", leftCoinniz[i]+wallLaps);
					leftCoinbool[i] = true;
					return 1;
				}
			}
	}
	else if(playerPosX == 2.5){
		for(i=0; i<300; i++){
			if(midCoinniz[i] +wallLaps != 0.0 && midCoinbool[i] == false){
				if(playerPosZ <= midCoinniz[i]+wallLaps+0.3 && playerPosZ >= midCoinniz[i]+wallLaps -0.2){
					//printf("USAO U SREDNJU koja je: %f\n", midCoinniz[i]+wallLaps);
					midCoinbool[i] = true;
					return 1;
				}
			}
		}
	}
	else
		for(i=0; i<300; i++){
			if(rightCoinniz[i] != 0.0 && (int)rightCoinniz[i] % 300 != 0 && rightCoinbool[i] == false){
				if(playerPosZ <= rightCoinniz[i]+wallLaps+0.7 &&playerPosZ >= rightCoinniz[i]+wallLaps -0.4) {
					//printf("USAO U DESNU pozicija: %f\n", rightCoinniz[i]+wallLaps);
					rightCoinbool[i] = true;
					return 1;
				}
			}
		}
	return 0;
	
}




void setMaterial(char * option) {
	//putevi
	if(strcmp("road", option)==0) {
		//Podesavamo vektore
		GLfloat specular [] = {0,0,0,0};
		GLfloat ambient  [] = {0.305, 0.431, 0.411,1};
		GLfloat diffuse  [] = {0.301, 0.301, 0.301,1};
    	int shininess   = 100;

		//Inicijalizujemo osobine materijala
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess);
	}
	// linije na putevima
	else if(strcmp("lines", option)==0) {
		//Podesavamo vektore
		GLfloat specular [] = {0,0,0,0};
		GLfloat ambient  [] = {0.205, 0.231, 0.211,1};
		GLfloat diffuse  [] = {0.201, 0.201, 0.201,1};
    	int shininess   = 100;

		//Inicijalizujemo osobine materijala
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess);
	}
	// lopta!
	else if(strcmp("player", option)==0) {
		//Podesavamo vektore
		GLfloat specular [] = {0,0,1,0};
		GLfloat ambient  [] = {0,0,1,1};
		GLfloat diffuse  [] = {0.4,0.4,1,1};
	    int shininess   = 100;
		
		//Inicijalizujemo osobine materijala
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess);	
	}
	else if(strcmp("wall", option)==0)
	{
		//Podesavamo vektore
		GLfloat specular [] = {0,0,0,0};
		GLfloat ambient  [] = {0.909, 0.270, 0.552,0.9};
		GLfloat diffuse  [] = {0.909, 0.270, 0.552, 1};
    	int shininess   = 100;

		//Inicijalizujemo osobine materijala
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess);
	}
	else if(strcmp("coins", option)==0) {
		//Podesavamo vektore
		GLfloat specular [] = {0,0,0,0};
		GLfloat ambient  [] = {0.909, 0.870, 0.552,1};
		GLfloat diffuse  [] = {0.909, 0.870, 0.552,1};
    	int shininess   = 100;

		//Inicijalizujemo osobine materijala
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess);
	}
	else if(strcmp("tunel", option)==0) {
		//Podesavamo vektore
		GLfloat specular [] = {0,0,0,0};
		GLfloat ambient  [] = {0.1, 0.870, 0.1,0.7};
		GLfloat diffuse  [] = {0.1, 0.870, 0.1,0.9};
    	int shininess   = 100;

		//Inicijalizujemo osobine materijala
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess);
	}		
}

