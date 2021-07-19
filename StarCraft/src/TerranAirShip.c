#include "TerranAirShip.h"

void makeTerranShip(int *ship, int ID, int type, int damage, int health){
  /* passes on Terran Air Ship attributes */
  makeShip(ship, ID, type, damage, health);
}

void damageTerranShip(int *ship, int damage){
  /* subtracts Protoss damage from Terran health rate */
  ship[SHIP_HEALTH] -= damage;
}