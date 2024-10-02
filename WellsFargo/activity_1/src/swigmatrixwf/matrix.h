#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

class MyMatrix {
public:
    int rows;
    int cols;
    vector<vector<double>> data;

    MyMatrix();
    MyMatrix(vector<vector<double>> data);
    MyMatrix operator+(MyMatrix const& other);
};

void setUpLibrary();
void tearDownLibrary();
