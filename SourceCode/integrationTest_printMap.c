#include <stdio.h>
#include "mapping.h"

void testBlueLine()
{
	struct Map baseMap = populateMap();
	struct Route blueRoute = getBlueRoute();
	struct Map routeMap = addRoute(&baseMap, &blueRoute);

	printMap(&routeMap, 1, 1);
}

void testGreenLine()
{
	struct Map baseMap = populateMap();
	struct Route greenRoute = getGreenRoute();
	struct Map routeMap = addRoute(&baseMap, &greenRoute);

	printMap(&routeMap, 1, 1);
}

void testYellowLine()
{
	struct Map baseMap = populateMap();
	struct Route yellowRoute = getYellowRoute();
	struct Map routeMap = addRoute(&baseMap, &yellowRoute);

	printMap(&routeMap, 1, 1);
}

int main()
{
	//Integration test for printMap, addRoute, getBlueRoute and populateMap
	printf("Blue Line: \n");
	testBlueLine();
	printf("\n");

	//Integration test for printMap, addRoute, getGreenRoute and populateMap
	printf("Green Line: \n");
	testGreenLine();
	printf("\n");

	//Integration test for printMap, addRoute, getYellowRoute and populateMap
	printf("Yellow Line: \n");
	testYellowLine();
	printf("\n");

	return 0;
}