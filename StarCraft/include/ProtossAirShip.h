#ifndef PROTOSSAIRSHIP_H_
#define PROTOSSAIRSHIP_H_

#include "Defines.h"
#include "AirShip.h"

  /* passes on Protoss Air Ship attributes */
void makeProtossShip(int *ship, int ID, int type, int damage, int health, int shield, int regenerateShieldRate);

  /* subtracts Protoss damage from Terran health rate */
void damageProtossShip(int *ship,int damage);

#endif /* PROTOSSAIRSHIP_H_ */