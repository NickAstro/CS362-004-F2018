/*
carttest2 is a test for the villiage card in Dominion.c
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
    
    printf("\n\n****** Entering adventure card Test ****** \n\n");
    //setup parts of game -
    gameState.deckCount[0] = 10;
    gameState.handCount[0] = 10;
    gameState.discardCount[0] = 10;
    gameState.hand[0][0] = village; //force village to test

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
    
    
    printf("\n****** T1d: numActions ******\n");
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
    printf("Deck Count expected: %d\nDeck Count actual: %d\n", 9, gameState.deckCount[0]);
    outcome = localAssert(9, gameState.deckCount[0]);
    evaluateOutcome(outcome);
    if(isPassing)
        printf("\n          ** TEST PASSED **\n");
    else
        printf("\n          ** TEST FAILED ** \n");
    isPassing = 1;
    
    
    printf("\n****** T2b: handCount ******\n");
    printf("Hand Count expected: %d\nhand count actual: %d\n", 10, gameState.handCount[0]);
    outcome = localAssert(10, gameState.handCount[0]);
    evaluateOutcome(outcome);
    if(isPassing)
        printf("\n          ** TEST PASSED **\n");
    else
        printf("\n          ** TEST FAILED ** \n");
    isPassing = 1;
    
    
    printf("\n****** T2c: discardCount ******\n");
    printf("discard expected: %d\ndiscard actual: %d\n", 11, gameState.discardCount[0]);
    outcome = localAssert(11, gameState.discardCount[0]);
    evaluateOutcome(outcome);
    if(isPassing)
        printf("\n          ** TEST PASSED **\n");
    else
        printf("\n          ** TEST FAILED ** \n");
    isPassing = 1;
 
 
    printf("\n****** T2d: numActions ******\n");
    printf("Num actions expected: %d\nNum actions actual: %d\n", 3, gameState.numActions);
    outcome = localAssert(3, gameState.numActions);
    evaluateOutcome(outcome);
    if(isPassing)
        printf("\n          ** TEST PASSED **\n");
    else
        printf("\n          ** TEST FAILED ** \n");
    isPassing = 1;
 
     
    printf("\n****** village Function Final result ******\n");
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