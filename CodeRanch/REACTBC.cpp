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

bool comp(vector<int> &instructor1, vector<int> &instructor2) {
    if (instructor1[0] == instructor2[0])
        return instructor1[1] < instructor2[1];
    return instructor1[0] < instructor2[0];
}

void solve() {
    int n, d;
    cin >> n >> d;
    vector<vector<int>> instructors;
    multiset<pair<int, int>> ms;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        instructors.pb({a - 1, b, c});
    }
    sort(instructors.begin(), instructors.end(), comp);
    int idx = 0;
    for (int i = 0; i < d; i++) {
        // finding instructors for di th day
        int j;
        for (j = idx; j < n; j++) {
            if (instructors[j][0] == i) {
                ms.insert({instructors[j][2], instructors[j][1]});
            } else
                break;
        }
        idx = j;
        // for (auto data : ms) cout << data.first << " " << data.second << " ,
        // "; cout << endl;
        if (!ms.empty()) {
            auto lastinstructorIt = --ms.end();
            int lastinstructorDaysLeft = lastinstructorIt->second - 1;
            int lastinstructorSadness = lastinstructorIt->first;
            ms.erase(lastinstructorIt);
            if (lastinstructorDaysLeft > 0)
                ms.insert({lastinstructorSadness, lastinstructorDaysLeft});
        }
    }
    int remainingSadness = 0;
    for (auto data : ms) remainingSadness += data.first * data.second;

    cout << remainingSadness << endl;
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