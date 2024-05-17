# Truck Delivery Testing Project

## Project Description

Our team had been hired by a local delivery company that operates three different trucks on three different routes in part of the client's city. The goal of the project is to optimize the delivery process by selecting the best truck for each shipment based on route proximity and capacity.

### Key Features of the Algorithm:
- Follows the route for each truck.
- Calculates the Euclidean distance from each square on the route to the destination.
- Selects the minimum Euclidean distance for each truck and calculates the shortest path from those positions to the destination.
- Excludes any truck that cannot find a path to the destination.
- Chooses the truck with the shortest path to the destination and attempts to add the package to that truck.
- If the selected truck is full, it tries the next closest truck.
- If no truck can take the package, it stores the package at the depot until the next day, printing "Ships tomorrow".
- The algorithm runs for one day, deciding truck assignments, and outputs delivery details and any necessary route diversions.

## Project Structure

The project was divided into six milestones, managed using Jira and Agile methodologies. The programming language used is C, and the testing is conducted in C++.

### Milestones

1. **Understanding Client Requirements and Generating Test Plan**
   - Understand the client's requirements.
   - Generate a comprehensive test plan.

2. **Code Specification and Creating Traceability Matrix**
   - Define the code specifications.
   - Create a traceability matrix.
   - Develop black-box unit test cases for available functions.

3. **Code Implementation and Creating White-Box Unit Test Cases**
   - Implement the code according to specifications.
   - Develop white-box unit test cases.

4. **Debugging and Bug Fixing**
   - Debug the complete program.
   - Fix bugs identified from the unit tests.

5. **Integration Testing**
   - Conduct integration testing to ensure all parts work together seamlessly.

6. **Documentation and User Acceptance Testing**
   - Document all work, including the test plan, test cases, and traceability matrix.
   - Create and conduct user acceptance tests.

## Team Structure

- **Programmers**: 2 team members responsible for implementing the code.
- **Testers**: 2 team members responsible for testing the code.

## Documentation

All project documents are stored in the repository, including:
- Source code
  -   input.c /input.h: Take input from users
  -   mapping.h / maaping.c: Generate map data from the client and calculate the shortest path
  -   main.c: The entry point of the application, initializing and running the main program loop and create the user interface
- Test-plan.pdf
- test_cases.xlsx (over 100 cases in total)
- traceability_matrix.xlsx
