#include <bits/stdc++.h>

#include <cmath>
#include <iostream>
#define ll long long
using namespace std;

vector<int> generateRoatatedArr(vector<int> &a, vector<int> &b, int pivot) {
    vector<int> ans;
    if (pivot > 0) {
        int x = -1;
        for (int i = pivot; i < b.size(); i++) {
            x++;
            int value = (a[x] + b[i]) % b.size();
            ans.push_back(value);
        }
        for (int i = 0; i < pivot; i++) {
            x++;
            int value = (a[x] + b[i]) % b.size();
            ans.push_back(value);
        }

    } else {
        for (int i = 0; i < b.size(); i++) {
            int value = (a[i] + b[i]) % b.size();
            ans.push_back(value);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        vector<int> b;
        multiset<pair<int, int>> m;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            b.push_back(x);
        }
        for (int i = 0; i < n; i++) {
            int value = (a[0] + b[i]) % n;
            m.insert({value, i});
        }
        // for(auto value:m)
        //     cout<<value.first<<" "<<value.second<<endl;
        auto beginIt = m.begin();
        pair<int, int> pair1 = *beginIt++;
        pair<int, int> pair2 = *beginIt;
        vector<int> resultArr;
        if (pair1.first == pair2.first) {
            auto v1 = generateRoatatedArr(a, b, pair1.second);
            auto v2 = generateRoatatedArr(a, b, pair2.second);
            if (v1 < v2)
                resultArr = v1;
            else
                resultArr = v2;
        } else {
            resultArr = generateRoatatedArr(a, b, pair1.second);
        }
        for (auto value : resultArr) cout << value << " ";
        cout << endl;
    }
    return 0;
}