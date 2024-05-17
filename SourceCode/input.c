#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "input.h"


/**
 * Get the user input and validate it
 * @return - True if user input 0 0 x to exit the program. False if user input a valid input.
 */
int getUserInput(struct UserInput* input, const struct Map* map)
{
    int success = 0, exit = 0;
    do
    {
        char destination[4];
        // Prompt user for input
        printf("Enter shipment weight, box size and destination (0 0 x to stop): ");
        if (scanf("%d %lf %3s", &input->weight, &input->boxSize, &destination) == 3) {
            convertStringToPoint(&input->destination, destination);

            // Check if user wants to exit
            if (input->weight == 0 && input->boxSize == 0 && input->destination.row == 'x' && input->destination.col == '\0') {
                exit = 1;
            }
            else {
                if (!inputWeightValidation(input->weight)) {
                    printf("Invalid weight (must be 1 - %d Kg.)\n", MAX_WEIGHT);
                }
                if (!inputSizeValidation(input->boxSize)) {
                    printf("Invalid size\n");
                }
                if (!inputDestinationValidation(input->destination, map)) {
                    printf("Invalid destination\n");
                }
                if (inputWeightValidation(input->weight) && inputSizeValidation(input->boxSize) && inputDestinationValidation(input->destination, map)) {
                    success = 1;
                }
            }
        }
        else {
            printf("Invalid Input\n");
            while (getchar() != '\n') {}
            input->weight = 0;
            input->boxSize = 0;
            input->destination.row = 0;
            input->destination.col = 0;
        }

    } while (!success && !exit); // Repeat until all inputs are valid

    return !exit; // Return validated inputs
}

/**
 * Convert string to struct Point
 * @param destination - the point to store the converted value
 * @param source - the string need to convert
 */
void convertStringToPoint(struct Point* dest, const char* source) {
    // Parse row from point
    dest->row = 0;
    int i = 0;
    for (i = 0; isdigit(source[i]); i++) {
        dest->row = dest->row * 10 + (source[i] - '0');
    }
    dest->row--;
    if (i == 0) {
        dest->row = source[i];
        dest->col = '\0';
    }
    else {
        dest->col = toupper(source[i]) - 'A';
    }
}

/**
 * Validate the user input of the package weight
 * @param weight - the original weight of the package input by the user
 * @return - True if the weight is valid and false if the weight is invalid
 */
int inputWeightValidation(const int weight)
{
    // Check if weight is within valid range
    return weight > 0 && weight <= MAX_WEIGHT;
}

/**
 * Validate the user input of the box size
 * @param size - the original size of the package input by the user
 * @return - True if the size is valid and false if the size is invalid
 */
int inputSizeValidation(const double size)
{
    // Check if box size is valid
    return size == SMALL_BOX || size == MEDIUM_BOX || size == LARGE_BOX;
}

/**
 * Validate the user input of the destination
 * @param destination - the original destination of the package input by the user
 * @param map - the map that we define the point is valid or not.
 * @return - the destination of the package after validation or {-1, -1} if the destination is invalid
 */
int inputDestinationValidation(const struct Point point, const struct Map* map)
{
    return point.row >= 0 && point.row < map->numRows && point.col >= 0 && point.col < map->numCols && map->squares[point.row][point.col] == 1;
}

/**
 * Print message for choosing the when truck to put the box to
 * @param selection - select the sentence format for the message
 * @param route - provide information of the route to print
 */
void printMessage(int selection, const struct Route* route) {
    switch (selection) {
    case 0:
        printf("Ship on ");
        switch (route->routeSymbol) {
        case BLUE:
            printf("BLUE");
            break;
        case GREEN:
            printf("GREEN");
            break;
        case YELLOW:
            printf("YELLOW");
            break;
        }
        printf(" LINE, divert: ");
        for (int i = 0; i < route->numPoints; i++) {
            printf("%d%c", route->points[i].row + 1, 'A' + route->points[i].col);
            if (i < route->numPoints-1) {
                printf(",");
            }
            else {
                printf("\n");
            }
        }
        break;
    case 1:
        printf("Ship on ");
        switch (route->routeSymbol) {
        case BLUE:
            printf("BLUE");
            break;
        case GREEN:
            printf("GREEN");
            break;
        case YELLOW:
            printf("YELLOW");
        }
        printf(" LINE, no diversion\n");
        break;
    case 2:
        printf("Ships tomorrow\n");
        break;
    }
}   