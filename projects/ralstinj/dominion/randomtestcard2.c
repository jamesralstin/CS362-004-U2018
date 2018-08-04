/* -----------------------------------------------------------------------
* Title: randomtestcard1
* Author: James Ralstin
* Assignment: 4
* Due Date: 08/05/2018
* Description: This random test is responsible for testing the card 
* implementation of smithy in the implementation of dominion as provided
* for the course of CS362
* Term: Summer 2018
*
* Must include the following in the make file
* randomtestcard1: randomtestcard2.c dominion.o rngs.o Assert.o
*      gcc -o randomtestcard2 -g  randomtestcard2.c dominion.o rngs.o Assert.o $(CFLAGS)
* -----------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "Assert.h"
#include <string.h>
#include "rngs.h"
#include <math.h>

void testSmithy(int player, struct gameState *G){
	
	int r;
	struct gameState preG;
	
	//Replacing last position card with smithy
	discardCard(0, player, G, 0);	
	G->hand[player][0] = smithy;
	G->handCount[player]++;
	G->supplyCount[smithy]--;
	
	memcpy(&preG, G, sizeof(struct gameState));
	
	r = playSmithy(player, G, 0);
	Assert(0, r, "==");
	
	preG.handCount[player] = preG.handCount[player] + 2;
	preG.playedCardCount++;
	preG.deckCount[player] = preG.deckCount[player] - 3;
	
	printf("Comparing hand count of player %d\n",player);
	Assert(preG.handCount[player], G->handCount[player], "==");
	printf("Comparing played card count\n");
	Assert(preG.playedCardCount, G->playedCardCount, "==");
	printf("Comparing last played card, should be smithy\n");
	Assert(smithy, G->playedCards[G->playedCardCount - 1], "==");
	printf("Comparing deck count of player %d\n",player);
	Assert(preG.deckCount[player], G->deckCount[player], "==");
	
}

int main(){

	struct gameState testGame;
	int i, player, n;
	
	SelectStream(2);
	PutSeed(3);
	
	for(n = 0; n < 100; n++){
			
		testGame.numPlayers = floor(Random()*MAX_PLAYERS);
		player = floor(Random()*testGame.numPlayers);
		int kingdomCards[10];
		for(i = 0; i < 10; i++){
			kingdomCards[i] = floor(Random()*treasure_map + 1);
		}
		
		int randoSeed = floor(Random()*1000);
		
		i = initializeGame(testGame.numPlayers, kingdomCards, randoSeed, &testGame);
	
		//For each player initialize a realistic game state
		for(i = 0; i < testGame.numPlayers; i++){
			testGame.handCount[i] = floor(Random()*MAX_HAND);
			testGame.deckCount[i] = floor(Random()*MAX_DECK);
			testGame.discardCount[i] = floor(Random()*MAX_DECK);
		}
		
		testGame.playedCardCount = floor(Random()*MAX_DECK);
		
		testSmithy(player, &testGame);
	
	}
	printf("\n**TESTING COMPLETE**\n\n");

return 0;
}
