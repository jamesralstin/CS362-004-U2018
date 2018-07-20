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
#include <assert.h>

int testLastPositionCardPlayed(struct gameState *G, int player){
	
	int trashFlag = 0;
	int result;
	int position = 4;//First compare for last card in 
	int compareCard, comparePlayedCardCount, compareHandCount;
	
	//For comparing cards in their new destinations i.e. discount piles
	compareCard = G->hand[player][position];
	comparePlayedCardCount = G->playedCardCount;
	compareHandCount = G->handCount[player];
	
	//Not trashed
	result = discardCard(position, player, G, trashFlag);
	
	printf("|---------------------------------UNIT TEST 2.1: Last position played, not trashed--------------------------------|\n\n");
	
	//Verify card was moved from hand to playedCard
	Assert(compareCard, G->playedCards[G->playedCardCount - 1], "==");
	Assert(-1, G->hand[player][position], "==");
	
	//Validate increment of playedCardCount
	Assert(comparePlayedCardCount, G->playedCardCount, "<");
	
	//Verify decrement of handCount
	Assert(compareHandCount, G->handCount[player], ">");
	
	printf("\n|---------------------------------UNIT TEST 2.2: Last position played, trashed------------------------------------|\n\n");
	
	position = 3;
	trashFlag = 1;
	
	compareCard = G->hand[player][position];
	comparePlayedCardCount = G->playedCardCount;
	compareHandCount = G->handCount[player];
	
	result = discardCard(position, player, G, trashFlag);
	
	//Verify card was removed from hand
	Assert(-1, G->hand[player][position], "==");
	
	//Validate played card count was not incremented
	Assert(comparePlayedCardCount, G->playedCardCount, "==");
	
	//Verify decrement of handCount
	Assert(compareHandCount, G->handCount[player], ">");
	
	return result;
}

int testLastCardInHand(struct gameState *G, int player){
	
	int result, i;
	int position = 0;
	int trashFlag = 0;
	int compareCard, comparePlayedCardCount;
	
	for(i = 5; i > 0; i--){
		
		G->hand[player][i] = -1;
		
	}
	
	G->handCount[player] = 1;
	
	compareCard = G->hand[player][position];
	comparePlayedCardCount = G->playedCardCount;
	
	result = discardCard(position, player, G, trashFlag);
	
	printf("\n|---------------------------------UNIT TEST 2.3: Last card in hand, not trashed-----------------------------------|\n\n");
	
	//Verify card was moved from hand to playedCard
	Assert(compareCard, G->playedCards[G->playedCardCount - 1], "==");
	Assert(-1, G->hand[player][position], "==");
	
	//Validate increment of playedCardCount
	Assert(comparePlayedCardCount, G->playedCardCount, "<");
	
	//Verify decrement of handCount
	Assert(1, G->handCount[player], ">");
	
	printf("\n|---------------------------------UNIT TEST 2.4: Last card in hand, trashed---------------------------------------|\n\n");
	
	//reinitialize variables
	trashFlag = 1;
	G->handCount[player] = 1;
	G->hand[player][position] = 4;
	
	compareCard = G->hand[player][position];
	comparePlayedCardCount = G->playedCardCount;
	
	result = discardCard(position, player, G, trashFlag);
	
	//Verify card was removed from hand
	Assert(-1, G->hand[player][position], "==");
	
	//Validate played card count was not incremented
	Assert(comparePlayedCardCount, G->playedCardCount, "==");
	
	//Verify decrement of handCount
	Assert(1, G->handCount[player], ">");
	
	return result;
}

//Not last position in hand array and not last card in hand
int testNotAnyLast(struct gameState *G, int player){
	
	int trashFlag = 0;
	int position = 2;
	int result, compareLastCard, compareCard, comparePlayedCardCount, compareHandCount;
	
	//For comparing cards in their new destinations i.e. discard pile
	compareCard = G->hand[player][position];
	comparePlayedCardCount = G->playedCardCount;
	compareHandCount = G->handCount[player];
	compareLastCard = G->hand[player][4];
	
	//Not trashed
	result = discardCard(position, player, G, trashFlag);
	
	printf("\n|---------------------------------UNIT TEST 2.5: Not last position, not last card in hand, not trashed------------|\n\n");
	
	//Verify card was moved from hand to playedCard
	Assert(compareCard, G->playedCards[G->playedCardCount - 1], "==");
	
	//Validate increment of playedCardCount
	Assert(comparePlayedCardCount, G->playedCardCount, "<");
	
	//Verify decrement of handCount
	Assert(compareHandCount, G->handCount[player], ">");
	
	//Verify last card has been removed and then placed in the now empty position of array
	Assert(-1, G->hand[player][4], "==");
	Assert(compareLastCard, G->hand[player][position], "==");
	
	printf("\n|---------------------------------UNIT TEST 2.6: Not last position, not last card in hand, trashed----------------|\n\n");
	
	trashFlag = 1;
	
	compareCard = G->hand[player][position];
	comparePlayedCardCount = G->playedCardCount;
	compareHandCount = G->handCount[player];
	compareLastCard = G->hand[player][3];
	
	//Trashed
	result = discardCard(position, player, G, trashFlag);
	
	//Validate played card count was not incremented
	Assert(comparePlayedCardCount, G->playedCardCount, "==");
	
	//Verify decrement of handCount
	Assert(compareHandCount, G->handCount[player], ">");
	
	//Verify last card has been removed and then placed in the now empty position of array
	Assert(-1, G->hand[player][3], "==");
	Assert(compareLastCard, G->hand[player][position], "==");
	
	return result;
}

int main (){

	//initialize game
	struct gameState testState;
	int seed = 450;
	int numPlayers = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, sea_hag};
	int result;
	int player = 0;

	memset(&testState, 0, sizeof(struct gameState));
	
	result = initializeGame(numPlayers, k, seed, &testState);
	
	
	
	printf("\n|------------------------------------------------------------------UNIT TEST 2: \"discardCard\" START------------------------------------------------------------------|\n");
	printf("\n**Initialized values for game\n**Kingdom Cards: adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, sea_hag\n**Number of players: %d\n**Seed: %d\n\n", testState.numPlayers, seed);
	
	
	result = testLastPositionCardPlayed(&testState, player);
	
	result = testLastCardInHand(&testState, player);
	
	//Reinitialize state of game
	memset(&testState, 0, sizeof(struct gameState));
	result = initializeGame(numPlayers, k, seed, &testState);
	
	result = testNotAnyLast(&testState, player);
	
	assert(result == 0);
	
	printf("\n|------------------------------------------------------------------UNIT TEST 2: \"discardCard\" FINISH-----------------------------------------------------------------|\n\n");
	
return 0;
}
