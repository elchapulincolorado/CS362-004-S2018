#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int main() {
  struct gameState state;
  state = *newGame();

  size_t stateSize = sizeof(state);
  if (stateSize == 26300) {
    printf("newGame() test passed.  Size was supposed to be 26300 and it was!\n");
  } else {
    printf("newGame() test failed.  Size was supposed to be 26300 but it was %lu\n", stateSize);
  }

  return 0;
}
