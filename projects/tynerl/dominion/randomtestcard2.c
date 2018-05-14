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

int checkStewardCard(int choice1, int choice2, int choice3, struct gameState *post, int currentPlayer, int handPos) {
  int r;
  r = stewardEffect(choice1, choice2, choice3, post, currentPlayer, handPos);
  assert (r == 0);
}

int main () {
  int i, n, r, p, deckCount, discardCount, handCount;
  int randSize = 6;
  int randTreas[6] = {-5, -1, -0, 1, 2, 5};
  srand(time(NULL));

  int k[10] = {adventurer, council_room, steward, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState G;

  printf ("Testing stewardEffect.\n");
  SelectStream(2);
  PutSeed(3);
  for (n = 0; n < 2000; n++) {
    initializeGame(2, k, 23, &G);
    p = floor(Random() * 2);
    G.deckCount[p] = floor(Random() * MAX_DECK);
    G.discardCount[p] = floor(Random() * MAX_DECK);
    G.handCount[p] = floor(Random() * MAX_HAND);
    checkStewardCard(randTreas[rand() % randSize], randTreas[rand() % randSize], randTreas[rand() % randSize], &G, p, floor(Random() * MAX_HAND));
  }

  printf ("ALL TESTS OK\n");

  exit(0);
}
