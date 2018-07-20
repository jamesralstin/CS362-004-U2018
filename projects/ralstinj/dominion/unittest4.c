/* -----------------------------------------------------------------------
* Title: unittest4
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
#include <assert.h>

void testGetCost(struct gameState *G){
	
	int i, result;
	
	printf("|---------------------------------UNIT TEST 4.1: Verify known card values (i.e. smithy, adventurer)---------------------------------|\n\n");
	
	for(i = 0; i < 27; i++){
		
		result = getCost(i);
		
		switch( i ) 
		{
			case curse:
			  printf("Testing curse card. ");
			  Assert(result, 0, "==");
			  break;
			case estate:
			  printf("Testing estate card. ");
			  Assert(result, 2, "==");
			  break;
			case duchy:
			  printf("Testing duchy card. ");
			  Assert(result, 5, "==");
			  break;
			case province:
			  printf("Testing province card. ");
			  Assert(result, 8, "==");
			  break;
			case copper:
			  printf("Testing copper card. ");
			  Assert(result, 0, "==");
			  break;
			case silver:
			  printf("Testing silver card. ");
			  Assert(result, 3, "==");
			  break;
			case gold:
			  printf("Testing gold card. ");
			  Assert(result, 6, "==");
			  break;
			case adventurer:
			  printf("Testing adventurer card. ");
			  Assert(result, 6, "==");
			  break;
			case council_room:
			  printf("Testing council_room card. ");
			  Assert(result, 5, "==");
			  break;
			case feast:
			  printf("Testing feast card. ");
			  Assert(result, 4, "==");
			  break;
			case gardens:
			  printf("Testing gardens card. ");
			  Assert(result, 4, "==");
			  break;
			case mine:
			  printf("Testing mine card. ");
			  Assert(result, 5, "==");
			  break;
			case remodel:
			  printf("Testing remodel card. ");
			  Assert(result, 4, "==");
			  break;
			case smithy:
			  printf("Testing smithy card. ");
			  Assert(result, 4, "==");
			  break;
			case village:
			  printf("Testing village card. ");
			  Assert(result, 3, "==");
			  break;
			case baron:
			  printf("Testing baron card. ");
			  Assert(result, 4, "==");
			  break;
			case great_hall:
			  printf("Testing great hall card. ");
			  Assert(result, 3, "==");
			  break;
			case minion:
			  printf("Testing minion card. ");
			  Assert(result, 5, "==");
			  break;
			case steward:
			  printf("Testing steward card. ");
			  Assert(result, 3, "==");
			  break;
			case tribute:
			  printf("Testing tribute card. ");
			  Assert(result, 5, "==");
			  break;
			case ambassador:
			  printf("Testing ambassador card. ");
			  Assert(result, 3, "==");
			  break;
			case cutpurse:
			  printf("Testing cutpurse card. ");
			  Assert(result, 4, "==");
			  break;
			case embargo:
			  printf("Testing embargo card. ");
			  Assert(result, 2, "==");
			  break;
			case outpost:
			  printf("Testing outpost card. ");
			  Assert(result, 5, "==");
			  break;
			case salvager:
			  printf("Testing salvager card. ");
			  Assert(result, 4, "==");
			  break;
			case sea_hag:
			  printf("Testing sea hag card. ");
			  Assert(result, 4, "==");
			  break;
			case treasure_map:
			  printf("Testing treasure map card. ");
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
	assert(result == 0);
	//Print header for test
	printf("\n|------------------------------------------------------------------UNIT TEST 4: \"getCost\" START------------------------------------------------------------------|\n");
	printf("\n**Initialized values for game\n**Kingdom Cards: adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, sea_hag\n**Number of players: %d\n**Seed: %d\n\n", testState.numPlayers, seed);

	testGetCost(&testState);
	
	//Print test complete
	printf("\n|------------------------------------------------------------------UNIT TEST 4: \"getCost\" FINISH-----------------------------------------------------------------|\n\n");
	
return 0;
}
