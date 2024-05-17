#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"
#include "input.h"

struct Route shortestPathByEachPointFromRoute(const struct Route* route, const struct UserInput* input, const struct Map* map);
void addWeightSize(struct UserInput* input, int* weight, double* size);

int main(void)
{
	struct UserInput input = { 0 };
	struct Map baseMap = populateMap();
	struct Route blueRoute = getBlueRoute(), greenRoute = getGreenRoute(), yellowRoute = getYellowRoute();
	struct Route blueShortest = { 0 }, yellowShortest = { 0 }, greenShortest = { 0 }, bestPath = { 0 };
	const struct Route reset = { 0 };
	int blueWeight = 0, yellowWeight = 0, greenWeight = 0;
	double blueSize = 0, yellowSize = 0, greenSize = 0;

	printf("=================\n");
	printf("Seneca College Deliveries\n");
	printf("=================\n");

	while (getUserInput(&input, &baseMap)) {
		bestPath = reset;
		blueShortest = shortestPathByEachPointFromRoute(&blueRoute, &input, &baseMap);
		yellowShortest = shortestPathByEachPointFromRoute(&yellowRoute, &input, &baseMap);
		greenShortest = shortestPathByEachPointFromRoute(&greenRoute, &input, &baseMap);

		while (input.weight != 0 && input.boxSize != 0 && !(blueShortest.numPoints == MAX_ROUTE && yellowShortest.numPoints == MAX_ROUTE && greenShortest.numPoints == MAX_ROUTE)) {
			if (blueShortest.numPoints <= yellowShortest.numPoints && blueShortest.numPoints <= greenShortest.numPoints) {
				if ((blueWeight + input.weight) <= MAX_WEIGHT && (blueSize + input.boxSize) <= MAX_BOX_SIZE) {
					bestPath = blueShortest;
					bestPath.routeSymbol = BLUE;
					addWeightSize(&input, &blueWeight, &blueSize);
				}
				else {
					blueShortest.numPoints = MAX_ROUTE;
				}
			}
			else if (yellowShortest.numPoints <= greenShortest.numPoints) {
				if ((yellowWeight + input.weight) <= MAX_WEIGHT && (yellowSize + input.boxSize) <= MAX_BOX_SIZE) {
					bestPath = yellowShortest;
					bestPath.routeSymbol = YELLOW;
					addWeightSize(&input, &yellowWeight, &yellowSize);
				}
				else {
					yellowShortest.numPoints = MAX_ROUTE;
				}
			}
			else {
				if ((greenWeight + input.weight) <= MAX_WEIGHT && (greenSize + input.boxSize) <= MAX_BOX_SIZE) {
					bestPath = greenShortest;
					bestPath.routeSymbol = GREEN;
					addWeightSize(&input, &greenWeight, &greenSize);
				}
				else {
					greenShortest.numPoints = MAX_ROUTE;
				}
			}
		}
		if (input.weight != 0 && input.boxSize != 0) {
			printMessage(2, &bestPath);
		}
		else {
			printMessage(bestPath.numPoints <= 2, &bestPath);
		}
	}

	printf("Thanks for shipping with Seneca!\n");

	return 0;
}

struct Route shortestPathByEachPointFromRoute(const struct Route* route, const struct UserInput* input, const struct Map* map) {
	struct Route shortestRoute = { 0 }, compare = { 0 };

	shortestRoute = shortestPath(map, route->points[0], input->destination);
	for (int i = 1; i < route->numPoints; i++) {
		compare = shortestPath(map, route->points[i], input->destination);
		if (compare.numPoints < shortestRoute.numPoints) {
			shortestRoute = compare;
		}
	}

	return shortestRoute;
}

void addWeightSize(struct UserInput* input, int* weight, double* size) {
	*weight += input->weight;
	*size += input->boxSize;
	input->weight = 0;
	input->boxSize = 0.0;
}