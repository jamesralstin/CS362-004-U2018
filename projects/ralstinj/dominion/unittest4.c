/* -----------------------------------------------------------------------
* Title: unittest1
* Author: James Ralstin
* Assignment: 3
* Due Date: 07/22/2018
* Description: This unit test is responsible for testing the function of getCost
* in the implementation of dominion as provided for the course of CS362
* Term: Summer 2018
*
* Must include the following in the make file
* unittest1: unittest4.c dominion.o rngs.o Assert.o
*      gcc -o unittest4 -g  unittest4.c dominion.o rngs.o Assert.o $(CFLAGS)
* -----------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include "Assert.h"


void testGetCost(struct gameState *G){
	
	int i, result;
	
	printf("|---------------------------------UNIT TEST 4.1: Verify known card values (i.e. smithy, adventurer)---------------------------------|\n\n");
	
	for(i = 0; i < 27; i++){
		
		result = getCost(i);
		
		switch( i ) 
		{
			case curse:
			  Assert(result, 0, "==");
			  break;
			case estate:
			  Assert(result, 2, "==");
			  break;
			case duchy:
			  Assert(result, 5, "==");
			  break;
			case province:
			  Assert(result, 8, "==");
			  break;
			case copper:
			  Assert(result, 0, "==");
			  break;
			case silver:
			  Assert(result, 3, "==");
			  break;
			case gold:
			  Assert(result, 6, "==");
			  break;
			case adventurer:
			  Assert(result, 6, "==");
			  break;
			case council_room:
			  Assert(result, 5, "==");
			  break;
			case feast:
			  Assert(result, 4, "==");
			  break;
			case gardens:
			  Assert(result, 4, "==");
			  break;
			case mine:
			  Assert(result, 5, "==");
			  break;
			case remodel:
			  Assert(result, 4, "==");
			  break;
			case smithy:
			  Assert(result, 4, "==");
			  break;
			case village:
			  Assert(result, 3, "==");
			  break;
			case baron:
			  Assert(result, 4, "==");
			  break;
			case great_hall:
			  Assert(result, 3, "==");
			  break;
			case minion:
			  Assert(result, 5, "==");
			  break;
			case steward:
			  Assert(result, 3, "==");
			  break;
			case tribute:
			  Assert(result, 5, "==");
			  break;
			case ambassador:
			  Assert(result, 3, "==");
			  break;
			case cutpurse:
			  Assert(result, 4, "==");
			  break;
			case embargo:
			  Assert(result, 2, "==");
			  break;
			case outpost:
			  Assert(result, 5, "==");
			  break;
			case salvager:
			  Assert(result, 4, "==");
			  break;
			case sea_hag:
			  Assert(result, 4, "==");
			  break;
			case treasure_map:
			  Assert(result, 4, "==");
			  break;
		}
	}
	
	printf("\n|---------------------------------UNIT TEST 4.2: Verify error on unknown cards (i.e. some int greater than 27 or less than 0)---------------------------------|\n\n");
	
	result = getCost(28);
	
	Assert(result, -1, "==");
	
	result = getCost(-1);
	
	Assert(result, -1, "==");
	
}


int main (){

	//initialize game
	struct gameState testState;
	int seed = 600;
	int numPlayers = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, sea_hag};
	int result;

	memset(&testState, 0, sizeof(struct gameState));
	
	result = initializeGame(numPlayers, k, seed, &testState);
	
	//Print header for test
	printf("\n|------------------------------------------------------------------UNIT TEST 4: \"getCost\" START------------------------------------------------------------------|\n");
	printf("\n**Initialized values for game\n**Kingdom Cards: adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, sea_hag\n**Number of players: %d\n**Seed: %d\n\n", testState.numPlayers, seed);

	testGetCost(&testState);
	
	//Print test complete
	printf("\n|------------------------------------------------------------------UNIT TEST 4: \"getCard\" FINISH-----------------------------------------------------------------|\n\n");
	
return 0;
}
