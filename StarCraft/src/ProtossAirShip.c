#include "ProtossAirShip.h"

void makeProtossShip(int *ship, int ID, int type, int damage, int health, int shield, int regenerateShieldRate){
  /* passes on Protoss Air Ship attributes */
  makeShip(ship, ID, type, damage, health);
  ship[SHIP_SHIELD] = shield;
  ship[SHIP_REGENERATE_SHIELD_RATE] = regenerateShieldRate;
  ship[SHIP_INITIAL_SHIELD] = shield; // a copy to store initial shield rate
}

void damageProtossShip(int *ship,int damage){
  /* subtracts Terran damage from Protoss shield or health rate */
  ship[SHIP_SHIELD] -= damage;
  if (ship[SHIP_SHIELD] < 0) { // shield is destroyed
    ship[SHIP_HEALTH] += ship[SHIP_SHIELD];
    ship[SHIP_SHIELD] = 0;
  }
}