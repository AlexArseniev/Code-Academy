#ifndef BATTLEFIELD_H_
#define BATTLEFIELD_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BattleCruser.h"
#include "Carrier.h"
#include "Phoenix.h"
#include "Viking.h"

#include "Vector.h"

typedef struct {
  Vector terranFleet;
  Vector protossFleet;
} BattleField;

  /* generates Terran ships and pushes them into a vector, holding the Terran fleet */
void generateTerranFleet(BattleField *battleField, const char *terranFleetStr);
  /* generates Protoss ships and pushes them into a vector, holding the Protoss fleet */
void generateProtossFleet(BattleField *battleField, const char *protossFleetStr);

  /* processes turns until a fleet is defeated */
void startBattle(BattleField *battleField);

  /* frees dynamic allocated memory */
void deinit(BattleField *battleField);

  /* manages the Terran fleet attack and returns true if Protoss fleet is defeated */
bool processTerranTurn(BattleField *battleField);
  /* manages the Protoss fleet attack and returns true if Terran fleet is defeated */
bool processProtossTurn(BattleField *battleField);

#endif /* BATTLEFIELD_H_ */
