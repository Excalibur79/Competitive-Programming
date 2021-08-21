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

bool comp(pair<double, double> a, pair<double, double> b) {
    if (a.first == b.first) return a.second > b.second;

    return a.first < b.first;
}

void solve() {
    int n, k;
    cin >> n >> k;
    double price[n];
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    vector<pair<double, double>> arr;
    for (int i = 0; i < n; i++) {
        arr.pb({price[i], (double)(i + 1)});
    }
    sort(arr.begin(), arr.end(), comp);
    int spent = 0;
    int ans = 0;
    // for (auto data : arr) {
    //     cout << data.first << " " << data.second << endl;
    // }
    for (auto data : arr) {
        int stockPrice = data.first;
        int numberOfStocks = data.second;
        if (spent + numberOfStocks * stockPrice <= k) {
            spent += numberOfStocks * stockPrice;
            ans += numberOfStocks;
        } else {
            int canBuy = (k - spent) / stockPrice;
            if (canBuy <= numberOfStocks) {
                spent += canBuy * stockPrice;
                ans += canBuy;
            }
            break;
        }
    }
    cout << ans << endl;
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