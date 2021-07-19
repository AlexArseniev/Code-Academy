#ifndef CARRIER_H_
#define CARRIER_H_

#include "Defines.h"
#include "Vector.h"
#include "ProtossAirShip.h"
#include "TerranAirShip.h"
#include "AirShip.h"

  /* passes on Carrier Air Ship attributes and creates an Interceptor attribute */
void makeCarrier(int *ship, int ID, int damage, int  health, int shield, int regenerateShieldRate);

  /* operates the Carrier Air Ship attack */
void carrierAttack(int *ship, Vector *terranFleet);

  /* decreases interceptors to 4 if shield rate is 0 or less */
void checkCarrierShield(int *ship);

#endif /* CARRIER_H_ */