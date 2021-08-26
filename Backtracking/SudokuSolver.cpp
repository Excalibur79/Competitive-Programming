// Author: Ankur Saha
// Linkedin: https://www.linkedin.com/in/ankur-saha/
// Github: https://github.com/Excalibur79

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
const int MOD = 1e9 + 7;
const ll INF = 1e18;
#define inputarr(arr, n) \
    for (ll i = 0; i < n; i++) cin >> arr[i];
#define printarr(arr, n) \
    for (ll i = 0; i < n; i++) cout << arr[i] << ' ';

int n;

bool canPlace(auto &sudoku, int number, int i, int j) {
    // checking row
    for (int col = 0; col < n; col++) {
        if (sudoku[i][col] == number) return false;
    }
    // checking column
    for (int row = 0; row < n; row++) {
        if (sudoku[row][j] == number) return false;
    }
    //  checking subgrid

    int x = (i / (int)sqrt(n)) * sqrt(n);
    int y = (j / (int)sqrt(n)) * sqrt(n);
    // cout << x << " " << y << endl;
    for (int p = x; p < (x + sqrt(n)); p++) {
        for (int q = y; q < (y + sqrt(n)); q++) {
            if (sudoku[p][q] == number) return false;
        }
    }

    return true;
}

bool sudokuSolver(auto &sudoku, int row, int col) {
    if (row == n) {
        // print Sudoku
        cout << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << sudoku[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }
    if (col == n)  // column er baire piuche geche so go to next row
        return sudokuSolver(sudoku, row + 1, 0);
    if (sudoku[row][col] != 0) return sudokuSolver(sudoku, row, col + 1);
    // else place a valid number here
    for (int number = 1; number <= n; number++) {
        if (canPlace(sudoku, number, row, col)) {
            sudoku[row][col] = number;
            bool res = sudokuSolver(sudoku, row, col + 1);
            sudoku[row][col] = 0;
            if (res) return true;
        }
    }

    return false;
}

void solve() {
    n = 9;
    vector<vector<int>> sudoku = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0}, {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1}, {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5}, {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0}, {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    // sudoku = {{5, 3, 0, 0, 7, 0, 0, 0, 0}, {6, 0, 0, 1, 9, 5, 0, 0, 0},
    //           {0, 9, 8, 0, 0, 0, 0, 6, 0}, {8, 0, 0, 0, 6, 0, 0, 0, 3},
    //           {4, 0, 0, 8, 0, 3, 0, 0, 1}, {7, 0, 0, 0, 2, 0, 0, 0, 6},
    //           {0, 6, 0, 0, 0, 0, 2, 8, 0}, {0, 0, 0, 4, 1, 9, 0, 0, 5},
    //           {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    bool res = sudokuSolver(sudoku, 0, 0);
    if (!res) cout << "Puzzle Could'nt be solved!";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}