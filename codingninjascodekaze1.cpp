#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long int

#define inputarr(arr, n) \
    for (ll i = 0; i < n; i++) cin >> arr[i];

set<int> blackList;
map<int, int> frequency;

bool comp(pair<int, int> &a, pair<int, int> &b) {
    if (a.first * a.second == b.first * b.second) {
        int aStake = 0, bStake = 0;
        if (frequency.find(a.first + 1) != frequency.end())
            aStake += (a.first + 1) * frequency[a.first + 1];
        if (frequency.find(a.first - 1) != frequency.end())
            aStake += (a.first - 1) * frequency[a.first - 1];
        if (frequency.find(b.first + 1) != frequency.end())
            bStake += (b.first + 1) * frequency[b.first + 1];
        if (frequency.find(b.first - 1) != frequency.end())
            bStake += (b.first - 1) * frequency[a.first - 1];
        return aStake > bStake;
    }
    return a.first * a.second > b.first * b.second;
}

int maximumPoints(int n, vector<int> arr) {
    blackList.clear();
    frequency.clear();
    for (int data : arr) {
        frequency[data]++;
    }
    vector<pair<int, int>> p;
    for (auto data : frequency) {
        p.push_back(make_pair(data.first, data.second));
    }
    sort(p.begin(), p.end(), comp);
    for (auto data : p)
        cout << "(" << data.first << " , " << data.second << ") ";
    cout << endl;

    int ans = 0;
    for (pair<int, int> data : p) {
        if (blackList.find(data.first) == blackList.end()) {
            ans += data.first * data.second;
            blackList.insert(data.first - 1);
            blackList.insert(data.first + 1);
        }
    }
    return ans;
}

int32_t main() {
    // int n = 3;
    // vector<int> arr = {1, 2, 3};
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        inputarr(arr, n);
        cout << maximumPoints(n, arr) << endl;
    }

    return 0;
}