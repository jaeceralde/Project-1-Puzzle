#ifndef PROBLEM_HPP
#define PROBLEM_HPP
#include <iostream>
#include "../headers/node.hpp"
using namespace std;

class Problem {
    protected:
        int puzzleSize = 3;

    public:
        node puzzle;

        Problem();
        void userProblem();
        // int getPuzzleSize(); // dont need this for now
        void printStartState(); // for testing purposes
        // void printGoalState(); // for testing purposes
        void UniformCostSearch();
        void MisplacedTileSearch();
        double EuclideanDistanceSearch(node inputPuzzle);
        bool GoalStateTest(node puzzleInput);
        bool canShiftUp(node inputPuzzle);
        bool canShiftDown(node inputPuzzle);
        bool canShiftLeft(node inputPuzzle);
        bool canShiftRight(node inputPuzzle);

};

#endif