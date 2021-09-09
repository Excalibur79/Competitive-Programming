// Author: Ankur Saha
// Linkedin: https://www.linkedin.com/in/ankur-saha/
// Github: https://github.com/Excalibur79

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long int
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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<char>> matrix(n, vector<char>(n, '.'));
    // observation  => losing when number of 2s is either 1 or 2
    int ones = 0, twos = 0;
    for (char c : s) {
        if (c == '2')
            twos++;
        else
            ones++;
    }
    if (twos == 1 || twos == 2) {
        cout << "No" << endl;

    } else {
        cout << "Yes" << endl;
        // concept if s[i] is 1 then lets make matches with all s[j] as draw ie.
        // '= if s[i] is 2 and s[j] is also 2 then  make i the winner and sest
        // satisfied true which idicates that i may loose other matches

        for (int i = 0; i < n; i++) {
            bool satisfied = false;
            for (int j = i; j < n; j++) {
                if (i == j)
                    matrix[i][j] = 'X';
                else {
                    if (s[i] == '1' || s[j] == '1') {
                        matrix[i][j] = '=';
                        matrix[j][i] = '=';
                    }

                    if (s[i] == '2' && s[j] == '2' && !satisfied) {
                        matrix[i][j] = '+';
                        matrix[j][i] = '-';
                        satisfied = true;
                    } else if (s[i] == '2' && s[j] == '2' && satisfied) {
                        matrix[i][j] = '-';
                        matrix[j][i] = '+';
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j];
            }
            cout << endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}