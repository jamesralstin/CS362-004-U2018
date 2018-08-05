/* -----------------------------------------------------------------------
* Title: randomtestcard1
* Author: James Ralstin
* Assignment: 4
* Due Date: 08/05/2018
* Description: This random test is responsible for testing the card 
* implementation of sea hag in the implementation of dominion as provided
* for the course of CS362
* Term: Summer 2018
*
* Must include the following in the make file
* randomtestcard1: randomtestcard1.c dominion.o rngs.o Assert.o
*      gcc -o randomtestcard1 -g  randomtestcard1.c dominion.o rngs.o Assert.o $(CFLAGS)
* -----------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <math.h>
#include "Assert.h"
#include <string.h>

void testSeaHag(int player, struct gameState *G){
	
	int i, r;
	struct gameState preG;
	
	memcpy(&preG, G, sizeof(struct gameState));
	
	r = playSeaHag(player, G);
	
	for(i = 0; i < G->numPlayers; i++){
		
		if( i != player){//Modifying the states of players whose turn it is not
						
			preG.discard[i][preG.discardCount[i]] = preG.deck[i][preG.deckCount[i]-1];			
			preG.deckCount[i]--;
			preG.discardCount[i]++;
			preG.deck[i][preG.deckCount[i]-1] = curse;//Top card now a curse
			
		}else{//Modifying the state of the player whose turn it is

			preG.playedCards[preG.playedCardCount - 1] = sea_hag;
			
		}
	}
	
	for(i = 0; i < G->numPlayers; i++){//Compare relevant values from playing sea hag for each player
		
		printf("Comparing discarded card of player %d\n",i);
		Assert(preG.discard[i][preG.discardCount[i]], G->discard[i][G->discardCount[i]], "==");
		printf("Comparing deck count of player %d\n",i);
		Assert(preG.deckCount[i], G->deckCount[i], "==");
		printf("Comparing discard count of player %d\n",i);
		Assert(preG.discardCount[i], G->discardCount[i], "==");
		printf("Comparing top deck card of player %d\n",i);
		Assert(preG.deck[i][preG.deckCount[i]-1], G->deck[i][G->deckCount[i]-1], "==");
		
	}
	
	printf("Verifying sea hag returned without error\n");
	Assert(r, 0, "==");
	
}

int main(){
	
	struct gameState testGame;
	int i, player, n;
	
	SelectStream(2);
	PutSeed(3);
	
	for(n = 0; n < 100; n++){
		
		for(i = 0; i < sizeof(struct gameState); i++){
			
			((char*)&testGame)[i] = floor(Random()*256);
		
		}
		testGame.numPlayers = floor(Random()*3+2);
		player = floor(Random()*testGame.numPlayers);
	
		//For each player initialize a realistic game state
		for(i = 0; i < testGame.numPlayers; i++){
			testGame.handCount[i] = floor(Random()*MAX_HAND);
			testGame.deckCount[i] = floor(Random()*MAX_DECK);
			testGame.discardCount[i] = floor(Random()*MAX_DECK);
		}
		
		testGame.playedCardCount = floor(Random()*MAX_DECK);
		
		testSeaHag(player, &testGame);
	
	}
	printf("\n**TESTING COMPLETE**\n\n");

return 0;
}
