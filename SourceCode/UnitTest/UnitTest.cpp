#include "pch.h"
#include "CppUnitTest.h"
#include "input_r.h"
#include "mapping_r.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	//Blackbox: inputWeightValidation
	TEST_CLASS(WeightValidationFunction_B)
	{
	public:

		TEST_METHOD(numberInRange)
		{
			int test = inputWeightValidation(500);
			Assert::AreEqual(1, test);
		}

		TEST_METHOD(numberExceedRange)
		{
			int test = inputWeightValidation(1500);
			Assert::AreEqual(0, test);
		}

		TEST_METHOD(negativeNumber)
		{
			int test = inputWeightValidation(-100);
			Assert::AreEqual(0, test);
		}

		TEST_METHOD(zeroValue)
		{
			int test = inputWeightValidation(0);
			Assert::AreEqual(0, test);
		}
	};

	//Blackbox: inputSizeValidation 
	TEST_CLASS(SizeValidation_B)
	{
	public:

		TEST_METHOD(optionInList)
		{
			int test = inputSizeValidation(1);
			Assert::AreEqual(1, test);
		}

		TEST_METHOD(optionNotInList)
		{
			int test = inputSizeValidation(10);
			Assert::AreEqual(0, test);
		}

		TEST_METHOD(zeroSize)
		{
			int test = inputSizeValidation(0);
			Assert::AreEqual(0, test);
		}
	};

	//Blackbox: eqPt
	TEST_CLASS(eqPt_B)
	{
	public:
		TEST_METHOD(twoSamePoint)
		{
			int test = eqPt({1,1}, {1,1});
			Assert::AreEqual(1, test);
		}
		TEST_METHOD(twoDiffPoint)
		{
			int test = eqPt({ 1,1 }, { 2,2 });
			Assert::AreEqual(0, test);
		}
		TEST_METHOD(compareEmptyPoint)
		{
			int test = eqPt({ 1,1 }, {  });
			Assert::AreEqual(0, test);
		}
	};

	//Blackbox: inputDestinationValidation
	TEST_CLASS(DestinationValidation_B)
	{
	public:
		Map map = populateMap();
		TEST_METHOD(validDestination)
		{
			char* src = "12L";
			Point input{};
			convertStringToPoint(&input, src);
			int result = inputDestinationValidation(input, &map);

			Assert::AreEqual(1, result);
		}
		TEST_METHOD(outOfRangePoint)
		{
			char* src = "28X";
			Point input{};
			convertStringToPoint(&input, src);
			int result = inputDestinationValidation(input, &map);

			Assert::AreEqual(0, result);
		}
		TEST_METHOD(notaBuilding)
		{
			char* src = "1A";
			Point input{};
			convertStringToPoint(&input, src);
			int result = inputDestinationValidation(input, &map);

			Assert::AreEqual(0, result);
		}
		TEST_METHOD(incompletedInput)
		{
			char* src = "12";
			Point input{};
			convertStringToPoint(&input, src);
			int result = inputDestinationValidation(input, &map);

			Assert::AreEqual(0, result);
		}
	};

	//Blackbox: distance
	TEST_CLASS(Distance_B)
	{
	public:
		TEST_METHOD(twoDiffLocations)
		{
			Point p1 = { 1, 1 };
			Point p2 = { 4, 5 };

			double result = distance(&p1, &p2);
			Assert::AreEqual(7.0, result);
		}
		TEST_METHOD(sameLocation)
		{
			Point p1 = { 1, 1 };
			Point p2 = { 1, 1 };

			double result = distance(&p1, &p2);
			Assert::AreEqual(0.0, result);
		}
		TEST_METHOD(negativeLocations)
		{
			Point p1 = { -1, -1 };
			Point p2 = { -4, -5 };

			double result = distance(&p1, &p2);
			Assert::AreEqual(7.0, result);
		}
	};


	//Blackbox: getClosestPoint
	TEST_CLASS(GetCloseRoute_B)
	{
	public:
		TEST_METHOD(onlyOnePointInRoute)
		{
			Route route = { { 1, 1 }, 1, 'B'};
			Point pt = { 2, 2 };
			
			int closestIndex = getClosestPoint(&route, pt);
			Assert::AreEqual(0, closestIndex);
		}
		TEST_METHOD(noPointInRoute)
		{
			Route route = { {  }, 0, 'B' };
			Point pt = { 2, 2 };

			int closestIndex = getClosestPoint(&route, pt);
			Assert::AreEqual(-1, closestIndex);
		}
	};


	//Blackbox: addPointToRoute
	TEST_CLASS(AddPoint_B)
	{
	public:
		TEST_METHOD(allValid)
		{
			Route route = { { 1, 1 }, 1, 'B' };
			int row = 2;
			int col = 6;

			addPointToRoute(&route, row, col);
			Assert::AreEqual(2, route.numPoints);
		}
		TEST_METHOD(addNegativePoint)
		{
			Route route = { { 1, 1 }, 1, 'B' };
			int row = -2;
			int col = -6;

			addPointToRoute(&route, row, col);
			Assert::AreEqual(2, route.numPoints);
		}
		TEST_METHOD(addPoint)
		{
			Route route = {};
			int row = 2;
			int col = 6;

			addPointToRoute(&route, row, col);
			Assert::AreEqual(1, route.numPoints);
		}
	};

	//Blackbox: addPointToRouteIfNot
	TEST_CLASS(AddPointIfNot_B)
	{
	public:
		TEST_METHOD(allValid)
		{
			Route route = { { 4, 4 }, 1, 'Y' };
			int row = 1;
			int col = 2;
			Point notThis = {3,3};

			addPointToRouteIfNot(&route, row, col, notThis);
			Assert::AreEqual(2, route.numPoints);
		}
		TEST_METHOD(sameWithOther)
		{
			Route route = { { 4, 4 }, 1, 'Y' };
			int row = 3;
			int col = 3;
			Point notThis = { 3,3 };

			addPointToRouteIfNot(&route, row, col, notThis);
			Assert::AreEqual(1, route.numPoints);
		}
		TEST_METHOD(emptyRoute)
		{
			Route route = { };
			int row = 1;
			int col = 2;
			Point notThis = { 3,3 };

			addPointToRouteIfNot(&route, row, col, notThis);
			Assert::AreEqual(1, route.numPoints);
		}
	};

    //Blackbox: addPtToRouteIfNot
    TEST_CLASS(AddPt_B)
    {
    public:
        TEST_METHOD(allValid)
        {
            Route route = { { 2, 2 }, 1, 'G' };
            Point notThis = { 3,3 };

            // Add a point to the route if it is not the same as the "notThis" point
            addPtToRoute(&route, notThis);
            Assert::AreEqual(2, route.numPoints); 
        }
	    TEST_METHOD(emptyRoute)
	    {
		    Route route = {  };
		    Point notThis = { 3,3 };

		    // Add a point to the route if it is not the same as the "notThis" point
		    addPtToRoute(&route, notThis);
		    Assert::AreEqual(1, route.numPoints); //Failed no error, the route has 1 point now
	    }
	    TEST_METHOD(emptyPoint)
	    {
		    Route route = { { 2, 2 }, 1, 'G' };
		    Point notThis = { };

		    // Add a point to the route if it is not an empty point
		    addPtToRoute(&route, notThis);
		    Assert::AreEqual(2, route.numPoints); //Failed numPoint is not 1, the empty point is added
	    }
    };

    //Blackbox: getNumRows
    TEST_CLASS(GetNumRows_B)
    {
    public:
	    TEST_METHOD(rowAndColSame)
	    {
		    Map map = { {{ 0, 0, 0 , 0 , 0, 0 },  {0, 0, 0 , 0 , 0, 0 }, {0, 0, 0 , 0 , 0, 0 }, {0, 0, 0 , 0 , 0, 0 }, {0, 0, 0 , 0 , 0, 0 }, { 0, 0, 0 , 0 , 0, 0 }},
		    6, 6};

		    int result = getNumRows(&map); // Calculate the number of rows in the map
		    Assert::AreEqual(6, result); // Assert that the result is equal to the expected number of rows
	    }
	    TEST_METHOD(rowAndColDiff)
	    {
		    Map map = {
		    {{ 0, 0, 0 , 0 , 0, 0 },  {0, 0, 0 , 0 , 0, 0 }, {0, 0, 0 , 0 , 0, 0 }, {0, 0, 0 , 0 , 0, 0 }, {0, 0, 0 , 0 , 0, 0 }, { 0, 0, 0 , 0 , 0, 0 }, { 0, 0, 0 , 0 , 0, 0 }
					, { 0, 0, 0 , 0 , 0, 0 }, { 0, 0, 0 , 0 , 0, 0 }, { 0, 0, 0 , 0 , 0, 0 }, { 0, 0, 0 , 0 , 0, 0 }},
		    11, 6 };

		    int result = getNumRows(&map); // Calculate the number of rows in the map
		    Assert::AreEqual(11, result); // Assert that the result is equal to the expected number of rows
	    }
	    TEST_METHOD(emptyMap)
	    {
		    Map map = { { },0, 0 };

		    int result = getNumRows(&map); // Calculate the number of rows in the map
		    Assert::AreEqual(0, result); // Assert that the result is equal to the expected number of rows
	    }
    };

	//Blackbox: getNumCols
	TEST_CLASS(GetNumCols_B)
	{
	public:
		TEST_METHOD(rowAndColSame)
		{
			Map map = { {{ 0, 0, 0 , 0 , 0 },  {0, 0, 0 , 0 , 0 }, {0, 0, 0 , 0 , 0}, {0, 0, 0 , 0 , 0}, {0, 0, 0 , 0 , 0}},
				5, 5 };

			int result = getNumCols(&map);
			Assert::AreEqual(5, result);
		}
		TEST_METHOD(rowAndColDiff)
		{
			Map map = {
				{
					{ 0, 0, 0 , 0 , 0, 0, 0, 0, 0 , 0 , 0, 0 },  {0, 0, 0 , 0 , 0, 0, 0, 0, 0 , 0 , 0, 0 }, {0, 0, 0 , 0 , 0, 0, 0, 0, 0 , 0 , 0, 0 },
					{0, 0, 0 , 0 , 0, 0, 0, 0, 0 , 0 , 0, 0 }, {0, 0, 0 , 0 , 0, 0, 0, 0, 0 , 0 , 0, 0 }},
				5, 10 };

			int result = getNumCols(&map);
			Assert::AreEqual(10, result);
		}
		TEST_METHOD(emptyMap)
		{
			Map map = { { },0, 0 };

			int result = getNumCols(&map);
			Assert::AreEqual(0, result);
		}
	};


	//Blackbox: ShortestPath
	TEST_CLASS(ShortestPath_B)
	{
	public:
		TEST_METHOD(emptyMap)
		{
			Map map = { {{0, 0, 0, 0, 0},  
						 {0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0}
				}, 5, 5 };
			Point start = { 0, 0 };
			Point dest = { 4, 4 };
			Route result = shortestPath(&map, start, dest);
			Assert::AreEqual(9, result.numPoints);
		}
		TEST_METHOD(oneBuildingMap)
		{
			Map map = { {{0, 0, 0, 0, 0},  
						 {0, 0, 0, 0, 0},
						 {0, 0, 1, 0, 0},
						 {0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0}}, 5, 5 };
			Point start = { 0, 0 };
			Point dest = { 4, 4 };
			Route result = shortestPath(&map, start, dest);
			Assert::AreEqual(9, result.numPoints);
		}
	};

	//Whitebox: addPointToRoute
	TEST_CLASS(AddPoint_W)
	{
	public:
		TEST_METHOD(allValid)
		{
			Route route = { { 1, 1 }, 1, 'B' };
			int row = 2;
			int col = 6;
			addPointToRoute(&route, row, col);

			char expect_row = 2;
			char expect_col = 6;
			Assert::AreEqual(2, route.numPoints);
			Assert::AreEqual(expect_row, route.points[1].row);
			Assert::AreEqual(expect_col, route.points[1].col);
		}

		TEST_METHOD(addNegativePoint)
		{
			Route route = { { 1, 1 }, 1, 'B' };
			int row = -2;
			int col = -6;
			addPointToRoute(&route, row, col);

			char expect_row = -2;
			char expect_col = -6;
			Assert::AreEqual(2, route.numPoints);
			Assert::AreEqual(expect_row, route.points[1].row);
			Assert::AreEqual(expect_col, route.points[1].col);
		}

		TEST_METHOD(addPoint)
		{
			Route route = {};
			int row = 2;
			int col = 6;
			addPointToRoute(&route, row, col);

			char expect_row = 2;
			char expect_col = 6;
			Assert::AreEqual(1, route.numPoints);
			Assert::AreEqual(expect_row, route.points[0].row);
			Assert::AreEqual(expect_col, route.points[0].col);
		}

	};

	//Whitebox: eqPt
	TEST_CLASS(eqPt_W)
	{
	public:
		TEST_METHOD(twoSameRowPoint)
		{
			int test = eqPt({ 1,1 }, { 1,2 });
			Assert::AreEqual(0, test);
		}
		TEST_METHOD(twoSameColPoint)
		{
			int test = eqPt({ 1,1 }, { 2,1 });
			Assert::AreEqual(0, test);
		}
	};

	//Whitebox: distance
	TEST_CLASS(Distance_W)
	{
	public:
		TEST_METHOD(sameLocation)
		{
			Point p1 = { 0, 0 };
			Point p2 = { 0, 0 };

			double result = distance(&p1, &p2);
			Assert::AreEqual(0.0, result);
		}
		TEST_METHOD(negativeLocations)
		{
			Point p1 = { -2, -3 };
			Point p2 = { -5, -7 };

			double result = distance(&p1, &p2);
			Assert::AreEqual(7.0, result);
		}
	};

	//Whitebox: inputWeightValidation
	TEST_CLASS(WeightValidationFunction_W)
	{
	public:
		TEST_METHOD(numberInRange)
		{
			int test = inputWeightValidation(500);
			Assert::AreEqual(1, test);
		}

		TEST_METHOD(zeorWeight)
		{
			int test = inputWeightValidation(0);
			Assert::AreEqual(0, test);
		}

		TEST_METHOD(numberExceedRange)
		{
			int test = inputWeightValidation(2000);
			Assert::AreEqual(0, test);
		}

		TEST_METHOD(zeroValue)
		{
			int test = inputWeightValidation(0);
			Assert::AreEqual(0, test);
		}
		TEST_METHOD(minValue)
		{
			int test = inputWeightValidation(1);
			Assert::AreEqual(1, test);
		}
	};

	//Whitebox: inputSizeValidation 
	TEST_CLASS(SizeValidation_W)
	{
	public:

		TEST_METHOD(small)
		{
			int test = inputSizeValidation(0.5);
			Assert::AreEqual(1, test);
		}

		TEST_METHOD(medium)
		{
			int test = inputSizeValidation(1.0);
			Assert::AreEqual(1, test);
		}

		TEST_METHOD(large)
		{
			int test = inputSizeValidation(5.0);
			Assert::AreEqual(1, test);
		}
		TEST_METHOD(optionNotInList)
		{
			int test = inputSizeValidation(100);
			Assert::AreEqual(0, test);
		}
	};

	//Whitebox: inputDestinationValidation
	TEST_CLASS(DestinationValidation_W)
	{
	public:
		Map map = populateMap();
		TEST_METHOD(validDestination)
		{
			char* src = "3C";
			Point input{};
			convertStringToPoint(&input, src);
			int result = inputDestinationValidation(input, &map);

			Assert::AreEqual(1, result);
		}
		TEST_METHOD(outOfRangePoint)
		{
			char* src = "-1D";
			Point input{};
			convertStringToPoint(&input, src);
			int result = inputDestinationValidation(input, &map);

			Assert::AreEqual(0, result);
		}
		TEST_METHOD(startPoint)
		{
			char* src = "1A"; //(0,0)
			Point input{};
			convertStringToPoint(&input, src);
			int result = inputDestinationValidation(input, &map);

			Assert::AreEqual(0, result);
		}
		TEST_METHOD(notBuilding)
		{
			char* src = "3D";
			Point input{};
			convertStringToPoint(&input, src);
			int result = inputDestinationValidation(input, &map);

			Assert::AreEqual(0, result);
		}
	};

	//Whitebox: ShortestPath
	TEST_CLASS(ShortestPath_W)
	{
	public:
		TEST_METHOD(validInput)
		{
			Map map = { {{0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0}
				}, 5, 5 };
			Point start = { 0, 0 };
			Point dest = { 4, 4 };
			Route result = shortestPath(&map, start, dest);
			Assert::AreEqual(9, result.numPoints); 
		}
		TEST_METHOD(reverseDest)
		{
			Map map = { {{0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0}}, 5, 5 };
			Point start = { 3, 3};
			Point dest = { 2, 2 };
			Route result = shortestPath(&map, start, dest);
			Assert::AreEqual(3, result.numPoints);//Failed, can find the path for reverse destination
		}
		TEST_METHOD(sameDestStart)
		{
			Map map = { {{0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0}}, 5, 5 };
			Point start = { 3, 3 };
			Point dest = { 3, 3 };
			Route result = shortestPath(&map, start, dest);
			Assert::AreEqual(1, result.numPoints);
		}
		TEST_METHOD(destNotOnMap)
		{
			Map map = { {{0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0},
						 {0, 0, 1, 0, 0},
						 {0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0}}, 5, 5 };
			Point start = { 0, 0 };
			Point dest = { 5, 5 };
			Route result = shortestPath(&map, start, dest);
			Assert::AreEqual(100, result.numPoints);
		}
	};

	//Whitebox: getClosestPoint
	TEST_CLASS(GetCloseRoute_W)
	{
	public:
		TEST_METHOD(onlyOnePointInRoute)
		{
			Route route = { { 1, 1 }, 1, 'Y' };
			Point pt = { 1, 1 };

			int closestIndex = getClosestPoint(&route, pt);
			Assert::AreEqual(0, closestIndex);
		}
		TEST_METHOD(noPointInRoute)
		{
			Route route = { {  }, 0, 'Y' };
			Point pt = { 1, 1 };

			int closestIndex = getClosestPoint(&route, pt);
			Assert::AreEqual(-1, closestIndex);
		}
		TEST_METHOD(tooFarDistance)
		{
			Route route = { {1, 1}, 0, 'Y' };
			Point pt = { 1000000, 1 }; //closestDist = 999999.99

			int closestIndex = getClosestPoint(&route, pt);
			Assert::AreEqual(-1, closestIndex);
		}
	};

	//Whitebox: addRoute
	TEST_CLASS(AddRoute_W)
	{
	public:
		TEST_METHOD(EmptyRoute)
		{
			Map map = {
				{
					{0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0}
				},
				5,
				5
			};
			Route route = { {}, 0, 0 };
			Map result = addRoute(&map, &route);

			Assert::AreEqual(map.numRows, result.numRows);
			Assert::AreEqual(map.numCols, result.numCols);
			for (int i = 0; i < map.numRows; i++) {
				for (int j = 0; j < map.numCols; j++) {
					Assert::AreEqual(map.squares[i][j], result.squares[i][j]);
				}
			}
		}

		TEST_METHOD(SinglePointRoute)
		{
			Map map = {
				{
					{0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0}
				},
				5,
				5
			};
			Point point = { 2, 2 };
			Route route = { {point}, 1, BLUE };
			Map result = addRoute(&map, &route);
			Assert::AreEqual(route.routeSymbol - 0, result.squares[route.points[0].row][route.points[0].col]);
		}
	};


	//Whitebox: getPossibleMoves
	TEST_CLASS(GetPossibleMoves_W)
	{
		Map map = {
				{
					{0, 0, 0, 0, 0},
					{0, 1, 1, 1, 0},
					{0, 0, 0, 1, 0},
					{0, 1, 1, 1, 0},
					{0, 0, 0, 0, 0}
				},
				5, 5
		};
	public:
		//Find a bug that the possible moves do not include the destination if the destination is a building.
		//Find a bug that the possible moves find all 8 directions, but we only go for 4 directions.
		/*TEST_METHOD(PointInTheMiddle)
		{
			Point p1 = { 2, 2 };
			Point backpath = { 2, 1 };
			Route result = getPossibleMoves(&map, p1, backpath);
			Assert::AreEqual(0, result.numPoints);  
		}

		TEST_METHOD(PointAtTheCorner)
		{
			Point p1 = { 0, 0 };
			Point backpath = { 1, 0 };
			Route result = getPossibleMoves(&map, p1, backpath);
			Assert::AreEqual(1, result.numPoints); 
		}

		TEST_METHOD(PointAdjacentToBuilding)
		{
			Point p1 = { 1, 2 };
			Point backpath = { 1, 3 };
			Route result = getPossibleMoves(&map, p1, backpath);
			Assert::AreEqual(5, result.numPoints);  
		}*/
		TEST_METHOD(PointInTheMiddle)
		{
			Point p1 = { 2, 2 };  //start point
			Point backpath = { 2, 1 };  //last step
			Point dest = { 1, 2 }; //destination
			Route result = getPossibleMoves(&map, p1, backpath, dest);
			Assert::AreEqual(1, result.numPoints);
		}

		TEST_METHOD(PointAtTheCorner)
		{
			Point p1 = { 0, 0 };  //start point
			Point backpath = { 1, 0 };  //last step
			Point dest = { 1, 1 };  //destination
			Route result = getPossibleMoves(&map, p1, backpath, dest);
			Assert::AreEqual(1, result.numPoints);
		}

		TEST_METHOD(PointAdjacentToBuilding)
		{
			Point p1 = { 1, 2 };  //start point
			Point backpath = { 1, 3 };  //last step
			Point dest = { 1, 1 };  //destination
			Route result = getPossibleMoves(&map, p1, backpath, dest);
			Assert::AreEqual(3, result.numPoints);
		}
	};

	//Whitebox: convertStringToPoint
	TEST_CLASS(ConvertStringToPoint_W)
	{
	public:
		TEST_METHOD(emptyDest)
		{
			struct Point dest = { 0, 0 };
			const char* source = "12L";
			convertStringToPoint(&dest, source);
			Assert::AreEqual(static_cast<char>(11), dest.row);
			Assert::AreEqual(static_cast<char>(11), dest.col);
		}
		TEST_METHOD(nonEmptyDest)
		{
			struct Point dest = { 1, 1 };
			const char* source = "12L";
			convertStringToPoint(&dest, source);
			Assert::AreEqual(static_cast<char>(11), dest.row);
			Assert::AreEqual(static_cast<char>(11), dest.col);
		}
		TEST_METHOD(emptySoure)
		{
			struct Point dest = { 1, 1 };
			const char* source = "";
			convertStringToPoint(&dest, source);
			Assert::AreEqual(static_cast<char>(0), dest.row);
			Assert::AreEqual(static_cast<char>(0), dest.col);
		}
	};



}
