#include "sharedVars.h"
#include <stdio.h>
#include <stdbool.h>

//Moje promenljive

//Promenljive koje cuvaju velicinu prozora
float window_height; //visina
float window_width; //sirina




//Energija naseg igraca, 100 je maksimalna vrednost


bool just_started = true;
bool crashed = false;

//promenljive koje cuvaju poziciju igraca
 float playerPosX = 2.5;
 float playerLength = 0.1; //sirina lopte
 float lengthOfRoad = 1.5;
 float playerPosZ = -5; 
 float playerStepBackwards = -0.6;
 float playerStepForward = 0.6;

//pomocne promenjive za prepreke hehe
 //jasno je da su sve tri trake uvek iste u X osi, odnosno, da prepreka u X osi (npr) u levoj traci nikad nece da se menja, vec samo po Z

// gde u kojoj su traci zidovi, odnosno gde se nalaze na x osi
 float leftWallPosX = 2;
 float midWallPosX = 2.5;
 float rightWallPosX = 3;
// niz zidova za svaku traku
 float *leftWallniz;
 float *midWallniz;
 float *rightWallniz;
// u kojoj su traci novcici
 float leftCoinPosX = 2;
 float midCoinPosX = 2.5;
 float rightCoinPosX = 3;
// nizovi koji cuvaju gde se nalaze novcici po trakama
 float *leftCoinniz;
 float *midCoinniz;
 float *rightCoinniz;
 //posto imam probleme sa score, odnosno lopta mi ide prebrzo i funkcija is_coin_collected ne stize da obradi sta treba
 //ubacujem 3 nova niza da vide da li je lopta vec prosla taj konkretni coin
 bool *leftCoinbool;
 bool *midCoinbool;
 bool *rightCoinbool;

 int brojacZaPut = 0;
 int brojacZaCoins = 0;

 float move = 0.1; //brzina kojom se krece
 float wallLaps = 0; //kada prodje vecina zidova, transliracemo ih opet nazad gde im je mesto. Necemo generisati nove.
 int pauseStart = 0; //kada je ova promenjiva % 2 == 1 onda treba da bude animation_ongoing = true, u suprotnom se pauzira.



 //animation parametar
 bool animation_ongoing = true;



 //kamera 
 float cameraOffsetX = 0.2;
 float cameraOffsetY = 1;


 float dnFPS = 1000; //koristimo ga u on_timer pozivu za kontrolu frejmova po sekundi


 //bool promenljive za kretanje
 bool pressed_a = false;
 bool pressed_d = false;

 //fullscreen
 bool fullscreen = true;


//Da li je igra restartovana
bool has_been_restarted = true;

 //Score
 int score = 0;
