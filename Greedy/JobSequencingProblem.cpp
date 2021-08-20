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

class Job {
   public:
    int id, dead, profit;
    Job(int a, int b, int c) {
        id = a;
        dead = b;
        profit = c;
    }
};

bool comp(Job a, Job b) { return a.profit >= b.profit; }

void solve() {
    int n;
    cin >> n;
    vector<Job> arr;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;  // id //deadline profit
        Job newJob(a, b, c);
        arr.push_back(newJob);
    }

    sort(arr.begin(), arr.end(), comp);
    bool done[n] = {0};
    int day = 0, profit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = min(n - 1, arr[i].dead - 1); j >= 0; j--) {
            if (done[j] == false) {
                day++;
                profit += arr[i].profit;
                done[j] = true;
                break;
            }
        }
    }
    cout << day << " " << profit << endl;
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