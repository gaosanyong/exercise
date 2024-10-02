#include "matrix.h"

MyMatrix::MyMatrix(vector<vector<double>> data) : data(data) {
    rows = data.size();
    if (rows) cols = data[0].size();
    else cols = 0;
}

MyMatrix::MyMatrix() {
    string line;
    ifstream file("config.txt");
    getline(file, line); rows = stoi(line);
    getline(file, line); cols = stoi(line);
    getline(file, line); int v = stoi(line);
    file.close();
    data = vector<vector<double>>(rows, vector<double>(cols, v));
}

MyMatrix MyMatrix::operator+(MyMatrix const& other) {
    vector<vector<double>> ans;
    if (rows == other.rows && cols == other.cols) {
        ans = vector<vector<double>>(rows, vector<double>(cols, 0));
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                ans[i][j] = data[i][j] + other.data[i][j];
    }
    return MyMatrix(ans);
}

void setUpLibrary() {
    cout << "Loading library" << endl;
}
void tearDownLibrary() {
    cout << "Unloading library" << endl;
}
