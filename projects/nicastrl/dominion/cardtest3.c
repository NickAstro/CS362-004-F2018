/*
carttest3 is a test for the councilroom card in Dominion.c
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
    
    //initialize game with 4 playes, kingdomcards, seed, and state
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    initializeGame(4, k, 50, &gameState);
    
    printf("\n\n****** Entering council Room card Test ****** \n\n");
    //setup parts of game - Testing with 2nd player first.
    
    gameState.deckCount[1] = 10;
    gameState.handCount[1] = 10;
    gameState.discardCount[1] = 10;
    gameState.hand[1][0] = council_room; //force council room to test
    
    //starting with player 2
    gameState.whoseTurn = 1;
    printf("\n****** whose turn****** %d\n", gameState.whoseTurn);
    

    printf("\n****** T1: Pre-play state checks ******\n");
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
    
    printf("\n****** T1e: numbuys ******\n");
    
     printf("Buy Count expected: %d\nBuy Count actual: %d\n", 1, gameState.numBuys);
    outcome = localAssert(1, gameState.numBuys);
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
     printf("Deck Count expected: %d\nDeck Count actual: %d\n", 6, gameState.deckCount[1]);
    
    outcome = localAssert(10 -4, gameState.deckCount[1]);
    evaluateOutcome(outcome);
    if(isPassing)
        printf("\n          ** TEST PASSED **\n");
    else
        printf("\n          ** TEST FAILED ** \n");
    isPassing = 1;
    
    
    printf("\n****** T2b: handCount ******\n");
    
     printf("hand Count expected: %d\nHand Count actual: %d\n", 13, gameState.handCount[1]);
    outcome = localAssert(10 + 4 - 1, gameState.handCount[1]);
    evaluateOutcome(outcome);
    if(isPassing)
        printf("\n          ** TEST PASSED **\n");
    else
        printf("\n          ** TEST FAILED ** \n");
    isPassing = 1;
    
    
    printf("\n****** T2c: discardCount ******\n");
    
     printf("discard Count expected: %d\nDiscard Count actual: %d\n", 11, gameState.discardCount[1]);
    outcome = localAssert(11, gameState.discardCount[1]);
    evaluateOutcome(outcome);
    if(isPassing)
        printf("\n          ** TEST PASSED **\n");
    else
        printf("\n          ** TEST FAILED ** \n");
    isPassing = 1;
    
    
    printf("\n****** T2d: numActions ******\n");
    
     printf("actuion Count expected: %d\nAction Count actual: %d\n", 0, gameState.numActions);
    outcome = localAssert(0, gameState.numActions);
    evaluateOutcome(outcome);
    if(isPassing)
        printf("\n          ** TEST PASSED **\n");
    else
        printf("\n          ** TEST FAILED ** \n");
    isPassing = 1;
    
    printf("\n****** T2e: numbuys ******\n");
    
     printf("Buy Count expected: %d\nBuy Count actual: %d\n", 2, gameState.numBuys);
    outcome = localAssert(2, gameState.numBuys);
    evaluateOutcome(outcome);
    if(isPassing)
        printf("\n          ** TEST PASSED **\n");
    else
        printf("\n          ** TEST FAILED ** \n");
    isPassing = 1;
    
    
    printf("\n****** T3: Post-play Other Player card count check ******\n");
    for(i = 0; i < 4; i++){
        if(i != 1) {
            printf("\n****** T3 Player %d: card Count ******\n", i + 1);
    
            printf("Card Count expected: %d\nCard Count actual: %d\n", 1, gameState.handCount[i]);
            outcome = localAssert(1, gameState.handCount[i]);
            evaluateOutcome(outcome);
            if(isPassing)
                printf("\n          ** TEST PASSED **\n");
            else
                printf("\n          ** TEST FAILED ** \n");
            isPassing = 1;
            
        }
    }
     
    printf("\n****** council_room Function Final result ******\n");
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