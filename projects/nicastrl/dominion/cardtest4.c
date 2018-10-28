/*
carttest4 is a test for the adventurer card in Dominion.c
Louis Nicastro
Due 10/28/18
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//global check for pass/fail
int isPassing = 1;
int allTestsPassed = 1; //switch to false if any fail

//helper assert
int localAssert(int, int);
void evaluateOutcome(int);

int main() {
    struct gameState gameState;
    int outcome, i;
    int beforeTreasureCount, afterTreasureCount = 0;
    
    //initialize game with 4 playes, kingdomcards, seed, and state
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    initializeGame(4, k, 50, &gameState);
    
    printf("\n\n****** Entering adventurer card Test ****** \n\n");
    
    gameState.deckCount[1] = 10;
    gameState.handCount[1] = 10;
    gameState.discardCount[1] = 10;
    //fill everything with copper first
    for (i = 0; i<10;i++){
        gameState.deck[1][i] = copper;
        gameState.discard[1][i] = copper;
        gameState.hand[1][i] = copper;
    }
    gameState.hand[1][0] = adventurer; //force adventurer to test

    printf("\n****** T1: Pre-play state checks ******\n");
    
	for(i = 0; i < gameState.handCount[1]; i++){
		if(gameState.hand[1][i] == copper || gameState.hand[1][i] == silver || gameState.hand[1][i] == gold){
			beforeTreasureCount++;
		}
	}
    
    printf("\n****** T1a: Deck ******\n");
     printf("Deck Count expected: %d\nDeck Count actual: %d\n", 10, gameState.deckCount[1]);
    
    outcome = localAssert(10, gameState.deckCount[1]);
    evaluateOutcome(outcome);
    if(isPassing)
        printf("\n          ** TEST PASSED **\n");
    else
        printf("\n          ** TEST FAILED ** \n");
    isPassing = 1;
    
    
    printf("\n****** T1b: handCount ******\n");
    
     printf("hand Count expected: %d\nHand Count actual: %d\n", 10, gameState.handCount[1]);
    outcome = localAssert(10, gameState.handCount[1]);
    evaluateOutcome(outcome);
    if(isPassing)
        printf("\n          ** TEST PASSED **\n");
    else
        printf("\n          ** TEST FAILED ** \n");
    isPassing = 1;
    
    
    printf("\n****** T1c: discardCount ******\n");
    
     printf("discard Count expected: %d\nDiscard Count actual: %d\n", 10, gameState.discardCount[1]);
    outcome = localAssert(10, gameState.discardCount[1]);
    evaluateOutcome(outcome);
    if(isPassing)
        printf("\n          ** TEST PASSED **\n");
    else
        printf("\n          ** TEST FAILED ** \n");
    isPassing = 1;
    
    
    printf("\n****** T1d: numActions ******\n");
    
     printf("actuion Count expected: %d\nAction Count actual: %d\n", 1, gameState.numActions);
    outcome = localAssert(1, gameState.numActions);
    evaluateOutcome(outcome);
    if(isPassing)
        printf("\n          ** TEST PASSED **\n");
    else
        printf("\n          ** TEST FAILED ** \n");
    isPassing = 1;
    
    //play card 
    playCard(0,0,0,0,&gameState);
    
    //then repeat all the above tests 
    printf("\n****** T2: Post-play state checks ******\n");
    printf("\n****** T2a: Deck ******\n");
     printf("Deck Count expected: %d\nDeck Count actual: %d\n", 10, gameState.deckCount[1]);
    
    outcome = localAssert(10 -0, gameState.deckCount[1]);
    evaluateOutcome(outcome);
    if(isPassing)
        printf("\n          ** TEST PASSED **\n");
    else
        printf("\n          ** TEST FAILED ** \n");
    isPassing = 1;
    
    
    printf("\n****** T2b: handCount ******\n");
    
     printf("hand Count expected: %d\nHand Count actual: %d\n", 10, gameState.handCount[1]);
    outcome = localAssert(10 + 0, gameState.handCount[1]);
    evaluateOutcome(outcome);
    if(isPassing)
        printf("\n          ** TEST PASSED **\n");
    else
        printf("\n          ** TEST FAILED ** \n");
    isPassing = 1;
    
    
    printf("\n****** T2c: numActions ******\n");
    
     printf("actuion Count expected: %d\nAction Count actual: %d\n", 1, gameState.numActions);
    outcome = localAssert(1, gameState.numActions);
    evaluateOutcome(outcome);
    if(isPassing)
        printf("\n          ** TEST PASSED **\n");
    else
        printf("\n          ** TEST FAILED ** \n");
    isPassing = 1;
    
    
    printf("\n****** T3: Played Card count size ******\n");
     printf("played card Count expected: %d\nPlayed card count Count actual: %d\n", 0, gameState.playedCardCount);
    outcome = localAssert(0, gameState.playedCardCount);
    evaluateOutcome(outcome);
    if(isPassing)
        printf("\n          ** TEST PASSED **\n");
    else
        printf("\n          ** TEST FAILED ** \n");
    isPassing = 1;
    
    
    printf("\n****** T4: Played Card count size ******\n");
    


	for(i = 0; i < gameState.handCount[1]; i++){
		if(gameState.hand[1][i] == copper || gameState.hand[1][i] == silver || gameState.hand[1][i] == gold){
			afterTreasureCount++;
		}
	}
	
    printf("Treasure Count expected: %d\nTreasure count Count actual: %d\n", beforeTreasureCount - 2, afterTreasureCount);
    outcome = localAssert(beforeTreasureCount - 2, afterTreasureCount);
    evaluateOutcome(outcome);
    if(isPassing)
        printf("\n          ** TEST PASSED **\n");
    else
        printf("\n          ** TEST FAILED ** \n");
    isPassing = 1;
    
    
    printf("\n****** adventurer Function Final result ******\n");
    if(allTestsPassed)
        printf("\n   ** ALL TEST PASSED **\n");
    else
        printf("\n   ** A TEST FAILED ** \n");
    
    return 0;    
}

//a local assert as requested in spec
int localAssert(int goal, int actual) {
    return goal == actual;
}

//function that checks if a value is passing or not
void evaluateOutcome(int outcome) {
    if (outcome == 1)
        isPassing = 1;
    else {
        isPassing = 0;
        allTestsPassed = 0;
    }

}