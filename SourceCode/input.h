#pragma once

#include "mapping.h"

#define MAX_WEIGHT 1200
#define SMALL_BOX 0.5
#define MEDIUM_BOX 1.0
#define LARGE_BOX 5.0
#define MAX_BOX_SIZE 50.0

/*
 * UserInput struct stores the user input
 * weight - the weigth of the package
 * boxSize - the size of the box
 * destination - the destination of the package
 */
struct UserInput {
    int weight;
    double boxSize;
    struct Point destination;
};

/**
 * Get the user input and validate it
 * @param input - A struct stores the user input data
 * @param map - A map for further validation use
 * @return - Return 1 if user input 0 0 x to exit the program, 0 if user input a valid input.
 */
int getUserInput(struct UserInput* input, const struct Map* map);

/**
 * Convert string to struct Point
 * @param destination - The point of storing the converted value
 * @param source - The string needs to convert
 */
void convertStringToPoint(struct Point* destination, const char* source);

/**
 * Validate the user input of the package weight
 * @param weight - the original weight of the package input by the user
 * @return - True if the weight is valid and false if the weight is invalid
 */
int inputWeightValidation(const int weight);

/**
 * Validate the user input of the box size
 * @param size - the original size of the package input by the user
 * @return - True if the size is valid and false if the size is invalid
 */
int inputSizeValidation(const double size);

/**
 * Validate the user input of the destination
 * @param destination - the original destination of the package input by the user
 * @param map - the map that we define the point is valid or not.
 * @return - the destination of the package after validation or {-1, -1} if the destination is invalid
 */
int inputDestinationValidation(const struct Point point, const struct Map* map);

/**
 * Print message for choosing the when truck to put the box to
 * @param selection - select the sentence format for the message
 * @param route - provide information of the route to print
 */
void printMessage(int selection, const struct Route* route);