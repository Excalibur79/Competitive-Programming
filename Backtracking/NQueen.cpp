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

bool isValid(auto &board, int i, int j) {
    for (int x = i; x >= 0; x--) {
        if (board[x][j] == 1) return false;
    }
    int x = i, y = j;
    while (x >= 0 && y >= 0) {
        if (board[x][y] == 1) return false;
        x--;
        y--;
    }
    x = i, y = j;
    while (x >= 0 && y < n) {
        if (board[x][y] == 1) return false;
        x--;
        y++;
    }
    return true;
}

void nQueenAllPossibilites(auto &board, int row) {
    if (row == n) {
        cout << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << (board[i][j] == 1 ? 'Q' : '_') << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int j = 0; j < n; j++) {
        if (isValid(board, row, j)) {
            board[row][j] = 1;
            nQueenAllPossibilites(board, row + 1);
            board[row][j] = 0;
        }
    }
}

bool nQueen(auto &board, int row) {
    if (row == n) {
              for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << (board[i][j] == 1 ? 'Q' : '_') << " ";
            }
            cout << endl;
        }
        return true;
    }
    for (int j = 0; j < n; j++) {
        if (isValid(board, row, j)) {
            board[row][j] = 1;
            bool res = nQueen(board, row + 1);
            board[row][j] = 0;
            if (res) return true;
        }
    }
    return false;
}

void solve() {
    cin >> n;
    vector<vector<int>> board;
    for (int i = 0; i < n; i++) {
        vector<int> p;
        for (int j = 0; j <= n; j++) {
            p.pb(0);
        }
        board.pb(p);
    }
    //  nQueenAllPossibilites(board, 0);
    nQueen(board, 0);
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