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
    int x, n;
    cin >> x >> n;
    int ox = x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int i = 0, j = 0;
    int ans = INT_MIN;
    // unordered_set<int> uniquePrices;
    unordered_map<int, int> uniquePrices;
    while (j < n) {
        // if (j != 0 && arr[j - 1] != arr[j] && arr[j] >= x) {
        //     // cout << "asddasd" << endl;
        //     x -= arr[j];
        // } else if (j == 0)
        //     x -= arr[j];
        // else if (arr[j] > x && arr[j] <= ox) {
        //     cout << "ss" << endl;
        //     while (arr[j] > x) {
        //         if (arr[i] != arr[i + 1]) x += arr[i];
        //         i++;
        //     }
        //     x -= arr[j];
        // } else if (arr[j] > x && arr[j] > ox) {
        //     while (i < j) {
        //         if (arr[i] != arr[i + 1]) x += arr[i];
        //         i++;
        //     }
        // }
        // ans = max(ans, j - i + 1);
        // cout << i << " " << j << " " << x << endl;
        // j++;

        // if (j == 0) {
        //     x -= arr[j];
        //     uniquePrices.insert(arr[j]);
        // } else if (arr[j] != arr[j - 1]) {
        //     if (arr[j] <= x)
        //         x -= arr[j];
        //     else if (arr[j] <= ox) {
        //         while (arr[j] > x) {
        //             if (arr[i] != arr[i + 1]) x += arr[i];
        //             i++;
        //         }
        //         x -= arr[j];
        //     } else {
        //         while (i < j) {
        //             if (arr[i] != arr[i + 1]) x += arr[i];
        //             i++;
        //         }
        //     }
        // }
        // cout << i << " " << j << " " << x << endl;
        // ans = max(ans, j - i + 1);
        // j++;
        if (j == 0) {
            if (arr[j] > x)
                i++;
            else {
                x -= arr[j];
                uniquePrices[arr[j]]++;
            }
        } else if (uniquePrices.find(arr[j]) == uniquePrices.end()) {
            if (arr[j] <= x) {
                x -= arr[j];
                uniquePrices[arr[j]]++;
            } else if (arr[j] <= ox) {
                while (arr[j] > x) {
                    uniquePrices[arr[i]]--;
                    if (uniquePrices[arr[i]] == 0) {
                        uniquePrices.erase(arr[i]);
                        x += arr[i];
                    }
                    for (auto data : uniquePrices)
                        cout << data.first << " : " << data.second << endl;
                    i++;
                }
                x -= arr[j];
            } else {
                while (i < j) {
                    uniquePrices[arr[i]]++;
                    if (uniquePrices[arr[i]] == 0) {
                        uniquePrices.erase(arr[i]);
                        x += arr[i];
                    }
                    i++;
                }
            }
        } else {
            uniquePrices[arr[j]]++;
        }
        cout << i << " " << j << " " << x << endl;
        ans = max(ans, j - i + 1);
        j++;
    }
    cout << ans << endl;
    cout << ox - x << endl;
}

int32_t main() {
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