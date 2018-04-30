#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int main() {
  // set up (not test)
  struct gameState state;
  int numCoins;
  state = *newGame();
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};
  initializeGame(2, k, 23, &state);
  int player = 0;
  // Hand is supposed to be randomly shuffled, so manually create it for testing
  state.handCount[player] = 5;
  state.hand[player][0] = copper;
  state.hand[player][1] = estate;
  state.hand[player][2] = copper;
  state.hand[player][3] = estate;
  state.hand[player][4] = copper;

  // actual test
  updateCoins(player, &state, 0);
  // test default number of coins
  numCoins = state.coins;
  if (numCoins == 3) {
    printf("updateCoins() initial hand test passed.  Number of coins was supposed to be 3 and it was!\n");
  } else {
    printf("updateCoins() initial hand test failed.  Size was supposed to be 3 but it was %d\n", numCoins);
  }

  // setup for another test
  state.hand[player][0] = copper;
  state.hand[player][1] = estate;
  state.hand[player][2] = silver;
  state.hand[player][3] = estate;
  state.hand[player][4] = gold;

  // actual test
  updateCoins(player, &state, 0);
  numCoins = state.coins;
  // cooper + silver + gold = 6
  if (numCoins == 6) {
    printf("updateCoins() all denominations test passed.  Number of coins was supposed to be 6 and it was!\n");
  } else {
    printf("updateCoins() all denominations test failed.  Size was supposed to be 6 but it was %d\n", numCoins);
  }

  updateCoins(player, &state, 5);
  numCoins = state.coins;
  // cooper + silver + gold + 5 = 11
  if (numCoins == 11) {
    printf("updateCoins() bonus specified test passed.  Number of coins was supposed to be 11 and it was!\n");
  } else {
    printf("updateCoins() bonus specified test failed.  Size was supposed to be 11 but it was %d\n", numCoins);
  }
}
