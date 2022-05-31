#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

class Knapsack {
private:
    int N; // cols
    int R; // rows
    int maxWeight; 
    int** matrix;
    std::vector<std::pair<int, int >> *items;
public:
    Knapsack(int maxWeigtht, int N);
    ~Knapsack();
    void initialiseItems(std::vector<std::pair<int, int >> *vec);
    void solveKnapsackProblem();
    void showItemsToPick();
    void showResultMatrix();
    void showResult();
};