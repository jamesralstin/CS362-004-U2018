#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <math.h>

void testSeaHag(int player, struct gameState *G){
	
	
	
	printf("Current player is %d\n", player);
	

}

int main(){
	
	struct gameState testGame;
	int i, player, n;
	
	for(n = 0; n < 2000; n++){
		for(i = 0; i < sizeof(struct gameState); i++){
			
			((char*)&testGame)[i] = floor(Random()*256);
		
		}
		player = floor(Random()*2);
		testGame.handCount[player] = floor(Random()*MAX_HAND);
		testGame.deckCount[player] = floor(Random()*MAX_DECK);
		testGame.discardCount[player] = floor(Random()*MAX_DECK);
	
		testSeaHag(player, &testGame);
	
	}
	printf("Verifying source.\n");

return 0;
}
