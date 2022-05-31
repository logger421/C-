#include <iostream>
#include <vector>
#include <fstream>
#include <utility>
#include "Knapsack.h"


std::vector<std::pair<int, int >> readFile(std::string path);
void validate_read_data(const std::vector<std::pair<int, int >> &v);

int main() {
    std::vector<std::pair<int, int >> in_data;
    in_data = readFile("plecakZadanieG3.txt");
    //validate_read_data(in_data); // uncoment to validate read data
    Knapsack *k = new Knapsack(24, in_data.size());
    k->initialiseItems(&in_data);
    k->solveKnapsackProblem();
    k->showResultMatrix();
    k->showResult();
    k->showItemsToPick();
    std::cout<<"\n";
    delete k;
    return 0;
}

std::vector<std::pair<int, int >> readFile(std::string path) {
    std::vector<std::pair<int, int >> input;
    std::ifstream in;
    in.open(path);

    if(!in.is_open()) {
        std::cerr << "Error during opening file\n";
        std::abort();
    } 

    int weight, value;
    while(in >> weight >> value) {
        std::pair<int,int> item(weight, value);
        input.push_back(item);
    }
    in.close();
    return input;
}

void validate_read_data(const std::vector<std::pair<int, int >> &v) {
    for(auto x : v)
        std::cout << x.first << " " << x.second << std::endl;
}