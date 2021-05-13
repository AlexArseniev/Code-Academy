#include <stdio.h>
#include <stdlib.h>

#include "Phoenix.h"

void makePhoenix(int *ship, int ID, int damage, int  health, int shield, int regenerateShieldRate){
  /* passes on Phoenix Air Ship attributes */
  makeProtossShip(ship, ID, PHOENIX, damage, health, shield, regenerateShieldRate);
}

void phoenixAttack(int *ship, Vector *terranFleet){
  /* operates the Phoenix Air Ship attack */

  int *damagedShip;

  damagedShip = vectorBack(terranFleet);

  damageTerranShip(damagedShip, ship[SHIP_DAMAGE]);

  if(shipDestroyed(damagedShip)) {
    printf("Phoenix with ID: %d killed enemy airship with ID: %d\n", ship[SHIP_ID], damagedShip[SHIP_ID]);
    free(damagedShip);

    if(!damagedShip){
      fprintf(stderr, "The memory for damaged terrain ship is not emptied correctly!\n");

      exit(EXIT_FAILURE);
      }

    vectorPop(terranFleet);
  }
}