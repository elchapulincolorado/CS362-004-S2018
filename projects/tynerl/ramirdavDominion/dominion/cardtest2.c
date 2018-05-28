#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int main() {
  int result;
  int bonus = 0;
  int player = 0;
  struct gameState state;
  state = *newGame();
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
         sea_hag, tribute, smithy};
  initializeGame(2, k, 23, &state);

  //int adventurerEffect(int drawntreasure, struct gameState *state, int currentPlayer, int* temphand)

  state.hand[player][0] = adventurer;
  result = cardEffect(adventurer, 0, 0, 0, &state, 0, &bonus);
  if (result == 0) {
    printf("adventurer pass: adventurer card completed.\n");
  } else {
    printf("adventurer fail: adventurer card error\n");
  }
}
