/*
carttest1 is a test for the smithy card in Dominion.c
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
    int outcome;
    
    //initialize game with 2 playes, kingdomcards, seed, and state
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    initializeGame(2, k, 50, &gameState);
    
    printf("\n\n****** Entering smithy card Test ****** \n\n");
    //setup parts of game -
    gameState.deckCount[0] = 10;
    gameState.handCount[0] = 10;
    gameState.discardCount[0] = 10;
    gameState.hand[0][0] = smithy; //force smithy to test

    printf("\n****** T1: Pre-play state checks ******\n");
    printf("\n****** T1a: Deck ******\n");
    outcome = localAssert(10, gameState.deckCount[0]);
    evaluateOutcome(outcome);
    if(isPassing)
        printf("\n          ** TEST PASSED **\n");
    else
        printf("\n          ** TEST FAILED ** \n");
    isPassing = 1;
    
    
    printf("\n****** T1b: handCount ******\n");
    outcome = localAssert(10, gameState.handCount[0]);
    evaluateOutcome(outcome);
    if(isPassing)
        printf("\n          ** TEST PASSED **\n");
    else
        printf("\n          ** TEST FAILED ** \n");
    isPassing = 1;
    
    
    printf("\n****** T1c: discardCount ******\n");
    outcome = localAssert(10, gameState.discardCount[0]);
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
    outcome = localAssert(7, gameState.deckCount[0]);
    evaluateOutcome(outcome);
    if(isPassing)
        printf("\n          ** TEST PASSED **\n");
    else {
        printf("\n          ** TEST FAILED ** \n");
        printf("\n          ** expecting %d  received %d ** \n", 7, gameState.deckCount[0]);
    }
    isPassing = 1;
    
    
    printf("\n****** T2b: handCount ******\n");
    outcome = localAssert(12, gameState.handCount[0]);
    evaluateOutcome(outcome);
    if(isPassing)
        printf("\n          ** TEST PASSED **\n");
    else {
        printf("\n          ** TEST FAILED ** \n");
        printf("\n          ** expecting %d  received %d ** \n", 12, gameState.handCount[0]);
        
    }
    isPassing = 1;
    
    
    printf("\n****** T2c: discardCount ******\n");
    outcome = localAssert(11, gameState.discardCount[0]);
    evaluateOutcome(outcome);
    if(isPassing)
        printf("\n          ** TEST PASSED **\n");
    else {
        printf("\n          ** TEST FAILED ** \n");
        printf("\n          ** expecting %d  received %d ** \n", 11, gameState.discardCount[0]);
        
    }
    isPassing = 1;
 
 
 
     
    printf("\n****** smithy Function Final result ******\n");
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