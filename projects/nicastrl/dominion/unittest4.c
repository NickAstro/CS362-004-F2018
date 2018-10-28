/*
Unittest4 is a test for function numHandCards in Dominion.c
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

int main() 
{
    struct gameState gameState;
    gameState.coins = 0;
    int i;
    
    //initialize game with 2 playes, kingdomcards, seed, and state
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    initializeGame(2, k, 50, &gameState);
    
    printf("\n\n****** Entering numHandCards Test ****** \n\n");
    printf("\n****** T1: Testing for mis-matched hands ******\n");
    for(i = 0; i < MAX_HAND; i++) {
        gameState.handCount[0] = i + 2;
        if(numHandCards(&gameState) == i) {
            //test fails
            allTestsPassed = 0;
        }
    }
    
    if(isPassing)
        printf("\n          ** TEST PASSED **\n");
    else
        printf("\n          ** TEST FAILED ** \n");
    isPassing = 1;    
    
    
    printf("\n****** T2: Testing for matched hands ******\n");
    for(i = 0; i < MAX_HAND; i++) {
        gameState.handCount[0] = i;
        if(numHandCards(&gameState) != i) {
            //test fails
            allTestsPassed = 0;
        }
    }
    
    if(isPassing)
        printf("\n          ** TEST PASSED **\n");
    else
        printf("\n          ** TEST FAILED ** \n");
    isPassing = 1;    
    
    
    
    printf("\n****** numHandCards Function Final result ******\n");
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