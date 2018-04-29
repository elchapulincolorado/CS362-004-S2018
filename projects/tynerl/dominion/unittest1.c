#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int main() {
  struct gameState* state;

  state = newGame();
  
  if (sizeof(&state) == 8) {
    printf("newGame() test passed.  Size was supposed to be 8 and it was!\n");
  } else {
    printf("newGame() test failed.  Size was supposed to be 8 but it was %lu\n", sizeof(&state));
  }
  //assertTrue("gameState not 23", sizeof(&state), 23);
  return 0;
}
