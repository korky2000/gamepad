//Boomy the Cat 2: Rise of Lynks
//Kalista Shields || March 2021
//CRT 360 Advanced Protyping
int curMode = -1;
#include "frame.h"
#include "screen.h"
#include "tiles.h"
#include "controls.h"
#include "interactions.h"
#include "status.h"
#include "hero.h"
#include "enemy.h"
#include "fight.h"
#include "modes.h"

void setup() {
  //randomSeed(analogRead(A9));
  Serial.begin(9600);
  initScreen();
 initControls();
 // initNeighbors();


}

void loop() {
getControls();
 runMode();
 checkFrame();
  
}
