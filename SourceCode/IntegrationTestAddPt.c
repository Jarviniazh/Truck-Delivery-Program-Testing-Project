#include <stdio.h>
#include "mapping.h"

int main() {
	struct Map baseMap = populateMap();
	struct Route Test1 = { 0 };
	struct Route Test2 = { 0 };
	
	struct Point np = { 2,6 };
	int r = 2;
	int c = 6;

	addPointToRouteIfNot(&Test1, r, c, np);
	printf("Points: %d\n", Test1.numPoints);
	if (Test1.numPoints == 0) {
		printf("Integartion test 1 passed!\n");
	}
	else {
		printf("Integartion test 1 failed!\n");
	}



	int r2 = 3;
	int c2 = 9;
	addPointToRouteIfNot(&Test2, r2, c2, np);

	printf("Points: %d\n", Test2.numPoints);
	if (Test2.numPoints == 1) {
		printf("Integartion test 2 passed!\n");
	}
	else {
		printf("Integartion test 2 failed!\n");
	}
}
