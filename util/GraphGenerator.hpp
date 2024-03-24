//
// Created by tmmot on 24/03/2024.
//

#ifndef MAXFLOWOPTIMCPP_GRAPHGENERATOR_HPP
#define MAXFLOWOPTIMCPP_GRAPHGENERATOR_HPP

#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <filesystem>

using namespace std;

int randomCapacity();

std::string generateFilename();

void CreateGraph(int numUC, int numIT);

#endif //MAXFLOWOPTIMCPP_GRAPHGENERATOR_HPP
