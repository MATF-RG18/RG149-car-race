#ifndef MODEL_H
#define MODEL_H

#include <stdlib.h>
#include <GL/glut.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "callback.h"
#include "utility.h"
#include "sharedVars.h"


//Funkcija za iscrtavanje igraca
void drawPlayerModel(float x, float z);

//Funkcije za iscrtavanje podloge
void drawRoad();

void drawWall();
void drawCoins();
void setWall();
void setCoins();
void drawTunel();
//Ispisuje skor
void writeScore();

#endif