#include <stdio.h>
#include "mapping.h"

int main() {
	struct Map baseMap = populateMap();
	struct Route Test1 = { 0 };
	struct Route Test2 = { 0 };
	struct Route Test3 = { 0 };

	struct Point start = { 0, 0 };
	struct Point dest = { 2, 5 };
	Test1 = shortestPath(&baseMap, start, dest);
	printf("Points: %d\n", Test1.numPoints);
	if (Test1.numPoints == 10) {
		printf("Integartion test 1 passed!\n");
	}
	else {
		printf("Integartion test 1 failed!\n");
	}

	start.row = 17;
	start.col = 21;
	dest.row = 7;
	dest.col = 24;
	Test2 = shortestPath(&baseMap, start, dest);
	printf("Points: %d\n", Test2.numPoints);
	if (Test2.numPoints == 16) {
		printf("Integartion test 2 passed!\n");
	}
	else {
		printf("Integartion test 2 failed!\n");
	}

	start.row = 9;
	start.col = 2;
	dest.row = 21;
	dest.col = 11;
	Test3 = shortestPath(&baseMap, start, dest);
	printf("Points: %d\n", Test3.numPoints);
	for (int i = 0; i < Test3.numPoints; i++) {
		printf("%d%c\n", Test3.points[i].row + 1, 'A' + Test3.points[i].col);
	}
	if (Test3.numPoints == 24) {
		printf("Integartion test 2 passed!\n");
	}
	else {
		printf("Integartion test 2 failed!\n");
	}

	return 0;
}