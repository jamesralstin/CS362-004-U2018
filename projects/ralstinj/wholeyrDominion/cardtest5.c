/* -----------------------------------------------------------------------
* Title: cardtest5
* Author: James Ralstin
* Assignment: 5
* Due Date: 08/12/2018
* Description: This unit test is responsible for testing the card 
* implementation of council room in the implementation of dominion as provided
* for the course of CS362
* Term: Summer 2018
*
* Must include the following in the make file
* unittest1: cardtest5.c dominion.o rngs.o Assert.o
*      gcc -o cardtest5 -g  cardtest5.c dominion.o rngs.o Assert.o $(CFLAGS)
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

void testCouncilRoom(struct gameState *G, int player){
	
	int result, i;
	int preSupply[27];
	
	//Replacing last position card with council room
	discardCard(4, player, G, 0);	
	G->hand[player][4] = council_room;
	G->handCount[player]++;
	G->supplyCount[council_room]--;
	
	//Copy supply counts
	for(i = 0; i < 27; i++){preSupply[i] = G->supplyCount[i];}
	
	printf("Hand count before \"doCouncilRoomEffect\" %d\n",G->handCount[player]);
	printf("\nDeck count before \"doCouncilRoomEffect\" %d\n",G->deckCount[player]);
	printf("\nPlayed count before \"doCouncilRoomEffect\" %d (should be 1 due to initial remove and replace for council room card)\n",G->playedCardCount);
	
	result = doCouncilRoomEffect(4, player, G);
	assert(result == 0);
	
	printf("\nExpected hand count of current player after \"doCouncilRoomEffect\" is 8, actual hand count of current after \"doCouncilRoomEffect\" %d\n",G->handCount[player]);
	Assert(8, G->handCount[player], "==");
	
	printf("\nExpected hand count of opposing player after \"doCouncilRoomEffect\" is 1, actual hand count of current after \"doCouncilRoomEffect\" %d\n",G->handCount[1]);
	Assert(1, G->handCount[1], "==");
	
	printf("\nExpected played card count after \"doCouncilRoomEffect\" is 2, actual played count after \"doCouncilRoomEffect\" %d\n",G->playedCardCount);
	Assert(2, G->playedCardCount, "==");
	
	printf("\nExpected deck count of current player after \"doCouncilRoomEffect\" is 1, actual deck count after \"doCouncilRoomEffect\" %d\n",G->deckCount[player]);
	Assert(1, G->deckCount[player], "==");
	
	printf("\nExpected card value in last played card after \"doCouncilRoomEffect\" is %d, actual card value in last played card after \"doCouncilRoomEffect\" %d\n", council_room ,G->playedCards[1]);
	Assert(council_room, G->playedCards[1], "==");
	
	printf("\nExpected number of buys for current player after \"doCouncilRoomEffect\" is 2, actual number of buys for current player after \"doCouncilRoomEffect\" %d\n", G->numBuys);
	Assert(2, G->numBuys, "==");
	
	printf("\nVerifying no change to supply counts after \"doCouncilRoomEffect\"\n");
	
	for(i = 0; i < 27; i++){
		Assert(preSupply[i], G->supplyCount[i], "==");
	}
	
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
	printf("\n|------------------------------------------------------------------CARD TEST 1: \"council room\" START------------------------------------------------------------------|\n");
	printf("\n**Initialized values for game\n**Kingdom Cards: adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, sea_hag\n**Number of players: %d\n**Seed: %d\n\n", testState.numPlayers, seed);

	
	testCouncilRoom(&testState, 0);
	
	
	printf("\n|------------------------------------------------------------------CARD TEST 1: \"council room\" FINISH-----------------------------------------------------------------|\n\n");
	
return 0;
}