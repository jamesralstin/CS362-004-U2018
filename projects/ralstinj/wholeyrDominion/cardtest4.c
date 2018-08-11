/* -----------------------------------------------------------------------
* Title: cardtest4
* Author: James Ralstin
* Assignment: 3
* Due Date: 07/22/2018
* Description: This unit test is responsible for testing the card 
* implementation of adventurer in the implementation of dominion as provided
* for the course of CS362
* Term: Summer 2018
*
* Must include the following in the make file
* unittest1: cardtest4.c dominion.o rngs.o Assert.o
*      gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o Assert.o $(CFLAGS)
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

void testAdventurer(struct gameState *G){

	int preTreasureCount = 0, postTreasureCount = 0;
	struct gameState prePlay;
	int result, i;
	
	  
	memcpy(&prePlay, G, sizeof(struct gameState));
	  
	result = doAdventurerEffect(0, G);
	assert(result == 0);
	
	printf("|---------------------------------CARD TEST 4.1: General post state after played adventurer card---------------------------------|\n\n");
	
	printf("Verify hand count increased by 1, expected value %d, actual value %d\n", prePlay.handCount[0] + 1, G->handCount[0]);
	Assert(prePlay.handCount[0] + 1, G->handCount[0], "==");
	printf("Verify played card count increased by 1, expected value %d, actual value %d\n", prePlay.playedCardCount + 1, G->playedCardCount);
	Assert(prePlay.playedCardCount + 1, G->playedCardCount, "==");
	printf("Verify played card pile top card is adventurer, expected value 7, actual value %d\n", G->playedCards[G->playedCardCount-1]);
	Assert(adventurer, G->playedCards[G->playedCardCount-1], "==");

	printf("\n|---------------------------------CARD TEST 4.2: Verify two treasures added------------------------------------------------------|\n\n");
	
	//Get previous treasures
	for(i = 0; i < prePlay.handCount[0]; i++){
		
		if (prePlay.hand[0][i] == copper || prePlay.hand[0][i] == silver || prePlay.hand[0][i] == gold){
		
			preTreasureCount++;
		
		}
		
	}
	
	//Get new treasure
	for(i = 0; i < G->handCount[0]; i++){
		
		if (G->hand[0][i] == copper || G->hand[0][i] == silver || G->hand[0][i] == gold){
		
			postTreasureCount++;
		
		}
		
	}
	
	printf("Verifying two new treasures have been added, expected count %d, actual count %d\n", preTreasureCount + 2, postTreasureCount);
	Assert(preTreasureCount + 2, postTreasureCount, "==");

	printf("\n|---------------------------------CARD TEST 4.3: Only one treasure card exists in deck-------------------------------------------|\n\n");
	
	memcpy(&prePlay, G, sizeof(struct gameState));
	
	//Fill remaining deck with estate cards then add one copper
	for(i = 0; i < G->deckCount[0]; i++){
			G->deck[0][i] = estate;
	}
	//Set one copper into deck
	G->deck[0][0] = copper;
	
	memcpy(&prePlay, G, sizeof(struct gameState));
	
	result = doAdventurerEffect(0, G);
	assert(result == 0);
	
	preTreasureCount = 0;
	postTreasureCount = 0;
	
	//Get previous treasures
	for(i = 0; i < prePlay.handCount[0]; i++){
		
		if (prePlay.hand[0][i] == copper || prePlay.hand[0][i] == silver || prePlay.hand[0][i] == gold){
		
			preTreasureCount++;
		
		}
		
	}
	
	//Get new treasure
	for(i = 0; i < G->handCount[0]; i++){
		
		if (G->hand[0][i] == copper || G->hand[0][i] == silver || G->hand[0][i] == gold){
		
			postTreasureCount++;
		
		}
		
	}
	
	printf("Verifying one new treasures have been added, expected count %d, actual count %d\n", preTreasureCount + 1, postTreasureCount);
	Assert(preTreasureCount + 1, postTreasureCount, "==");
	
}

int main (){

	//initialize game
	struct gameState testState;
	int seed = 600;
	int numPlayers = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, sea_hag};
	int result, handPos;
	
	handPos = 4;
	
	memset(&testState, 0, sizeof(struct gameState));
	
	result = initializeGame(numPlayers, k, seed, &testState);
	assert(result == 0);
	
	//Replacing last position card with adventurer for player 0
	testState.hand[0][handPos] = adventurer;
	testState.supplyCount[adventurer]--;
	
	//Print header for test
	printf("\n|------------------------------------------------------------------CARD TEST 4: \"adventurer\" START------------------------------------------------------------------|\n");
	printf("\n**Initialized values for game\n**Kingdom Cards: adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, sea_hag\n**Number of players: %d\n**Seed: %d\n\n", testState.numPlayers, seed);
	
	testAdventurer(&testState);
	
	
	printf("\n|------------------------------------------------------------------CARD TEST 4: \"adventurer\" FINISH-----------------------------------------------------------------|\n\n");

return 0;
}
