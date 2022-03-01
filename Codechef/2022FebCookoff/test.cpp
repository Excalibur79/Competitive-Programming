#include <bits/stdc++.h>
#define ln '\n'
#define pb push_back
using namespace std;
typedef long long ll;
#define vectorOfLLS vector<ll>;

int solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> nums;
    for (int i = 0; i < m; ++i) {
        ll c;
        cin >> c;
        nums.pb(c);
    }
    sort(nums.begin(), nums.end());
    ll temp = 0;
    for (int i = 0; i < nums.size(); ++i) {
        ll num = nums.at(i);
        for (int j = num; j > temp; j--) {
            cout << j << " ";
        }
        temp = num;
    }
    cout << ln;
}
int main() {
    ll t;
    cin >> t;
    while (t--) solve();
}