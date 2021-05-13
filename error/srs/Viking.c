#include <stdlib.h>
#include <stdio.h>

#include "Viking.h"

void makeViking(int *ship, int ID, int damage, int health){
  /* passes on Viking Air Ship attributes */
  makeTerranShip(ship, ID, VIKING, damage, health);
}

void vikingAttack(int *ship, Vector *protossFleet){
  /* operates the Viking Air Ship attack */
  int *damagedShip;
  int damageRate;

  damagedShip = vectorBack(protossFleet);
  damageRate = ship[SHIP_DAMAGE];

  if(damagedShip[SHIP_TYPE] == PHOENIX) { /* in case it is Phoenix */
    damageRate *= VIKING_DAMAGE_BONUS_AGAINST_PHOENIX;
  }

  damageProtossShip(damagedShip, damageRate);

  if(damagedShip[SHIP_TYPE] == CARRIER){ /* in case it is Carrier */
    checkCarrierShield(damagedShip);
  }

  if(shipDestroyed(damagedShip)){
    printf("Viking with ID: %d killed enemy airship with ID: %d\n", ship[SHIP_ID], damagedShip[SHIP_ID]);
    free(damagedShip);

    if(!damagedShip){
      fprintf(stderr, "The memory for damaged protoss ship is not emptied correctly!\n");

      exit(EXIT_FAILURE);
    }
    vectorPop(protossFleet);
  }
}
