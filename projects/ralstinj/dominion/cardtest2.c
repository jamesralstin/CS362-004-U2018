/* -----------------------------------------------------------------------
* Title: cardtest2
* Author: James Ralstin
* Assignment: 3
* Due Date: 07/22/2018
* Description: This unit test is responsible for testing the card 
* implementation of sea_hag in the implementation of dominion as provided
* for the course of CS362
* Term: Summer 2018
*
* Must include the following in the make file
* unittest1: cardtest2.c dominion.o rngs.o Assert.o
*      gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o Assert.o $(CFLAGS)
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

void testSeaHag(struct gameState *G, int player, int numPlayers){
	
	int i, result;
	struct gameState prePlay;
	
	//Replacing last position card with sea_hag
	discardCard(4, player, G, 0);	
	G->hand[player][4] = 25;
	G->handCount[player]++;
	G->supplyCount[25]--;
	
	memcpy(&prePlay, G, sizeof(struct gameState));//State of game before sea hag played
	
	result = playSeaHag(player, G);
	assert(result == 0);
	
	for(i = 0; i < numPlayers; i++){
		
		if( i != player){//Verifying the states of players whose turn it is not
			
			printf("\n|---------------------------------CARD TEST 2.%d: Beginning tests for player %d, who is not the current player-------------------------------|\n\n",i+1,i);
			
			//This player should have a their top card on their deck discarded, then a curse placed on top of their deck.
			printf("\nVerifying that the top discard card came from top of deck, expected value %d, actual value %d\n",prePlay.deck[i][prePlay.deckCount[i] - 1], G->discard[i][G->discardCount[i]-1]);
			Assert(prePlay.deck[i][prePlay.deckCount[i] - 1], G->discard[i][G->discardCount[i]-1], "==");
			
			//Verify curse ontop of their deck
			printf("\nVerifying a curse card has been placed on top of the deck, expected value 0, actual value %d\n",G->deck[i][G->deckCount[i]-1]);
			Assert(curse, G->deck[i][G->deckCount[i]-1], "==");
			
			printf("\nVerify no change to deck count, expected value %d, actual value %d\n", prePlay.deckCount[i], G->deckCount[i]);
			Assert(prePlay.deckCount[i], G->deckCount[i],"==");
			
			printf("\nVerify discard count has incremented by 1, expected value %d, actual value %d\n", prePlay.discardCount[i] + 1, G->discardCount[i]);
			Assert(prePlay.discardCount[i], G->discardCount[i],"<");
				
		}else{//Verifying the state of the player whose turn it is
			
			printf("\n|---------------------------------CARD TEST 2.%d: Beginning tests for player %d, who is the current player---------------------------------|\n\n",i+1,i);
			
			//Verify discard of sea hag card
			printf("\nVerify card on top of played card pile is sea hag, expected value 25, actual value is %d\n",G->playedCards[G->playedCardCount - 1]);
			Assert(G->playedCards[G->playedCardCount - 1], 25, "==");
		
			//Verify played card count has incremented by one
			printf("\nVerify played card count has incremented by 1, expected value %d, actual value is %d\n", prePlay.playedCardCount + 1,G->playedCardCount);
			Assert(G->playedCardCount, prePlay.playedCardCount, ">");
			
			printf("\nVerify no change to deck count, expected value %d, actual value %d\n", prePlay.deckCount[i], G->deckCount[i]);
			Assert(prePlay.deckCount[i], G->deckCount[i],"==");
			
			printf("\nVerify sea hag has been removed from hand, expected value -1, actual value %d\n", G->hand[i][4]);
			Assert(G->hand[i][4], -1,"==");
			
			printf("\nVerify hand count has decremented by 1, expected value %d, actual value is %d\n", prePlay.handCount[i] - 1,G->handCount[i]);
			Assert(G->handCount[i], prePlay.handCount[i], "<");
		
		}
		
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
	printf("\n|------------------------------------------------------------------CARD TEST 2: \"sea_hag\" START------------------------------------------------------------------|\n");
	printf("\n**Initialized values for game\n**Kingdom Cards: adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, sea_hag\n**Number of players: %d\n**Seed: %d\n\n", testState.numPlayers, seed);

	testSeaHag(&testState, 0, numPlayers);
	
	printf("\n|------------------------------------------------------------------CARD TEST 2: \"sea_hag\" FINISH-----------------------------------------------------------------|\n\n");
	
return 0;
}
