#include <iostream>
#include "../headers/problem.hpp"

// initialize puzzle —

Problem::Problem() {    // default constructor
    // start state
    int tiles[9] = {1, 0, 3, 4, 2, 6, 7, 5, 8};
    for (int i = 0; i < puzzleSize; i++) {
        node tile;
        tile.state = tiles[i];
        tile.cost = 0;
        tile.heuristicCost = 0;
        // tile.p = ; // FIXME
        startState.push_back(tile);
    }

    // goal state
    int puzzleTiles = 1;

    for (int i = 0; i < puzzleSize - 1; i++) {
        node tile;
        tile.state = puzzleTiles;
        puzzleTiles += 1;
        goalState.push_back(tile);
    }

    node tile;
    tile.state = 0;
    goalState.push_back(tile);

}

void Problem::userProblem() {    // "constructor" based on user input
    int userInput = 0;
    
    for (auto i = startState.begin(); i != startState.end(); ++i) {
        cin >> userInput;
        i->state = userInput;
    }
}

// accessor functions —

int Problem::getPuzzleSize() {
    return puzzleSize - 1;
}

vector<node> Problem::getStartState() {
    return startState;
}
vector<node> Problem::getGoalState() {
    return goalState;
}

void Problem::printStartState() { // for testing purposes
    int counter = 0;

    for (auto i = startState.begin(); i != startState.end(); ++i) {
        
        if (i->state == 0) {
            cout << "* ";
        }

        else {
            cout << i->state << " ";
        }
        
        counter += 1;

        if (counter % 3 == 0) {
            cout << endl;
        }
    }

    cout << endl;
}

void Problem::printGoalState() { // for testing purposes
    int counter = 0;

    for (auto i = goalState.begin(); i != goalState.end(); ++i) {
        if (i->state == 0) {
            cout << "* ";
        }

        else {
            cout << i->state << " ";
        }

        counter += 1;

        if (counter % 3 == 0) {
            cout << endl;
        }
    }

    cout << endl;
}

bool Problem::GoalStateTest() {

    auto startIt = startState.begin();
    auto goalIt = goalState.begin();

    while ((startIt != startState.end()) || (goalIt != goalState.end())) {
        cout << "start: " << startIt->state << " goal: " << goalIt->state << endl;

        if (startIt->state != goalIt->state) {
            return false;
        }

        startIt++;
        goalIt++;
    }

    return true;
}