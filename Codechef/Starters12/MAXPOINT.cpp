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

bool comp(vector<double> &a, vector<double> &b) { return a[0] > b[0]; }

int evaluate(auto &data) {
    // for (auto value : data)
    //     cout << value[0] << " " << value[1] << " " << value[2] << endl;
    int leftTime = 240;
    int ans = 0;
    for (auto value : data) {
        int points = value[1];
        int duration = value[2];
        if (duration * 20 <= leftTime) {
            leftTime -= duration * 20;
            ans += 20 * points;
        } else {
            ans += points * (leftTime / duration);
            leftTime = leftTime % duration;
        }
        // cout << "Time :" << leftTime << " points:" << ans << endl;
    }
    return ans;
}

void solve() {
    vector<double> time(3);
    vector<double> marks(3);
    inputarr(time, 3);
    inputarr(marks, 3);
    vector<vector<double>> data;
    for (int i = 0; i < 3; i++) {
        vector<double> p = {(marks[i] * 1.0) / (time[i] * 1.0), marks[i],
                            time[i]};
        data.pb(p);
    }
    int res = INT_MIN;
    for (int i = 1; i <= 6; i++) {
        res = max(res, evaluate(data));
        next_permutation(data.begin(), data.end());
    }

    cout << res << endl;
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