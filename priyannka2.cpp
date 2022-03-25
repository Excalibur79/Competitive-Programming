// Author: Ankur Saha
// Linkedin: https://www.linkedin.com/in/ankur-saha/
// Github: https://github.com/Excalibur79

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// void solve() {
//     long long int n;
//     cin >> n;
//     vector<long long int> arr(n);
//     for (int i = 0; i < n; i++) cin >> arr[i];
//     sort(arr.begin(), arr.end());
//     int startIndex = n & 1 ? 0 : 1;
//     long long int sum = 0;
//     for (int i = startIndex; i < n; i += 2) {
//         if (arr[i] > 0) {
//             sum += arr[i] % MOD;
//         }
//     }
//     cout << sum << endl;
// }

const int MOD = 1e9 + 7;

int solve(int n, vector<int> arr) {
    sort(arr.begin(), arr.end());
    int startIndex = n & 1 ? 0 : 1;
    long long int sum = 0;
    for (int i = startIndex; i < n; i += 2) {
        if (arr[i] > 0) {
            sum += arr[i] % MOD;
        }
    }
    return sum;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        cout << solve();
    }
    return 0;
}