#include "BattleCruser.h"

void makeBattleCruiser(int *ship, int ID, int damage, int health){
  /* passes on Battle Cruiser Air Ship attributes and creates Yamato Canon attribute */
  makeTerranShip(ship, ID, BATTLE_CRUSER, damage, health);
  ship[YAMATO_CANNON_COUNTER] = 0; /* yamato strike counter */
}

void battleCruserAttack(int *ship, Vector *protossFleet){
  /* operates the Battle Cruiser Air Ship attack */

  int *damagedShip;
  int damageRate;
  
  damagedShip = vectorBack(protossFleet);
  damageRate = ship[SHIP_DAMAGE];

  if(ship[YAMATO_CANNON_COUNTER] == YAMATO_CANNON_LOADING_TURNS) { /* Time for a Yamato Cannon! */
    damageRate *= YAMATO_CANNON_DAMAGE_MODIFIER;
    ship[YAMATO_CANNON_COUNTER] = -1;
  }
  
  damageProtossShip(damagedShip, damageRate);

  if(damagedShip[SHIP_TYPE] == CARRIER){ /* in case it is Carrier */
    checkCarrierShield(damagedShip);
  }

  if(shipDestroyed(damagedShip)) {
    printf("BattleCruser with ID: %d killed enemy airship with ID: %d\n", ship[SHIP_ID], damagedShip[SHIP_ID]);
    free(damagedShip);
    vectorPop(protossFleet);
  }
}