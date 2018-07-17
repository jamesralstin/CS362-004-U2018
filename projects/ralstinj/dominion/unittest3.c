/* -----------------------------------------------------------------------
* Title: unittest1
* Author: James Ralstin
* Assignment: 3
* Due Date: 07/22/2018
* Description: This unit test is responsible for testing the function of fullDeckCount
* in the implementation of dominion as provided for the course of CS362
* Term: Summer 2018
*
* Must include the following in the make file
* unittest1: unittest3.c dominion.o rngs.o Assert.o
*      gcc -o unittest3 -g  unittest3.c dominion.o rngs.o Assert.o $(CFLAGS)
* -----------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include "Assert.h"

int testFullDeckCount(struct gameState *G){
	
	int player;
	int deckCountResult;
	
	//For each player, check...
	for(player = 0; player < 2; player++){
		
		//Estate card count
		printf("\nChecking player %d initialized estate cards\n", player +1);
		deckCountResult = fullDeckCount(player, estate, G);
		Assert(deckCountResult, 3, "==");
		
		//Copper card count
		printf("\nChecking player %d initialized copper cards\n", player +1);
		deckCountResult = fullDeckCount(player, copper, G);
		Assert(deckCountResult, 7, "==");
		
		//Known non-existent card
		printf("\nChecking for card not in deck, adventurer\n");
		deckCountResult = fullDeckCount(player, adventurer, G);
		Assert(deckCountResult, 0, "==");
		
		//Add new card to deck, check if it counts
		printf("\nAdding adventurer to deck and verifying count\n");
		
		if(player == 0){
			G->deck[player][5] = adventurer;
		}else{
			G->deck[player][10] = adventurer;
		}
		G->deckCount[player]++;
		deckCountResult = fullDeckCount(player, adventurer, G);
		Assert(deckCountResult, 1, "==");
		
		//Add new card to hand, check if it counts
		printf("\nAdding adventurer to hand and verifying count\n");
		
		if(player == 0){
			G->hand[player][5] = adventurer;
		}else{
			G->hand[player][0] = adventurer;
		}
		G->handCount[player]++;
		deckCountResult = fullDeckCount(player, adventurer, G);
		Assert(deckCountResult, 2, "==");
		
		//Add new card to discard, check if it counts
		printf("\nAdding adventurer to discard and verifying count\n");
		G->discard[player][0] = adventurer;
		G->discardCount[player]++;
		deckCountResult = fullDeckCount(player, adventurer, G);
		Assert(deckCountResult, 3, "==");
		
	}
	
	return 0;
}

int main (){

	//initialize game
	struct gameState testState;
	int seed = 900;
	int numPlayers = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, sea_hag};
	int result;

	memset(&testState, 0, sizeof(struct gameState));
	
	result = initializeGame(numPlayers, k, seed, &testState);

	printf("Player 1 %d, player 2 %d", testState.deckCount[0],testState.deckCount[1]);
	printf("Player 1 %d, player 2 %d", testState.handCount[0],testState.handCount[1]);
	
	//Print header for test
	printf("\n|------------------------------------------------------------------UNIT TEST 3: \"fullDeckCount\" START------------------------------------------------------------------|\n");
	printf("\n**Initialized values for game\n**Kingdom Cards: adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, sea_hag\n**Number of players: %d\n**Seed: %d\n\n", testState.numPlayers, seed);

	result = testFullDeckCount(&testState);
	
	//Print test complete
	printf("\n|------------------------------------------------------------------UNIT TEST 3: \"gainCard\" FINISH-----------------------------------------------------------------|\n\n");
	
return 0;
}
