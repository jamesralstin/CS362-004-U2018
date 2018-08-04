/* -----------------------------------------------------------------------
* Title: cardtest1
* Author: James Ralstin
* Assignment: 3
* Due Date: 07/22/2018
* Description: This unit test is responsible for testing the card 
* implementation of smithy in the implementation of dominion as provided
* for the course of CS362
* Term: Summer 2018
*
* Must include the following in the make file
* unittest1: cardtest1.c dominion.o rngs.o Assert.o
*      gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o Assert.o $(CFLAGS)
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

void testSmithy(struct gameState *G, int player){
	
	int result, i;
	int preSupply[27];
	
	//Replacing last position card with smithy
	discardCard(4, player, G, 0);	
	G->hand[player][4] = 13;
	G->handCount[player]++;
	G->supplyCount[13]--;
	
	//Copy supply counts
	for(i = 0; i < 27; i++){preSupply[i] = G->supplyCount[i];}
	
	printf("Hand count before \"playSmithy\" %d\n",G->handCount[player]);
	printf("\nDeck count before \"playSmithy\" %d\n",G->deckCount[player]);
	printf("\nPlayed count before \"playSmithy\" %d (should be 1 due to initial remove and replace for smithy card)\n",G->playedCardCount);
	
	result = playSmithy(player, G, 4);
	assert(result == 0);
	
	printf("\nExpected hand count after \"playSmithy\" is 7, actual hand count after \"playSmithy\" %d\n",G->handCount[player]);
	Assert(7, G->handCount[player], "==");
	
	printf("\nExpected played card count after \"playSmithy\" is 2, actual played count after \"playSmithy\" %d\n",G->playedCardCount);
	Assert(2, G->playedCardCount, "==");
	
	printf("\nExpected deck count after \"playSmithy\" is 2, actual deck count after \"playSmithy\" %d\n",G->deckCount[player]);
	Assert(2, G->deckCount[player], "==");
	
	printf("\nExpected card value in last played card after \"playSmithy\" is 13, actual card value in last played card after \"playSmithy\" %d\n",G->playedCards[1]);
	Assert(13, G->playedCards[1], "==");
	
	printf("\nVerifying no change to supply counts after \"playSmithy\"\n");
	
	for(i = 0; i < 27; i++){
		Assert(preSupply[i], G->supplyCount[i], "==");
	}
	
	printf("\nVerify no change to other player(s) deck\n");
	Assert(10, G->deckCount[1], "==");
	
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
	assert(result == 0);
	
	//Print header for test
	printf("\n|------------------------------------------------------------------CARD TEST 1: \"smithy\" START------------------------------------------------------------------|\n");
	printf("\n**Initialized values for game\n**Kingdom Cards: adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, sea_hag\n**Number of players: %d\n**Seed: %d\n\n", testState.numPlayers, seed);

	
	testSmithy(&testState, 0);
	
	
	printf("\n|------------------------------------------------------------------CARD TEST 1: \"smithy\" FINISH-----------------------------------------------------------------|\n\n");
	
return 0;
}
