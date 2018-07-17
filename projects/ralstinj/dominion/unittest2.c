/* -----------------------------------------------------------------------
* Title: unittest2
* Author: James Ralstin
* Assignment: 3
* Due Date: 07/22/2018
* Description: This unit test is responsible for testing the function of discardCard
* in the implementation of dominion as provided for the course of CS362
* Term: Summer 2018
*
* Must include the following in the make file
* unittest2: unittest2.c dominion.o rngs.o Assert.o
*      gcc -o unittest2 -g  unittest2.c dominion.o rngs.o Assert.o $(CFLAGS)
* -----------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "Assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>

int testTrashCard(struct gameState *G, int player){
	
	int result, trashFlag, initialPlayedCardCount, handPos;
	trashFlag = 0;
	
	printf("|---------------------------------UNIT TEST 2.1: Verify card not played if trashed-------------------------------|\n\n");
	
	
	
	for(handPos = 0; handPos < 5; handPos++){
		
		//printf("Hand Position is %d, Hand count is %d\n\n", handPos,G->handCount[player]);
		
		initialPlayedCardCount = G->playedCardCount;
		result = discardCard(handPos, player, G, trashFlag);
		result = Assert(initialPlayedCardCount + 1, G->playedCardCount, "==");
		
		if((handPos == G->handCount[player] - 1) || (G->handCount[player] == 1)){result = Assert(G->hand[player][handPos], -1, "==");}
		
	}
	
	return 0;
}

int main (){

	//initialize game
	struct gameState testState;
	int seed = 350;
	int numPlayers = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, sea_hag};
	int result, i;
	int player = 0;

	memset(&testState, 0, sizeof(struct gameState));
	
	result = initializeGame(numPlayers, k, seed, &testState);
	
	printf("\n|------------------------------------------------------------------UNIT TEST 2: \"discardCard\" START------------------------------------------------------------------|\n");
	printf("\n**Initialized values for game\n**Kingdom Cards: adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, sea_hag\n**Number of players: %d\n**Seed: %d\n\n", testState.numPlayers, seed);
	
	
	result = testTrashCard(&testState, player);
	
	
	printf("\n|------------------------------------------------------------------UNIT TEST 2: \"discardCard\" FINISH-----------------------------------------------------------------|\n\n");
	
return 0;
}
