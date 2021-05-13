#include <stdio.h>
#include <stdlib.h>

#include "BattleField.h"

int main(void) {
  const int buffSize = 50;
  char terranFleet[buffSize];
  char protossFleet[buffSize];

  printf("Welcome to Starcraft!\nEnter Terran Fleet:\n\t- enter 'v' for Viking\n\t- enter 'b' for Battle Cruser\n");
  scanf("%s", terranFleet);

  printf("Enter Protoss Fleet:\n\t- enter 'c' for Carrier\n\t- enter 'p' for Phoenix\n");
  scanf("%s", protossFleet);

  BattleField battleField;
  generateTerranFleet(&battleField, terranFleet);
  generateProtossFleet(&battleField, protossFleet);
  startBattle(&battleField);
  deinit(&battleField);

  return EXIT_SUCCESS;
}