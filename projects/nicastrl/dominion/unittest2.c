/*
Unittest2 is a test for function getCost in Dominion.c
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
    int i, outcome;
    
    //giant array of values expected in order as determined by the getcost card requirement and card number enum
    int expectedValues[27] = {0, 2, 5, 8, 0, 3, 6, 6, 5, 4, 4, 5, 4, 4, 3, 4, 3, 5, 3, 5, 3, 4, 2, 5, 4, 4, 4};
    
    //no game initialization required.
    
    
    printf("\n\n****** Entering getCardCost Test ****** \n\n");
    printf("\n****** T1: Test All Cards and values ******\n");
    
    for (i = 0; i < 27; i++)
    {
        outcome = localAssert(expectedValues[i], getCost(i));
        if(outcome == 0) {
            allTestsPassed = 0;
        }
    }
    if(allTestsPassed)
        printf("\n          ** TEST PASSED **\n");
    else
        printf("\n          ** TEST FAILED ** \n");
        
    
    printf("\n****** T2: Check that impossible card returns -1 ******\n");
    outcome = localAssert(-1, getCost(35));
    evaluateOutcome(outcome);
    if(isPassing)
        printf("\n          ** TEST PASSED **\n");
    else
        printf("\n          ** TEST FAILED ** \n");
        
    
        
    isPassing = 1;
    printf("\n****** T3: Check that curse and estate return different values ******\n");
    if(getCost(0)!= getCost(1)){
        outcome = 1;
    }
    else
        outcome = 0;
    evaluateOutcome(outcome);
    if(isPassing)
        printf("\n          ** TEST PASSED **\n");
    else
        printf("\n          ** TEST FAILED ** \n");

    
    
    printf("\n****** getCardCost Function Final result ******\n");
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