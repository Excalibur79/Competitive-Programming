#include <bits/stdc++.h>

#include <iostream>
using namespace std;

int countPairs(vector<int> &a, int n, int k) {
    set<int> s;
    for (int data : a) s.insert(data);
    auto it1 = s.begin();
    int ans = 0;
    int i = 0;
    while (s.size() > 0) {
        // cout << i << endl;
        int toFind = (2 * k) - *it1;
        auto it2 = s.lower_bound(toFind);
        ans += distance(s.end(), it2);
        s.erase(s.begin());
        it1 = s.begin();
    }
    return ans;
}

int main() {
    vector<int> a = {1, 6, 5, 2};
    int k = 7;
    cout << countPairs(a, a.size(), k);
}