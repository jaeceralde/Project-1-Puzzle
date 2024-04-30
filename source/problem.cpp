#include <iostream>
#include "../headers/problem.hpp"

// initialize puzzle —

Problem::Problem() {    // default constructor
    
    // give start state
    int tiles[9] = {1, 0, 3, 4, 2, 6, 7, 5, 8};
    for (int i = 0; i < puzzleSize; i++) {
        node tile;
        tile.state = tiles[i];
        // tile.cost = 0; // FIXME
        // tile.heuristicCost = 0; // FIXME
        // tile.p = ; // FIXME
        startState.push_back(tile);
    }

    // give goal state
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

Problem::Problem(vector<node> startState) {    // constructor based on user input

}

int Problem::getPuzzleSize() {
    return puzzleSize - 1;
}

// void Problem::printStartState() { // for testing purposes
//     int counter = 0;

//     for (auto i = startState.begin(); i != startState.end(); ++i) {
        
//         if (i->state == 0) {
//             cout << "* ";
//         }

//         else {
//             cout << i->state << " ";
//         }
        
//         counter += 1;

//         if (counter % 3 == 0) {
//             cout << endl;
//         }
//     }

//     cout << endl;
// }

// void Problem::printGoalState() { // for testing purposes
//     int counter = 0;

//     for (auto i = goalState.begin(); i != goalState.end(); ++i) {
//         if (i->state == 0) {
//             cout << "* ";
//         }

//         else {
//             cout << i->state << " ";
//         }

//         counter += 1;

//         if (counter % 3 == 0) {
//             cout << endl;
//         }
//     }

//     cout << endl;
// }


int Problem::EuclideanDistanceSearch(vector<node> startState){
    
    // first change states into a 2d vector and create a goals 2d vector
    vector<vector<node> > tempStates;
    vector<vector<int> > tempGoals = {{1,2,3}, {4,5,6}, {7,8,0}};

    // push the states into the new states vector
    int startcounter = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            tempStates[i].push_back(startState[startcounter]);
            startcounter++;
        }
    }

    int heuristicCost = 0;

    for(int i = 0; i < tempStates.size(); i++){
        for(int j = 0; j < tempStates[i].size(); j++){
            // if the state is 0 or its equal to goal state: continue
            if(tempStates[i][j].state == 0 || tempStates[i][j].state == tempGoals[i][j]){ 
                continue;
            }
            // if its misplaced 
            else{
                // find how far each of the titles are in the x and y 
                // run equation (i - igoaldistance)^2...
            }
        }
    }

    return heuristicCost; 
}