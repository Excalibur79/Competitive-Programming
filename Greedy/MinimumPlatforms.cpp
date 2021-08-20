// Author: Ankur Saha
// Linkedin: https://www.linkedin.com/in/ankur-saha/
// Github: https://github.com/Excalibur79

// Two pointers approach

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
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dept[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = 6;
    sort(arr, arr + n);
    sort(dept, dept + n);
    int minPlatforms = 1;
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] <= dept[j])
            minPlatforms++;
        else
            j++;
    }
    cout << minPlatforms << endl;
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