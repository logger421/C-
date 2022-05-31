#include "Knapsack.h"

Knapsack::Knapsack(int maxWeight, int rows) {
    this->maxWeight = maxWeight;
    N = maxWeight + 1;
    this->R = rows+1;

    matrix = new int *[R + 1];

    for(int i = 0; i < R; i++) { 
        matrix[i] = new int[N];
    }
}

Knapsack::~Knapsack() { 
    for(int i = 0; i < R; i++)
        delete [] matrix[i];
    delete[] matrix;
}

void Knapsack::initialiseItems(std::vector<std::pair<int, int >> *vec) {
    items = vec;
}

void Knapsack::solveKnapsackProblem() {
    for(int j = 0; j < N; j++)
        matrix[0][j] = 0;

    for(int i = 1; i < R; i++)
        for(int j = 0; j < N; j++) {
            if(i == 1) {
                if( items->at(i-1).first > j ) matrix[i][j] = 0;
                if( items->at(i-1).first <= j) matrix[i][j] = items->at(i-1).second;
            }
            else {
                if( items->at(i-1).first > j ) matrix[i][j] = matrix[i-1][j];
                if( items->at(i-1).first <= j ) matrix[i][j] = std::max(matrix[i-1][j], matrix[i-1][j-items->at(i-1).first] +items->at(i-1).second);
            }
        }
}

void Knapsack::showItemsToPick() {
    int n = items->size();
    int M = maxWeight;

    while(n != 0) {
        if(matrix[n][M] != matrix[n-1][M]) {
            std::cout << "Package " << n << " with W = " << items->at(n-1).first << " and Value = " << items->at(n-1).second << std::endl;
            M = M - items->at(n-1).first;
        }
        n--;
    }
}

void Knapsack::showResultMatrix() {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < N; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << "\n";
    }
}

void Knapsack::showResult() {
    std::cout << "\nResult: " << matrix[R-1][N-1] << std::endl;
}