#ifndef SHARED_VARS_H
#define SHARED_VARS_H

#include <stdio.h>
#include <stdbool.h> 

//Moje promenljive
float window_height; //visina
float window_width; //sirina




//Energija naseg igraca, 100 je maksimalna vrednost


bool just_started;
bool crashed;

//promenljive koje cuvaju poziciju igraca
 float playerPosX;
 float playerLength; //sirina lopte
 float lengthOfRoad;
 float playerPosZ; 
 float playerStepBackwards;
 float playerStepForward;


 float leftWallPosX;
 float midWallPosX;
 float rightWallPosX;
 // niz zidova za svaku traku
 float *leftWallniz;
 float *midWallniz;
 float *rightWallniz;

// u kojoj su traci novcici
 float leftCoinPosX;
 float midCoinPosX;
 float rightCoinPosX;
// nizovi koji cuvaju gde se nalaze novcici po trakama
 float *leftCoinniz;
 float *midCoinniz;
 float *rightCoinniz;

 bool *leftCoinbool;
 bool *midCoinbool;
 bool *rightCoinbool;

 int brojacZaPut;
 int brojacZaCoins;

 float move;
 float wallLaps;
 int pauseStart;
 //animation parametar
 bool animation_ongoing;



 //kamera 
 float cameraOffsetX;
 float cameraOffsetY;


 float dnFPS; //koristimo ga u on_timer pozivu za kontrolu frejmova po sekundi


 //bool promenljive za kretanje
 bool pressed_a;
 bool pressed_d;

 //fullscreen
 bool fullscreen;


//Da li je igra restartovana
bool has_been_restarted;

 //Score
 int score;


#endif