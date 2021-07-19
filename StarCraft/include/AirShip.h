#ifndef AIRSHIP_H_
#define AIRSHIP_H_

#include "Defines.h"
#include <stdbool.h>

  /* creates an array of Air Ship attributes */
void makeShip(int *ship, int ID, int type, int damage, int health);
  /* return true if health is 0 or less */
bool shipDestroyed(int *ship);

#endif /* AIRSHIP_H_ */
