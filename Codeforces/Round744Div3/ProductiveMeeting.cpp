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
    vi arr(n), newArr(n);
    inputarr(arr, n);
    sort(arr.begin(), arr.end());
    int i = 0, j = n - 1;
    newArr = arr;
    int steps = 0;
    while (i < j) {
        for (int x = 0; x < arr[i]; x++) {
            steps++;
            arr[i]--;
            arr[j]--;
        }
        if (arr[i] == 0) i++;
        if (arr[j] == 0) j--;
    }
    cout << steps << endl;
    i = 0, j = n - 1;
    while (i < j) {
        for (int x = 0; x < newArr[i]; x++) {
            cout << i + 1 << " " << j + 1 << endl;
            newArr[i]--;
            newArr[j]--;
        }
        if (newArr[i] == 0) i++;
        if (newArr[j] == 0) j--;
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