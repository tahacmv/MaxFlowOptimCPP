#include<iostream>
#include "util/GraphGenerator.hpp"

int main() {
    int numUC, numIT;

    std::cout << "Enter the number of UC nodes: ";
    std::cin >> numUC;
    std::cout << "Enter the number of IT nodes: ";
    std::cin >> numIT;

    CreateGraph(numUC, numIT);

    return 0;
}
