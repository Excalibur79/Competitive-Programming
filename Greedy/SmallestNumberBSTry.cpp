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

bool isValid(int s, int number) {
    int sum = 0;
    cout << number << " ";
    while (number) {
        sum += number % 10;
        number /= 10;
    }
    cout << sum << endl;
    if (sum == s) return true;
    return false;
}

void solve() {
    int s, d;
    cin >> s >> d;
    if (s > d * 9)
        cout << -1 << endl;
    else {
        int l = 1;
        string hNum;
        for (int i = 0; i < d; i++) hNum += '9';
        int h = stoi(hNum);
        int res = 0;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (isValid(s, mid)) {
                res = mid;
                h = mid - 1;
            } else
                l = mid + 1;
        }
        cout << endl << res << endl;
    }
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