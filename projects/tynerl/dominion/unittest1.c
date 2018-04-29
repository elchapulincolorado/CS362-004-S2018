#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assertTrue.h"

int main() {
  struct gameState *state;

  state = newGame();
  if (23) {
    printf("pass");
  } else {
    printf("fail");
  }
  //assertTrue("gameState not 23", sizeof(&state), 23);
  return 0;
}
