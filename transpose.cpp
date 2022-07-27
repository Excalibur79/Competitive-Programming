#include <bits/stdc++.h>
using namespace std;

void transpose(vector<vector<int>> &matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = i; j < matrix[0].size(); j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

vector<vector<int>> generateTranspose(vector<vector<int>> &matrix) {
    vector<vector<int>> transpose;
    for (int j = 0; j < matrix[0].size(); j++) {
        vector<int> p;
        for (int i = 0; i < matrix.size(); i++) {
            p.push_back(matrix[i][j]);
        }
        transpose.push_back(p);
    }
    return transpose;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    transpose(matrix);
    for (vector<int> row : matrix) {
        for (int data : row) cout << data << " ";
        cout << endl;
    }
    return 0;
}