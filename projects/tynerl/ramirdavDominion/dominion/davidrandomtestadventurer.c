//CS 362 Assignment 4
//Author: David Ramirez
//Date: 5/13/18

#include <string.h>
#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"


//Random Test 1: Adventurer card
//1. exactly 2 treasure cards should be added to player 1's hand after playing Adventurer card
//2. the discarded cards and the 2 treasure cards should come from player 1's supply pile
//3. check if no state change to kingdom/victory card piles


//Global Variables
struct gameState G;
struct gameState G2;
int passes = 0;
int fails = 0;
int handP = 0;
int treas;
int oldDeckCount;
int oldVictoryCount;
int oldKingdomCount;
int oldDiscardCount;



//checks the number of treasure cards in player 1's hand before playing Adventurer
void beforeTreasureCheck()
{
	treas = 0;
	int p = 0;
	for (p; p < G2.handCount[0]; p++) {
		
		if ((G2.hand[0][p] == gold) || (G2.hand[0][p] == silver) || (G2.hand[0][p] == copper)) {
			treas++;
		}
	}
	//printf("%d\n", treas);
}


/******************************************************************************************/
//test part 1: checks the number of treasure cards in player 1's hand after playing Adventurer
/******************************************************************************************/
void treasureTesting(int count)
{
	int treas2 = 0;
	//test that two treasures were drawn
	int k = 0;
	for (k; k < G2.handCount[0]; k++) {
		
		if ((G2.hand[0][k] == gold) || (G2.hand[0][k] == silver) || (G2.hand[0][k] == copper)) {
			treas2++;
		}
	}

	//printf("%d\n", treas2);
	//if there were 2 added treasure cards to the hand
	if (treas2 - treas == 2) {
		passes++;
		printf("Treasure Test # %d \npassed   \n     # players = %d, hand position = %d,  \n     # actions = %d, # buys = %d, # treasures = %d\n     p1 deck: %d, p1 discard: %d, p1 handpos: %d\n",count,G2.numPlayers, handP, G2.numActions, G2.numBuys, treas2-treas, oldDeckCount, oldDiscardCount, handP);
	}
	else {
		fails++;
		printf("Treasure Test # %d \nfailed   \n     # players = %d, hand position = %d,  \n     # actions = %d, # buys = %d, # treasures = %d\n     p1 deck: %d, p1 discard: %d, p1 handpos: %d\n",count,G2.numPlayers, handP, G2.numActions, G2.numBuys, treas2-treas, oldDeckCount, oldDiscardCount, handP);
	}
}


/******************************************************************************************/
//test part 2: compares the number of cards in the deck before and after playing Adventurer
/******************************************************************************************/
void deckTesting(int count)
{
	int numDiscarded = G2.discardCount[0] - oldDiscardCount;
    int newDeckCount = G2.deckCount[0];
    int totalFromDeck = numDiscarded + 2;       //the total number of cards from the deck should equal all discarded cards and 2 treasure cards
    int deckDiff = oldDeckCount - newDeckCount;

    if(totalFromDeck == deckDiff)
    {
		passes++;
        printf("Deck Test # %d \npassed   \n     # players = %d, hand position = %d,  \n     # actions = %d, # buys = %d,  deck diff = %d\n     p1 deck: %d, p1 discard: %d, p1 handpos: %d\n",count,G2.numPlayers, handP, G2.numActions, G2.numBuys, deckDiff, oldDeckCount, oldDiscardCount, handP);  
    }
    else
    {
		fails++;
        printf("Deck Test # %d \nfailed   \n     # players = %d, hand position = %d,  \n     # actions = %d, # buys = %d, deck diff = %d\n      p1 deck: %d, p1 discard: %d, p1 handpos: %d\n",count,G2.numPlayers, handP, G2.numActions, G2.numBuys, deckDiff, oldDeckCount, oldDiscardCount, handP);  
    }
}


/******************************************************************************************/
//test part 3: compares the number of victory and kingdom cards before and after playing Adventurer
/******************************************************************************************/
void victoryKingdomTesting(int count)
{
	int newKingdomCount = 0;
	int newVictoryCount = 0;
	int victoryChange;
	int kingdomChange;
	//count all victory cards after player 1 plays great_hall card
    newVictoryCount += G2.supplyCount[estate];
    newVictoryCount += G2.supplyCount[duchy];
    newVictoryCount += G2.supplyCount[province];

    //for each kingdom card, add the number in supply to the new kingdom card count (ie. after playing great_hall card)
    int m;
    for(m = adventurer; m <= great_hall; m++)
    {
        newKingdomCount += G2.supplyCount[m];
    }

    victoryChange = newVictoryCount - oldVictoryCount;
    kingdomChange = newKingdomCount - oldKingdomCount;

    //if there are no changes to the victory card and kingdom card supply then test passes
    if(victoryChange == 0 && kingdomChange == 0)
    {
		passes++;
		printf("Victory/Kingdom Card Test # %d \npassed   \n     # players = %d, hand position = %d, # actions = %d,\n     # buys = %d, victory change = %d, kingdom change: %d\n     p1 deck: %d, p1 discard: %d, p1 handpos: %d\n",count,G2.numPlayers, handP, G2.numActions, G2.numBuys,victoryChange,kingdomChange, oldDeckCount, oldDiscardCount, handP);  
    }
    else
    {
		fails++;
		printf("Victory/Kingdom Card Test # %d \nfailed   \n     # players = %d, hand position = %d, # actions = %d,\n     # buys = %d, victory change = %d, kingdom change: %d\n     p1 deck: %d, p1 discard: %d, p1 handpos: %d\n",count,G2.numPlayers, handP, G2.numActions, G2.numBuys,victoryChange,kingdomChange, oldDeckCount, oldDiscardCount, handP);  
		
    }
}


/******************************************************************************************/
//main test loop
/******************************************************************************************/
int main() {
	int testNum = 500000;		//number of times to run tests
	int bonus = 0;
	int seed = 1000;
	int numPlayers;
	int k[10] = {adventurer, great_hall, village, minion, mine, cutpurse,sea_hag, tribute, smithy, council_room}; //kingdom cards
	
	int i = 0;
	for (i; i < testNum; i++) {

		//randomization of players must be done before initialization
		numPlayers = rand() % (11 - 2) + 2;
		
		initializeGame(numPlayers, k, seed, &G);
		memcpy(&G2, &G, sizeof(struct gameState));


		/******************************************************************
		 *                          Randomization                         *
		 * ***************************************************************/
		//assign random number between 0 and 2 to number of actions
		G2.numActions = rand() % 3;
		//assign random number between 0 and 2 to number of buys
		G2.numBuys = rand() % 3;
		//randomly assign 0 or 1 to the outpost Played flag
		G2.outpostPlayed = rand() % 2;
		//Assign random number between 0 and handCount to hand position
		handP = rand() % (G2.handCount[0] + 1);
		//randomize deck count for each player (500 is max deck size)
		int h = 0;
		for (h; h < numPlayers; h++)
			G2.deckCount[h] = rand() % 501;
		//randomize discard count for each player (500 is max deck size)
		int g = 0;
		for (g; g < numPlayers; g++)
			G2.discardCount[g] = rand() % 501;

		/******************************************************************
		 *                        Setup for Tests                         *
		 * ***************************************************************/
		//Assign adventurer card to current hand position
		G2.hand[0][handP] = adventurer;
		//check treasure cards before playing Adventurer
		beforeTreasureCheck();
		//check deck count before playing Adventurer
		oldDeckCount = G2.deckCount[0];
		//check discard count before playing Adventurer
		oldDiscardCount = G2.discardCount[0];

		//set the victory/kingdom card count depending on number of players
		if (numPlayers == 2)
		{
			oldVictoryCount = 24;
			oldKingdomCount = 96;
		}
		else
		{	
			oldVictoryCount = 36;
			oldKingdomCount = 104;
		}
		
		/******************************************************************
		 *                          Play Card                             *
		 * ***************************************************************/
		//play Adventurer
		playCard(handP,-1, -1, -1, &G2);
	

		/******************************************************************
		 *                          Testing                               *
		 * ***************************************************************/
		//test for treasure card number
		treasureTesting(i);

		//test for deck count
		deckTesting(i);

		//test for victory/kingdom card number
		victoryKingdomTesting(i);

	}

	//output totals
	printf("Adventurer card random test results:\n     Passing Tests:%d\n     Failing Tests:%d\n\n\n\n", passes, fails);
    return 0;
}
