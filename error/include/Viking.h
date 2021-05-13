#ifndef VIKING_H_
#define VIKING_H_

#include "Defines.h"
#include "Vector.h"
#include "TerranAirShip.h"
#include "ProtossAirShip.h"
#include "AirShip.h"
#include "Carrier.h"

  /* passes on Viking Air Ship attributes */
void makeViking(int *ship, int ID, int damage, int health);

  /* operates the Viking Air Ship attack */
void vikingAttack(int *ship, Vector *protossFleet);

#endif /* VIKING_H_ */