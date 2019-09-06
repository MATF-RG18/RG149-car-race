#ifndef UTILITY_H
#define UTILITY_H


#include <stdlib.h>
#include <GL/glut.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "callback.h"
#include "keyboard.h"
#include "sharedVars.h"

//Moje funkcije
bool canMoveThisWay(unsigned char key);
void setLighting();
void setMaterial(char* option);
void generateMoreRoad();
int is_crashed();
int is_coin_collected();
void return_coin_bools_to_false();
#endif 