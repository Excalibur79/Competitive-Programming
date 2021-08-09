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
    for (ll i = 0; i < n; i++) cin >> arr{i};
#define printarr(arr, n) \
    for (ll i = 0; i < n; i++) cout << arr{i} << ' ';

bool sortComparator(pll a, pll b) {
    if (a.first < b.first) return true;
    if (a.first > b.first) return false;
    return a.second < b.second;
}

bool isValid(int i, int j) {
    if (i >= 0 && i < 8 && j >= 0 && j < 8) return true;
    return false;
}

bool checkMove(vector<vector<string>>& board, int rMove, int cMove,
               string color) {
    board[rMove][cMove] = color;
    // checking top
    string presentColor = color;
    int numberOfColors = 1;
    int length = 0;
    int i = rMove;
    int j = cMove;
    while (i >= 0) {
        length++;
        if (presentColor != board[i][j]) {
            numberOfColors++;
            presentColor = board[i][j];
        }

        i--;
    }
    if (numberOfColors == 3 && length >= 3 &&
        board[0][j] == board[rMove][cMove])
        return true;
    //===========

    // checling bottom'
    presentColor = color;
    numberOfColors = 1;
    i = rMove;
    j = cMove;
    length = 0;
    while (i < 8) {
        length++;
        if (presentColor != board[i][j]) {
            numberOfColors++;
            presentColor = board[i][j];
        }
        i++;
    }
    if (numberOfColors == 3 && length >= 3 &&
        board[7][j] == board[rMove][cMove])
        return true;
    //================

    // checling left'
    presentColor = color;
    numberOfColors = 1;
    i = rMove;
    j = cMove;
    length = 0;
    while (j >= 0) {
        length++;
        if (presentColor != board[i][j]) {
            numberOfColors++;
            presentColor = board[i][j];
        }
        j--;
    }
    if (numberOfColors == 3 && length >= 3 &&
        board[i][0] == board[rMove][cMove])
        return true;
    //================

    // checling right'
    presentColor = color;
    numberOfColors = 1;
    i = rMove;
    j = cMove;
    length = 0;
    while (j < 8) {
        length++;
        if (presentColor != board[i][j]) {
            numberOfColors++;
            presentColor = board[i][j];
        }
        j++;
    }
    if (numberOfColors == 3 && length >= 3 &&
        board[i][7] == board[rMove][cMove])
        return true;
    //================

    // checling top left diagonal'
    presentColor = color;
    numberOfColors = 1;
    i = rMove;
    j = cMove;
    length = 0;
    while (i >= 0 && j >= 0) {
        length++;
        if (presentColor != board[i][j]) {
            numberOfColors++;
            presentColor = board[i][j];
        }
        j--;
        i--;
    }
    if (numberOfColors == 3 && length >= 3 &&
        board[0][0] == board[rMove][cMove])
        return true;
    //================

    // checling top right diagonal'
    presentColor = color;
    numberOfColors = 1;
    i = rMove;
    j = cMove;
    length = 0;
    while (i >= 0 && j < 8) {
        length++;
        if (presentColor != board[i][j]) {
            numberOfColors++;
            presentColor = board[i][j];
        }
        j++;
        i--;
    }
    if (numberOfColors == 3 && length >= 3 &&
        board[0][7] == board[rMove][cMove])
        return true;
    //================

    // checling bottom left diagonal'
    presentColor = color;
    numberOfColors = 1;
    i = rMove;
    j = cMove;
    length = 0;
    while (i < 8 && j >= 0) {
        length++;
        if (presentColor != board[i][j]) {
            numberOfColors++;
            presentColor = board[i][j];
        }
        j--;
        i++;
    }
    if (numberOfColors == 3 && length >= 3 &&
        board[7][0] == board[rMove][cMove])
        return true;
    //================

    // checling bottom right diagonal'
    presentColor = color;
    numberOfColors = 1;
    i = rMove;
    j = cMove;
    length = 0;
    while (i < 8 && j < 8) {
        length++;
        if (presentColor != board[i][j]) {
            numberOfColors++;
            presentColor = board[i][j];
        }
        j++;
        i++;
    }
    if (numberOfColors == 3 && length >= 3 &&
        board[7][7] == board[rMove][cMove])
        return true;
    //================
    return false;
}

void solve() {
    vector<vector<string>> board = [
        [ "W", "W", ".", "B", ".", "B", "B", "." ],
        [ "W", "B", ".", ".", "W", "B", ".", "." ],
        [ "B", "B", "B", "B", "W", "W", "B", "." ],
        [ "W", "B", ".", ".", "B", "B", "B", "." ],
        [ "W", "W", "B", ".", "W", ".", "B", "B" ],
        [ "B", ".", "B", "W", ".", "B", ".", "." ],
        [ ".", "B", "B", "W", "B", "B", ".", "." ],
        [ "B", "B", "W", ".", ".", "B", ".", "." ]
    ];
    cout << (checkMove(board, 4, 4, "W"));
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