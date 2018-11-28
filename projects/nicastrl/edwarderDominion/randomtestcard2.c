/*
randomtestcard2.c is a random tester for the smithy card in Dominion.c
Louis Nicastro
Due 11/14/18
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include <math.h>
#include <time.h>
#include <assert.h>

#define NUM_TESTS 1500

typedef struct gameState gameState;
int getHandPosition(int p, gameState *g, enum CARD card);

int main()
{
    printf("\n********Entering Smithy random tester******** \n");
    
    srand(time(NULL));
    
    int numPassed = 0, numFailed = 0;
    int cards[10] = {minion, mine, cutpurse, sea_hag, tribute, smithy, adventurer, gardens, embargo, village};
    int i, player, numPlayers, randomSeed, foundFailure;
    
    gameState startState, endState;

    for (i = 0; i < NUM_TESTS; i++)
    {
        //reset any failures back to zero for each loop
        foundFailure = 0;
        player = 1;
        
        printf("** Entering Test Num: %d\n", i);
        
        //randomize the seed, players
        randomSeed = rand() % 50 + 1;
        numPlayers = rand() % 4 + 1;
        
        //int game with random input
        initializeGame(numPlayers, cards, randomSeed, &startState); 
            
        //now randomize the starting state (deck, discard, and hand)
        startState.handCount[1] = rand() % MAX_HAND;
        startState.deckCount[1] = rand() % MAX_DECK;
        startState.discardCount[1] = rand() % MAX_DECK;
        
        int k;
        for (k = 0; k <startState.deckCount[1]; k++) 
            startState.deck[1][k] = rand() % 25;
        for (k = 0; k <startState.discardCount[1]; k++) 
            startState.discard[1][k] = rand() % 25;
        for (k = 0; k <startState.handCount[1]; k++) 
            startState.hand[1][k] = rand() % 25;
            
        startState.whoseTurn = player; 

        memcpy(&endState, &startState, sizeof(struct gameState));
        
        int smithyLoc = getHandPosition(player, &startState, smithy);
        
        //play smithy if exists
        if (smithyLoc != -1)
            playCard(smithyLoc, 0, 0, 0, &endState);
        //otherwise, throw error
        else 
        {
            numFailed += 1;
            printf("ERROR: No Smithy in hand\n");
            continue; //so we don't double count this failure
        }
        
    {
        // Test that smithy drew the proper number of cards
        if (endState.handCount[player] != startState.handCount[player] + 2)
        {
            foundFailure = 1;
            printf("FAILED for hand count... Expected: %d Actual: %d\n", startState.handCount[player] + 2, endState.handCount[player]);
        }
       // check for discard pile count
       if(endState.discardCount[player] != startState.discardCount[player] + 1 ){
           foundFailure = 1;
           printf("FAILED for discard count... Expected: %d Actual: %d\n", startState.discardCount[player] + 1, endState.discardCount[player]);
       }
        
        //track final metrics for reporting purposes
        if (foundFailure == 1)
            numFailed += 1;
        else
            numPassed += 1;
            
    }
        }

    printf("\n *** TEST RESULTS *** \n");
    printf("Tests passed: %d\n", numPassed);
    printf("Tests failed: %d\n", numFailed);
    
    return 0;
}

//function to find the hand position of a desired card by card enum
int getHandPosition(int p, gameState *g, enum CARD card) {
	int i;
	for (i = 0; i < g->handCount[p]; i++) {
		if (g->hand[p][i] == card)
			return i;
	}
	return -1;
}