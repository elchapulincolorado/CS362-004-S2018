#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int main() {
  int result;
  int player = 0;
  int bonus = 0;
  struct gameState state;
  state = *newGame();
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
         sea_hag, tribute, smithy};
  initializeGame(2, k, 23, &state);

  // to realistically play smithy, it must be in the player's hand
  state.hand[player][0] = smithy;
  //pre smithy check
  int origCount = state.handCount[player];

  result = cardEffect(smithy, 0, 0, 0, &state, 0, &bonus);
  if (result == 0) {
    printf("smithy pass: smithy card completed.\n");
  } else {
    printf("smithy fail: smithy card error\n");
  }

  // smithy has been played, expect card to be discarded
  if (state.hand[player][0] != smithy) {
    printf("smithy pass: Smithy card successfully discarded after being played.\n");
  } else {
    printf("smithy fail: Smithy card remained in hand after being played.  %d\n", state.hand[player][0]);
  }

  // smithy should add 3 to hand, then get discarded, so total count should be 7
  int diff = state.handCount[player] - origCount;
  if (diff == 2 ) {
    printf("smithy pass: smithy successfully increased hand size by 2 (add 3, discard smithy)\n");
  } else {
    printf("smithy fail: smithy was played, but handsize was not increased by 2 (add 3, discard smithy) but by: %d\n", diff);
  }
}
