/* -----------------------------------------------------------------------
* Title: cardtest3
* Author: James Ralstin
* Assignment: 3
* Due Date: 07/22/2018
* Description: This unit test is responsible for testing the card 
* implementation of steward in the implementation of dominion as provided
* for the course of CS362
* Term: Summer 2018
*
* Must include the following in the make file
* unittest1: cardtest3.c dominion.o rngs.o Assert.o
*      gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o Assert.o $(CFLAGS)
* -----------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include "Assert.h"
#include <assert.h>

void testSteward(struct gameState *G, int numPlayers, int handPos){
	
	int choice1 = 0, choice2 = 0, choice3 = 0;
	struct gameState prePlay;
	int result;
	
	memcpy(&prePlay, G, sizeof(struct gameState));//State of game before steward played
	
	printf("|---------------------------------CARD TEST 3.1: Verify choice 1, two cards drawn---------------------------------|\n\n");
	
	choice1 = 1;
	
	result = playSteward(G, 0, handPos, choice1, choice2, choice3);
	assert(result == 0);
	
	printf("Verify hand count increased by 1, expected value %d, actual value %d\n", prePlay.handCount[0] + 1, G->handCount[0]);
	Assert(prePlay.handCount[0] + 1, G->handCount[0], "==");
	printf("Verify deck count decreased by 2, expected value %d, actual value %d\n", prePlay.deckCount[0]-2, G->deckCount[0]);
	Assert(prePlay.deckCount[0] - 2, G->deckCount[0], "==");
	printf("Verify played card count increased by 1, expected value %d, actual value %d\n", prePlay.playedCardCount + 1, G->playedCardCount);
	Assert(prePlay.playedCardCount + 2, G->playedCardCount, "==");
	printf("Verify played card pile top card is steward, expected value 18, actual value %d\n", G->playedCards[G->playedCardCount-1]);
	Assert(steward, G->playedCards[G->playedCardCount-1], "==");
	printf("Verify no change to coins, expected value %d, actual value %d\n", prePlay.coins,G->coins);
	Assert(prePlay.coins, G->coins, "==");
	
	printf("\n|---------------------------------CARD TEST 3.2: Verify choice 2, plus 2 coins---------------------------------|\n\n");
	
	choice1 = 2;
	
	handPos = 3;
	
	//Replacing last position card with steward for player 0
	discardCard(handPos, 0, G, 0);	
	G->hand[0][handPos] = steward;
	G->handCount[0]++;
	G->supplyCount[steward]--;
	
	memcpy(&prePlay, G, sizeof(struct gameState));//State of game before steward played
	
	result = playSteward(G, 0, handPos, choice1, choice2, choice3);
	assert(result == 0);
	
	printf("Verify hand count decreased by 1, expected value %d, actual value %d\n", prePlay.handCount[0] - 1, G->handCount[0]);
	Assert(prePlay.handCount[0] - 1, G->handCount[0], "==");
	printf("Verify no change to deck count, expected value %d, actual value %d\n", prePlay.deckCount[0], G->deckCount[0]);
	Assert(prePlay.deckCount[0] - 2, G->deckCount[0], "==");
	printf("Verify played card count increased by 1, expected value %d, actual value %d\n", prePlay.playedCardCount + 1, G->playedCardCount);
	Assert(prePlay.playedCardCount + 1, G->playedCardCount, "==");
	printf("Verify played card pile top card is steward, expected value 18, actual value %d\n", G->playedCards[G->playedCardCount-1]);
	Assert(18, G->playedCards[G->playedCardCount-1], "==");
	printf("Verify coins increased by 2, expected value %d, actual value %d\n", prePlay.coins + 2,G->coins);
	Assert(prePlay.coins + 2, G->coins, "==");
	
	printf("\n|---------------------------------CARD TEST 3.3: Verify choice 3, discard 2 cards---------------------------------|\n\n");
	
	//Need to initialize a sensible hand in order to verify function choice 3
	choice1 = 3;
	handPos = 4;
	
	G->hand[0][3] = estate;
	G->hand[0][handPos] = steward;
	G->supplyCount[estate]--;
	G->supplyCount[steward]--;
	
}

int main (){

	//initialize game
	struct gameState testState, prePlay;
	int seed = 900;
	int numPlayers = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, sea_hag};
	int result, handPos;
	
	handPos = 4;
	
	memset(&testState, 0, sizeof(struct gameState));
	
	result = initializeGame(numPlayers, k, seed, &testState);
	assert(result == 0);
	
	//Replacing last position card with steward for player 0
	discardCard(handPos, 0, &testState, 0);	
	testState.hand[0][handPos] = steward;
	testState.handCount[0]++;
	testState.supplyCount[steward]--;
	
	//Print header for test
	printf("\n|------------------------------------------------------------------CARD TEST 3: \"steward\" START------------------------------------------------------------------|\n");
	printf("\n**Initialized values for game\n**Kingdom Cards: adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, sea_hag\n**Number of players: %d\n**Seed: %d\n\n", testState.numPlayers, seed);

	testSteward(&testState, numPlayers, handPos);
	
	printf("\n|------------------------------------------------------------------CARD TEST 3: \"steward\" FINISH-----------------------------------------------------------------|\n\n");
	
return 0;
}
