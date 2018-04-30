#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int main() {
  struct gameState state;
  int result;
  state = *newGame();
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
         sea_hag, tribute, smithy};
  initializeGame(2, k, 23, &state);

  // just initialized game,  shouldn't be over
  result = isGameOver(&state);
  if (result == 0) {
    printf("isGameOver() just initialized test passed.  Game should not be over and it wasn't!\n");
  } else {
    printf("isGameOver() just initialized test failed.  Game should not be over and it was\n");
  }

  state.supplyCount[province] = 0;
  result = isGameOver(&state);
  if (result == 1) {
    printf("isGameOver() no provinces test passed.  Game should have been over and it was!\n");
  } else {
    printf("isGameOver() no provinces test failed.  Game should have been over and it wasn't\n");
  }

  // Prevent provinces from being a reason for being over
  state.supplyCount[province] = 1;

  // game should be over if any 3 supply piles are empty
  state.supplyCount[0] = 0;
  state.supplyCount[1] = 0;
  state.supplyCount[2] = 0;
  result = isGameOver(&state);
  if (result == 1) {
    printf("isGameOver() three empty piles test passed.  Game should have been over and it was!\n");
  } else {
    printf("isGameOver() three empty piles test failed.  Game should have been over and it wasn't\n");
  }
}
