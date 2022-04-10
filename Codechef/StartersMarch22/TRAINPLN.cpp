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

bool comp(pii a, pii b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}

int ans = INT_MIN;

int recur(vector<pii> &arr, int i, int trainingsCompleted) {
    if (i >= arr.size()) return 0;
    int res;
    if (trainingsCompleted >= arr[i].second) {
        int val1 = arr[i].first + recur(arr, i + 1, trainingsCompleted + 1);
        int val2 = recur(arr, i + 1, trainingsCompleted);

        ans = max(
            ans, max(val1 / trainingsCompleted + 1, val2 / trainingsCompleted));
        return res;
    }
    return 0;
}

pair<int, int> recur(vector<pii> &arr, int i, int trainingsCompleted) {
    if (i >= arr.size()) return {0, 0};
    int res;
    if (trainingsCompleted >= arr[i].second) {
        pair<int, int> call1 = recur(arr, i + 1, trainingsCompleted + 1);
        int val1 = (arr[i].first + call1.first) / call1.second;
        pair<int, int> call2 = recur(arr, i + 1, trainingsCompleted);
        int val1 = (arr[i].first + call1.first) / call1.second;
    }
}

void solve() {
    int n;
    cin >> n;
    vi a(n), b(n);
    inputarr(a, n);
    inputarr(b, n);
    vector<pii> arr;
    for (int i = 0; i < n; i++) arr.pb(mp(a[i], b[i]));
    sort(arr.begin(), arr.end(), comp);
    for (auto data : arr) cout << data.first << " " << data.second << endl;
    recur(arr, 0, 0);
    cout << ans << endl;
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