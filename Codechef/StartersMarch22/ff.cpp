#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<vector<int>> res;

    for (int i = n - 1; i >= 0; i--) {
        if (str[i] == '0') {
            int x = i + 1;
            for (int j = 0; j <= i; j++) {
                if (str[j] == '1')
                    str[j] = '0';
                else
                    str[j] = '1';
            }
            res.push_back({1ll, x});
        }
    }
    int siz = res.size();
    cout << siz << endl;
    for (auto x : res) cout << x[0] << " " << x[1] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}