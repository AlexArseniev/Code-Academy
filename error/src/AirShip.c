#include "AirShip.h"

void makeShip(int *ship, int ID, int type, int damage, int health){
  /* creates an array of Air Ship attributes */
  ship[SHIP_ID] = ID;
  ship[SHIP_TYPE] = type;
  ship[SHIP_DAMAGE] = damage;
  ship[SHIP_HEALTH] = health;
}

bool shipDestroyed(int *ship){
  /* return true if health is 0 or less */
  return ship[SHIP_HEALTH] <= 0;
}