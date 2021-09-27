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
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    map<int, int> hashMap;
    int maxFrequency = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        hashMap[arr[i]]++;
        maxFrequency = max(maxFrequency, hashMap[arr[i]]);
    }
    int steps = 0;
    for (auto data : hashMap) {
        int key = data.first;
        int freq = data.second;
        if (x != 0) {
            freq += hashMap[data.first ^ x];
            if (freq > maxFrequency) {
                maxFrequency = freq;
                steps = hashMap[data.first ^ x];
            } else if (freq == maxFrequency)
                steps = min(steps, hashMap[data.first ^ x]);
        }
    }
    cout << maxFrequency << " " << steps << endl;
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