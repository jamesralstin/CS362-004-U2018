/* -----------------------------------------------------------------------
* Title: randomtestadventurer
* Author: James Ralstin
* Assignment: 4
* Due Date: 08/05/2018
* Description: This random test is responsible for testing the card 
* implementation of adventurer in the implementation of dominion as provided
* for the course of CS362
* Term: Summer 2018
*
* Must include the following in the make file
* randomtestadventurer: randomtestadventurer.c dominion.o rngs.o Assert.o
*      gcc -o randomtestadventurer -g  randomtestadventurer.c dominion.o rngs.o Assert.o $(CFLAGS)
* -----------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <math.h>
#include <string.h>
#include "Assert.h"
#include "rngs.h"

void testAdventurer(int player, struct gameState *G){
	
	int tempHand[MAX_HAND];
	int z = 0;
	int cardDrawn = 0;
	int r, i;
	struct gameState preG;
	int preTreasureCount = 0;
	int postTreasureCount = 0;

	
	//Replacing first position card with adventurer
	discardCard(0, player, G, 0);	
	G->hand[player][0] = adventurer;
	G->handCount[player]++;
	G->supplyCount[adventurer]--;
	
	memcpy(&preG, G, sizeof(struct gameState));
	
	r = playAdventurer(z, G, player, cardDrawn, tempHand);
	Assert(0, r, "==");

	//Effects of adventurer on pre state
	printf("Verify hand count increased by 1, expected value %d, actual value %d\n", preG.handCount[player] + 1, G->handCount[player]);
	Assert(preG.handCount[player] + 1, G->handCount[player], "==");
	printf("Verify played card count increased by 1, expected value %d, actual value %d\n", preG.playedCardCount + 1, G->playedCardCount);
	Assert(preG.playedCardCount + 1, G->playedCardCount, "==");
	printf("Verify played card pile top card is adventurer, expected value 7, actual value %d\n", G->playedCards[G->playedCardCount-1]);
	Assert(adventurer, G->playedCards[G->playedCardCount-1], "==");
	
	//Get previous treasures
	for(i = 0; i < preG.handCount[player]; i++){
		
		if (preG.hand[player][i] == copper || preG.hand[player][i] == silver || preG.hand[player][i] == gold){
		
			preTreasureCount++;
		
		}
		
	}
	
	//Get new treasure
	for(i = 0; i < G->handCount[player]; i++){
		
		if (G->hand[player][i] == copper || G->hand[player][i] == silver || G->hand[player][i] == gold){
		
			postTreasureCount++;
		
		}
		
	}
	
	printf("Verifying two new treasures have been added, expected count %d, actual count %d\n", preTreasureCount + 2, postTreasureCount);
	Assert(preTreasureCount + 2, postTreasureCount, "==");
	
}


int main(){

	struct gameState testGame;
	int i, player, n, numPlayers;
	int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, sea_hag};
	
	SelectStream(2);
	PutSeed(3);
	
	for(n = 0; n < 100; n++){
		
		numPlayers = floor(Random()*3 + 2);
		player = floor(Random()*numPlayers);
		
		int randoSeed = floor(Random()*1005 + 1);
		
		i = initializeGame(numPlayers, kingdomCards, randoSeed, &testGame);
	
		//For each player initialize a realistic game state
		for(i = 0; i < numPlayers; i++){
			testGame.handCount[i] = floor(Random()*MAX_HAND);
			testGame.deckCount[i] = floor(Random()*MAX_DECK);
			testGame.discardCount[i] = floor(Random()*MAX_DECK);
		}
		
		testGame.playedCardCount = floor(Random()*MAX_DECK);
		
		testAdventurer(player, &testGame);
	
	}
	printf("\n**TESTING COMPLETE**\n\n");

return 0;
}
