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
  int k[10] = {adventurer, minion, embargo, village, minion, mine, cutpurse,
         sea_hag, tribute, smithy};
  initializeGame(2, k, 23, &state);

  //int adventurerEffect(int drawntreasure, struct gameState *state, int currentPlayer, int* temphand)
  int origCoins = state.coins;
  state.hand[player][0] = minion;
  result = cardEffect(minion, 1, 0, 0, &state, 0, &bonus);
  if (result == 0) {
    printf("minion pass: minion card completed.\n");
  } else {
    printf("minion fail: minion card error\n");
  }

  // Choice 1 selected, coins should increase by 2
  if (state.coins == origCoins + 2) {
    printf("minion pass: minion option 1 success, 2 coins added.\n");
  } else {
    printf("minion fail: minion option 1 error wrong coins\n");
  }

  // option 2, coins shouldn't increase
  origCoins = state.coins;
  state.hand[player][0] = minion;
  result = cardEffect(minion, 0, 1, 0, &state, 0, &bonus);
  if (state.coins == origCoins) {
    printf("minion pass: minion option 2 success, no coins added.\n");
  } else {
    printf("minion fail: minion option 2 error amount of coins shouldn't have changed but they did.\n");
  }

  // option 2, hand count should be 4
  if (state.handCount[player] == 4) {
    printf("minion pass: minion option 2 success, hand count now 4.\n");
  } else {
    printf("minion fail: minion option 2 error. Hand count should be 4, but it is: %d.\n", state.handCount[player]);
  }
}
