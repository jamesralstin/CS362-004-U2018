/* -----------------------------------------------------------------------
* Title: unittest1
* Author: James Ralstin
* Assignment: 3
* Due Date: 07/22/2018
* Description: This unit test is responsible for testing the function of gainCard
* in the implementation of dominion as provided for the course of CS362
* Term: Summer 2018
*
* Must include the following in the make file
* unittest1: unittest1.c dominion.o rngs.o Assert.o
*      gcc -o unittest1 -g  unittest1.c dominion.o rngs.o Assert.o $(CFLAGS)
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

int testCardNotDealt(struct gameState *G, int player){
	
	int returnedVal;
	int toFlag = 0;
	
	printf("|---------------------------------UNIT TEST 1.1: Verify error on card not dealt (i.e. supply count = -1)---------------------------------|\n\n");
	
	//Pass card that was not a part of the initialized kingdom cards i.e. "steward"
	returnedVal = gainCard(18, G, toFlag, player);
	
	printf("Test scenario card not dealt \"steward\" position 18 in supply count, value equal to: %d\n\nExpected value from \"gainCard\": -1\nActual value from \"gainCards\": %d\n",G->supplyCount[18], returnedVal);
	
	//Verify returned value was -1
	Assert(returnedVal,-1,"==");
	printf("\n");
	
	return 0;
}

int testCardSupplyEmpty(struct gameState *G, int player){
	
	int returnedVal;
	int toFlag = 0;
	
	printf("|---------------------------------UNIT TEST 1.2: Verify error on card supply empty (i.e. supply count = 0)-------------------------------|\n\n");
	
	//Setting supply of a card to 0 to then verify the returned value is -1
	printf("Setting curse = 0\n\n");
	G->supplyCount[0] = 0;
	
	returnedVal = gainCard(0, G, toFlag, player);
	
	printf("Test scenario \"curse\" card supply empty, position 0 in supply count, value equal to: %d\n\nExpected value from \"gainCard\": -1\nActual value from \"gainCards\": %d\n",G->supplyCount[0], returnedVal);
	
	//Verify the returned value was -1
	Assert(returnedVal,-1,"==");
	printf("\n");
	
	returnedVal = 0;
	
	return returnedVal;
}

void testGainCard(struct gameState *G, int player){
	
	int i;
	int returnVal;
	int initialCount;
	int initialSupply;
	
	printf("|---------------------------------UNIT TEST 1.3: Verify gain card to discard, deck, and hand---------------------------------------------|\n\n");
	
	//For each of the card locations of hand, deck, and discard, use any card with a supply count greater than 0, i.e. kingdom card adventurer
	for(i = 0; i < 3; i++){
		
		initialSupply = G->supplyCount[7];
		
		switch(i){
			case 0:
				
				//Print test and get initial values of state
				printf("Add \"adventurer\" to discard\n");
				initialCount = G->discardCount[player];
				
				//Test increment of discard pile
				returnVal = gainCard(7, G, i, player);
				printf("Initial discard size %d, expected new discard size %d, actual new discard size %d\n", initialCount, initialCount + 1, G->discardCount[0]);
				Assert(G->discardCount[player], initialCount + 1, "==");
				
				//Test adventurer was added to discard pile
				printf("\nAdded card to discard expected value: 7, actual value: %d\n",G->discard[player][G->discardCount[player]-1]);
				Assert(G->discard[player][G->discardCount[player]-1], 7, "==");
				
				break;
				
			case 1:
			
				//Print test and get initial values of state
				printf("\nAdd \"adventurer\" to deck\n");
				initialCount = G->deckCount[player];
			
				//Test increment of deck
				returnVal = gainCard(7, G, i, player);
				printf("Initial deck size %d, expected new deck size %d, actual new deck size %d\n", initialCount, initialCount + 1,G->deckCount[0]);
				Assert(G->deckCount[player], initialCount + 1, "==");
				
				//Test adventurer was added to deck
				printf("\nAdded card to deck expected value: 7, actual value: %d\n",G->deck[player][G->deckCount[player]-1]);
				Assert(G->deck[player][G->deckCount[player]-1], 7, "==");
				
				break;
				
			default:
				
				//Print test and get initial values of state
				printf("\nAdd \"adventurer\" to hand\n");
				initialCount = G->handCount[player];
				
				//Test increment of hand
				returnVal = gainCard(7, G, i, player);
				printf("Initial hand size %d, expected new hand size %d, actual new hand size %d\n", initialCount, initialCount + 1,G->handCount[0]);
				Assert(G->handCount[player], initialCount + 1, "==");
				
				//Test adventurer was added to hand
				printf("\nAdded card to hand expected value: 7, actual value: %d\n",G->hand[player][G->handCount[player]-1]);
				Assert(G->hand[player][G->handCount[player]-1], 7, "==");
		
		}
		
		//Test decrement of adventurer supply
		printf("\nRemove adventurer card from supply, original count: %d, expected value: %d, actual value %d\n", initialSupply, initialSupply-1, G->supplyCount[7]);
		Assert(initialSupply-1, G->supplyCount[7], "==");
		
	}
	assert(returnVal == 0);
}

int main (){

	//initialize game
	struct gameState testState;
	int seed = 500;
	int numPlayers = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, sea_hag};
	int result;

	memset(&testState, 0, sizeof(struct gameState));
	
	result = initializeGame(numPlayers, k, seed, &testState);

	//Print header for test
	printf("\n|------------------------------------------------------------------UNIT TEST 1: \"gainCard\" START------------------------------------------------------------------|\n");
	printf("\n**Initialized values for game\n**Kingdom Cards: adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, sea_hag\n**Number of players: %d\n**Seed: %d\n\n", testState.numPlayers, seed);
	
	//Testing the results for card that was never dealt, should return error
	result = testCardNotDealt(&testState, 0);
	
	result = testCardSupplyEmpty(&testState, 0);
	
	testGainCard(&testState, 0);
	
	printf("\n|------------------------------------------------------------------UNIT TEST 1: \"gainCard\" FINISH-----------------------------------------------------------------|\n\n");
	
	assert(result == 0);
	
return 0;
}