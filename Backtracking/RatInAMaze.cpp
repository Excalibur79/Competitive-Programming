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

bool ratInAMaze(char maze[10][10], int soln[][10], int i, int j, int m, int n) {
    if (i == m && j == n) {
        soln[i][j] = 1;
        cout << endl;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                cout << soln[i][j] << " ";
            }
            cout << endl;
        }

        return true;
    }
    if (i > m || j > n) return false;
    if (maze[i][j] == 'X') return false;

    soln[i][j] = 1;
    bool right = ratInAMaze(maze, soln, i, j + 1, m, n);
    bool down = ratInAMaze(maze, soln, i + 1, j, m, n);

    // Backtracking
    soln[i][j] = 0;

    if (right || down) return true;
    return false;
}

void solve() {
    char maze[10][10] = {"0000", "00X0", "000X", "0X00"};
    int soln[10][10] = {0};
    int m = 4, n = 4;
    bool ans = ratInAMaze(maze, soln, 0, 0, m - 1, n - 1);
    if (!ans) cout << "Path doesnt exist";
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