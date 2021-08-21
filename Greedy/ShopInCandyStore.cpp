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

void solve() {
    int candies[] = {3, 2, 1, 4, 5};
    int n = 5, k = 4;
    int x = 0, y = 0;
    int min = 0, max = 0;
    sort(candies, candies + n);
    int i = 0, j = n - 1;
    while (x < n) {
        min += candies[i];
        x += 1 + k;
        i++;
    }
    while (y < n) {
        max += candies[j];
        j--;
        y += 1 + k;
    }
    cout << min << " " << max << endl;
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