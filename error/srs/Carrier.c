#include <stdlib.h>
#include <stdio.h>

#include "Carrier.h"

void makeCarrier(int *ship, int ID, int damage, int  health, int shield, int regenerateShieldRate){
  /* passes on Carrier Air Ship attributes and creates an Interceptor attribute */
  makeProtossShip(ship, ID, CARRIER, damage, health, shield, regenerateShieldRate);
  ship[SHIP_CARRIER_INTERCEPTORS_NUMBER] = MAX_INTERCEPTORS; /* number of interceptors */
}

void carrierAttack(int *ship, Vector *terranFleet){
  /* operates the Carrier Air Ship attack */

  int *damagedShip;
  int attacks;

  for(attacks = 0; attacks < ship[SHIP_CARRIER_INTERCEPTORS_NUMBER]; attacks++){

    damagedShip = vectorBack(terranFleet);

    damageTerranShip(damagedShip, ship[SHIP_DAMAGE]);

    if(shipDestroyed(damagedShip)) {
      printf("Carrier with ID: %d killed enemy airship with ID: %d\n", ship[SHIP_ID], damagedShip[SHIP_ID]);
      free(damagedShip);

      if(!damagedShip){
        fprintf(stderr, "The memory for damaged terrain ship is not emptied correctly!\n");

        exit(EXIT_FAILURE);
        }

      vectorPop(terranFleet);

      if(vectorIsEmpty(terranFleet)){ /* enemy fleet is all wiped out */
        return;
      }
    }
  }
}

void checkCarrierShield(int *ship){
  /* decreases interceptors to 4 if shield rate is 0 or less */
  if (ship[SHIP_HEALTH] < CARRIER_HEALTH) {
    ship[SHIP_CARRIER_INTERCEPTORS_NUMBER] = DAMAGED_STATUS_INTERCEPTORS; /* number of interceptors */
  }
}