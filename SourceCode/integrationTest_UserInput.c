#include <stdio.h>
#include "mapping.h"
#include "input.h"

void runTest() {
    // Initialize a Map and UserInput
    struct Map map = populateMap();
    struct UserInput input = {0};

    // Test getUserInput
    int result = getUserInput(&input, &map);
    if (result == 0) {
        printf("User chose to exit the program\n");
        return;
    }
    else if (result != 1) {
        printf("getUserInput failed\n");
        return;
    }

    // Test validation functions
    int weightResult = inputWeightValidation(input.weight);
    if (!weightResult) {
        printf("inputWeightValidation failed\n");
        return;
    }
    int sizeResult = inputSizeValidation(input.boxSize);
    if (!sizeResult) {
        printf("inputSizeValidation failed\n");
        return;
    }
    int destinationResult = inputDestinationValidation(input.destination, &map);
    if (!destinationResult) {
        printf("inputDestinationValidation failed\n");
        return;
    }

    printf("Test passed\n");
}

int main() {
    //Integration test for getUserInput, inputWeightValidation, inputSizeValidation, and inputDestinationValidation
    printf("Please enter the following test data when prompted: \n");
    // Test cases 1, TI01
	printf("Test Case 1: 50 0.5 12L\n"); //Normal case
    runTest();
    printf("\n");
    // Test cases 2, TI02
    printf("Test Case 2: 2000 0.5 12L Reenter: 500 0.5 12L\n"); //Invalid weight
    runTest();
    printf("\n");
    // Test cases 3, TI03
    printf("Test Case 3: 500 3 12L Reenter: 500 1 12L\n"); //Invalid size    
    runTest();
    printf("\n");
    // Test cases 4, TI04
	printf("Test Case 4: 500 0.5 30A Reenter: 500 0.5 12L\n"); //Invalid destination
    runTest();
    printf("\n");
    // Test cases 5, TI05
	printf("Test Case 5: 8Y Reenter: 500 0.5 8Y\n"); //Insufficient amount of inputs
    runTest();
    printf("\n");
    // Test cases 6, TI06
	printf("Test Case 6: 0 0 x\n"); //Normal case, exit program
    runTest();
    printf("Integration test for input validation finished");


    return 0;
}
