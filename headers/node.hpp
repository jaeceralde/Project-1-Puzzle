#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
#include <vector>
using namespace std;

struct node {
    int state[3][3]; // first value in state pair is the number itself, second is its cost
    int cost = 0;
    int heuristicCost = 0;
    node *p = NULL;
};

#endif