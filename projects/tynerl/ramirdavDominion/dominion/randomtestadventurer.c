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

int checkAdventurerCard(int drawntreasure, struct gameState *post, int p, int* temphand) {
  int r;
  r = adventurerFunction(post, p);
  assert (r == 0);
}

int main () {
  int i, n, r, p, deckCount, discardCount, handCount;
  int randSize = 6;
  int randTreas[6] = {-5, -1, -0, 1, 2, 5};
  srand(time(NULL));

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState G;

  printf ("Testing adventurerEffect.\n");
  SelectStream(2);
  PutSeed(3);
  int tempHand[3];
  for (n = 0; n < 2000; n++) {
    initializeGame(2, k, 23, &G);
    p = floor(Random() * 2);
    G.deckCount[p] = floor(Random() * MAX_DECK);
    G.discardCount[p] = floor(Random() * MAX_DECK);
    G.handCount[p] = floor(Random() * MAX_HAND);
    checkAdventurerCard(randTreas[rand() % randSize], &G, p, tempHand);
  }

  printf ("ALL TESTS OK\n");

  exit(0);
}
