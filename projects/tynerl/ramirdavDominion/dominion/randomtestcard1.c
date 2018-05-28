// Lowell Tyner
// Week 6
// Assignment 5
// Adapted from "testDrawCard.c" provided by the class repository.

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include "rngs.h"

int checkSmithyCard(int currentPlayer, int handPos, struct gameState *post) {
  int r;
  r = smithyFunction(currentPlayer, post, handPos);
  assert (r == 0);
}

int main () {
  int i, n, r, p, deckCount, discardCount, handCount;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState G;

  printf ("Testing smithyEffect.\n");
  SelectStream(2);
  PutSeed(3);
  int tempHand[3];
  int numPlayers = 2;
  for (n = 0; n < 2000; n++) {
    initializeGame(2, k, 23, &G);
    p = floor(Random() * 2);
    G.deckCount[p] = floor(Random() * MAX_DECK);
    G.discardCount[p] = floor(Random() * MAX_DECK);
    G.handCount[p] = floor(Random() * MAX_HAND);
    checkSmithyCard(p, floor(Random() * MAX_HAND), &G);
  }

  printf ("ALL TESTS OK\n");

  exit(0);
}
