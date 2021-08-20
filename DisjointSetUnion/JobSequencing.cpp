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

// Disjoint Set Functions
vector<int> Parent;

void makeSet(int n) {
    for (int i = 0; i <= n; i++) {
        Parent.pb(i);
    }
}

int Find(int u) {
    if (Parent[u] == u) return u;
    return Parent[u] = Find(Parent[u]);
}

void Union(int left, int right) {
    right = Find(right);
    left = Find(left);
    Parent[right] = left;
}
//=======================

class Job {
   public:
    int id, dead, profit;
    Job(int a, int b, int c) {
        id = a;
        dead = b;
        profit = c;
    }
};

bool comp(Job a, Job b) { return a.profit > b.profit; }

void solve() {
    int n;
    cin >> n;
    vector<Job> arr;
    int maxValue = n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;  // id //deadline profit
        Job newJob(a, b, c);
        arr.push_back(newJob);
        maxValue = max(maxValue, b);
    }
    makeSet(maxValue);
    sort(arr.begin(), arr.end(), comp);
    for (auto data : arr) {
        int id = data.id;
        int deadline = data.dead;
        int profit = data.profit;
        int parent = Find(deadline);
        if (parent > 0) {
            Union(parent - 1, parent);
            cout << id << " ";
        }
    }
    cout << endl;
    for (int i = 0; i < Parent.size(); i++) cout << i << " ";
    cout << endl;
    printarr(Parent, Parent.size());
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