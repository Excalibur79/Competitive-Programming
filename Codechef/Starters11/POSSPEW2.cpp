// Author: Ankur Saha
// Linkedin: https://www.linkedin.com/in/ankur-saha/
// Github: https://github.com/Excalibur79
// doesnt work
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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    inputarr(arr, n);
    unordered_set<int> posIndexes;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) posIndexes.insert(i);
    }
    // for (auto value : arr) cout << value << " ";
    if (posIndexes.empty()) {
        cout << 0 << endl;
    } else {
        while (k && posIndexes.size() < n) {
            k--;
            if (posIndexes.size() < n) {
                vector<int> newPosIndexes;
                for (auto index : posIndexes) {
                    int leftIndex = index - 1 >= 0 ? index - 1 : n - 1;
                    int rightIndex = index + 1 < n ? index + 1 : 0;
                    arr[leftIndex]++;
                    arr[rightIndex]++;
                    newPosIndexes.pb(leftIndex);
                    newPosIndexes.pb(rightIndex);
                }

                for (auto value : newPosIndexes) posIndexes.insert(value);
                newPosIndexes = {};
            } else
                break;
        }
        if (k > 0) {
            for (int i = 0; i < n; i++) {
                arr[i] += 2 * k;
            }
        }
        int summ = 0;
        for (int i = 0; i < n; i++) summ += arr[i];
        cout << summ << endl;
    }
    // printarr(arr, n);
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