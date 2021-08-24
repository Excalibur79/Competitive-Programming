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

bool Sorted(auto arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (i + 1 != arr[i]) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr;
    int steps = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.pb(x);
    }
    for (int i = 0; i < n; i++) {
        if (Sorted(arr)) break;
        for (int j = 0; j < n; j++) {
            if ((i + 1) % 2 == 0) {
                if ((j + 1) % 2 == 0) {
                    if (arr[j] > arr[j + 1]) {
                        int temp = arr[j + 1];
                        arr[j + 1] = arr[j];
                        arr[j] = temp;
                    }
                }
            } else {
                if ((j + 1) % 2 != 0) {
                    if (arr[j] > arr[j + 1]) {
                        int temp = arr[j + 1];
                        arr[j + 1] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
        }
        // printarr(arr, n);
        // cout << endl;
        steps++;
    }
    cout << steps << endl;
}

int main() {
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