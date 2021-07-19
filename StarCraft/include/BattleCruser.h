#ifndef BATTLECRUISER_H_
#define BATTLECRUISER_H_

#include "Defines.h"
#include "Vector.h"
#include "TerranAirShip.h"
#include "ProtossAirShip.h"
#include "AirShip.h"
#include "Carrier.h"


/* passes on Battle Cruiser Air Ship attributes and creates Yamato Canon attribute */
void makeBattleCruiser(int *ship, int ID, int damage, int health);

/* operates the Battle Cruiser Air Ship attack */
void battleCruserAttack(int *ship, Vector *protossFleet);

#endif /* BATTLECRUISER_H_ */
