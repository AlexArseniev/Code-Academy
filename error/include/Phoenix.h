#ifndef PHOENIX_H_
#define PHOENIX_H_

#include "Defines.h"
#include "Vector.h"
#include "ProtossAirShip.h"
#include "TerranAirShip.h"
#include "AirShip.h"

  /* passes on Phoenix Air Ship attributes */
void makePhoenix(int *ship, int ID, int damage, int  health, int shield, int regenerateShieldRate);

  /* operates the Phoenix Air Ship attack */
void phoenixAttack(int *ship, Vector *terranFleet);

#endif /* PHOENIX_H_ */