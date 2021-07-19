#include "BattleField.h"
#include "Defines.h"
#include "Vector.h"

void generateTerranFleet(BattleField *battleField, const char *terranFleetStr){
  /* generates Terran ships and pushes them into a vector, holding the Terran fleet */

  size_t capacity;
  int *ship;
  size_t i;
  
  capacity = strlen(terranFleetStr);

  vectorInit(&battleField->terranFleet, capacity);

  for(i = 0; i < capacity; i++){
    if (terranFleetStr[i] == 'b'){
      ship = malloc(BATTLE_CRUSER_ARRAY_SIZE * sizeof(int));
      makeBattleCruiser(ship, i, BATTLE_CRUSER_DAMAGE, BATTLE_CRUSER_HEALTH);
      vectorPush(&battleField->terranFleet, ship);
    }else if(terranFleetStr[i] == 'v'){
      ship = malloc(VIKING_ARRAY_SIZE * sizeof(int));
      makeViking(ship, i, VIKING_DAMAGE, VIKING_HEALTH);
      vectorPush(&battleField->terranFleet, ship);
    }
  }
}

void generateProtossFleet(BattleField *battleField, const char *protossFleetStr){
  /* generates Protoss ships and pushes them into a vector, holding the Protoss fleet */

  size_t capacity;
  int *ship;
  size_t i;
  
  capacity = strlen(protossFleetStr);

  vectorInit(&battleField->protossFleet, capacity);

  for(i = 0; i < capacity; i++) { 
    if (protossFleetStr[i] == 'c') {
      ship = malloc(CARRIER_ARRAY_SIZE * sizeof(int));
      makeCarrier(ship, i, CARRIER_DAMAGE, CARRIER_HEALTH, CARRIER_SHIELD, CARRIER_SHIELD_REGENERATE_RATE);
      vectorPush(&battleField->protossFleet, ship);
    }else if (protossFleetStr[i] == 'p'){
      ship = malloc(PHOENIX_ARRAY_SIZE * sizeof(int));
      makePhoenix(ship, i, PHOENIX_DAMAGE, PHOENIX_HEALTH, PHOENIX_SHIELD, PHOENIX_SHIELD_REGENERATE_RATE);
      vectorPush(&battleField->protossFleet, ship);
    }
  }
}

void startBattle(BattleField *battleField) {
  /* processes turns until a fleet is defeated */
  while (true) {
    if (processTerranTurn(battleField)) {
      printf("TERRAN has won!\n");
      break;
    }

    if (processProtossTurn(battleField)) {
      printf("PROTOSS has won!\n");
      break;
    }
  }
}

void deinit(BattleField *battleField){
  /* frees dynamic allocated memory */

  int *ship;
  size_t numShips;  
  size_t i;
  
  numShips = vectorGetSize(&battleField->terranFleet); 

  for(i = 0; i < numShips; i++) {
    ship = vectorGet(&battleField->terranFleet, i);
    free(ship);
  } 

  numShips = vectorGetSize(&battleField->protossFleet); 

  for(i = 0; i < numShips; i++) { 
    ship = vectorGet(&battleField->protossFleet, i);
    free(ship);
  }

  vectorFree(&battleField->terranFleet);
  vectorFree(&battleField->protossFleet); 
}

bool processTerranTurn(BattleField *battleField){
  /* manages the Terran fleet attack and returns true if Protoss fleet is defeated */

  int *ship;
  int *lastShip;
  bool fleetDestroyed;
  size_t numShips;
  size_t i;
  
  numShips = vectorGetSize(&battleField->terranFleet);

  for(i = 0; numShips > i; i++){
    
    ship = vectorGet(&battleField->terranFleet, i);

    if(ship[SHIP_TYPE] == VIKING) {
      vikingAttack(ship, &battleField->protossFleet);
    }else {
      battleCruserAttack(ship, &battleField->protossFleet);
      ship[YAMATO_CANNON_LOADING_TURNS]++; /* yamato counter++ */
    }
  
    fleetDestroyed = vectorIsEmpty(&battleField->protossFleet);

    if (fleetDestroyed){
      return true;
    }
  }

  lastShip = vectorBack(&battleField->protossFleet);
  printf("Last Protoss AirShip with ID: %d has %d health and %d shield left\n", lastShip[SHIP_ID], lastShip[SHIP_HEALTH], lastShip[SHIP_SHIELD]);
  return false;
}

bool processProtossTurn(BattleField *battleField){
  /* manages the Protoss fleet attack and returns true if Terran fleet is defeated */

  int *ship;
  int *lastShip;
  bool fleetDestroyed;
  size_t numShips;
  size_t i;
  
  numShips = vectorGetSize(&battleField->protossFleet);

  for(i = 0; numShips > i; i++){

    ship = vectorGet(&battleField->protossFleet, i);

    if (ship[SHIP_TYPE] == PHOENIX) {
      phoenixAttack(ship, &battleField->terranFleet);
    } else {
      carrierAttack(ship, &battleField->terranFleet);
    }
    
    ship[SHIP_SHIELD] += ship[SHIP_REGENERATE_SHIELD_RATE]; /* shield regeneration */
    if (ship[SHIP_SHIELD] > ship[SHIP_INITIAL_SHIELD]){ /* top up shield but don't overfill it */
      ship[SHIP_SHIELD] = ship[SHIP_INITIAL_SHIELD]; 
    }

    fleetDestroyed = vectorIsEmpty(&battleField->terranFleet);

    if (fleetDestroyed){
      return true;
    }
  }

  lastShip = vectorBack(&battleField->terranFleet);
  printf("Last Terran AirShip with ID: %d has %d health left\n", lastShip[SHIP_ID], lastShip[SHIP_HEALTH]);
  return false;
}
