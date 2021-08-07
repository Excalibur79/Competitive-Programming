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

bool sortComparator(pll a, pll b) {
    if (a.first < b.first) return true;
    if (a.first > b.first) return false;
    return a.second < b.second;
}

void printQueue(auto &q) {
    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
}

void printpairQueue(auto &pq) {
    while (!pq.empty()) {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }
}

bool comp(pii p1, pii p2) {
    if (p1.first <= p2.first) return true;
    return false;
}

void solve() {
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(3);
    q.push(5);
    q.push(0);
    q.push(1);
    q.push(9);
    q.push(1);
    // printQueue(q);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pii>> pq;
    pq.push(mp(3, 5));
    pq.push(mp(3, 4));
    pq.push(mp(6, 1));
    pq.push(mp(0, 3));
    printpairQueue(pq);
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