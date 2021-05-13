#ifndef TERRANAIRSHIP_H_
#define TERRANAIRSHIP_H_

#include "Defines.h"
#include "AirShip.h"

  /* passes on Terran Air Ship attributes */
void makeTerranShip(int *ship, int ID, int type, int damage, int health);

  /* subtracts Terran damage from Protoss shield or health rate */
void damageTerranShip(int *ship, int damage);

#endif /* TERRANAIRSHIP_H_ */