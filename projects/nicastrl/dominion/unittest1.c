/*
Unittest1 is a test for function isGameOver in Dominion.c
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
int isPassing = 0;
int allTestsPassed = 1; //switch to false if any fail

//helper assert
int localAssert(int, int);
void evaluateOutcome(int);

int main() 
{
    struct gameState gameState;
    int i, outcome;
    
    //initialize game with 2 playes, kingdomcards, seed, and state
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    initializeGame(2, k, 50, &gameState);
    
    printf("\n\n****** Entering isGameOver Test ****** \n\n");
    printf("\n****** T1: Game Ends when Provence Cards Gone ******\n");
    
    gameState.supplyCount[province] = 0;
    outcome = localAssert(1, isGameOver(&gameState)); //expect the game to be over
    evaluateOutcome(outcome);
    
    if(isPassing)
        printf("\n          ** TEST PASSED **\n");
    else
        printf("\n          ** TEST FAILED ** \n");
        
    isPassing = 0;
    
    
    printf("\n****** T2: Game Still Active when Provence Cards Exists ******\n");
    
    for (i = 1; i <= MAX_DECK; i++) {
        //printf("For %d province cards...\n", i);
        gameState.supplyCount[province] = i;
        outcome = localAssert(0, isGameOver(&gameState)); 
        evaluateOutcome(outcome);
    }
    if(isPassing && allTestsPassed)
        printf("\n          ** TEST PASSED **\n");
    else
        printf("\n          ** TEST FAILED ** \n");
        
    isPassing = 0;
    
    
    printf("\n****** T2: Game Ends When Supply Piles End ******\n");
    
    for (i = 0; i <5; i++) {
        gameState.supplyCount[i] = 0;

    }
    outcome = localAssert(1, isGameOver(&gameState)); 
    evaluateOutcome(outcome);
    if(isPassing)
        printf("\n          ** TEST PASSED **\n");
    else
        printf("\n          ** TEST FAILED ** \n");
        
    isPassing = 0;
    
    
    
    printf("\n****** isGameOver Function Final result ******\n");
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