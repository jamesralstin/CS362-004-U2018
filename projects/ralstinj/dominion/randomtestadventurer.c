/* -----------------------------------------------------------------------
* Title: randomtestcard1
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
	int r;
	struct gameState preG;
	
	//Replacing first position card with adventurer
	discardCard(0, player, G, 0);	
	G->hand[player][0] = adventurer;
	G->handCount[player]++;
	G->supplyCount[adventurer]--;
	
	memcpy(&preG, G, sizeof(struct gameState));
	
	r = playAdventurer(z, G, player, cardDrawn, tempHand);
	Assert(0, r, "==");

	//Effects of adventurer on pre state
	int drawntreasure=0;
	
	while(drawntreasure<2){
		
		if (preG.deckCount[player] <1){//if the deck is empty we need to shuffle discard and add to deck
		
			shuffle(player, &preG);
		
		}
	
		drawCard(player, &preG);
		cardDrawn = preG.hand[player][preG.handCount[player]-1];//top card of hand is most recently drawn card.
		
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold){
		
			drawntreasure++;
		
		}else{
		
			tempHand[z]=cardDrawn;
			preG.handCount[player]--; //this should just remove the top card (the most recently drawn one).
			z++;
		
		}
	}
	
	while(z-1>=0){
		
		preG.discard[player][preG.discardCount[player]++]=tempHand[z-1]; // discard all cards in play that have been drawn
		z=z-1;
	
	}
	
	Assert(memcmp(&preG, G, sizeof(struct gameState)), 0, "==");
	
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
