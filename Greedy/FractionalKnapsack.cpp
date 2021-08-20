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

class Item {
   public:
    int value, weight;
    Item(int i, int w) {
        value = i;
        weight = w;
    }
};

bool comp(vector<int> a, vector<int> b) { return a[2] > b[2]; }

void solve() {
    int w = 50, n = 3;
    vector<Item> arr;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        Item newitem(a, b);
        arr.pb(newitem);
    }
    vector<vector<int>> ratioArr;
    for (auto data : arr) {
        ratioArr.pb({data.value, data.weight, data.value / data.weight});
    }
    sort(ratioArr.begin(), ratioArr.end(), comp);
    int wt = 0;
    int sum = 0;
    for (auto data : ratioArr) {
        if (wt < w) {
            if (wt + data[1] <= w) {
                sum += data[0];
                wt += data[1];
            } else {
                sum += (data[0] / data[1]) * (w - wt);
                wt = w;
            }
        } else
            break;
    }
    cout << sum << endl;
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