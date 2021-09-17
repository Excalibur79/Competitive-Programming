#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
ll mod = 1000000007;
using namespace std;

ll n;

pair<ll, ll> find_top(vector<string> s) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (s[i][j] == '#') return make_pair(i, j);
}

bool same(vector<string> s, vector<string> t) {
    pair<ll, ll> Sij = find_top(s);
    pair<ll, ll> Tij = find_top(t);

    ll diffX = Tij.first - Sij.first;
    ll diffY = Tij.second - Sij.second;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int ii = i + diffX;
            int jj = j + diffY;
            if (ii >= 0 && ii < n && jj >= 0 && jj < n) {
                if (s[i][j] != t[ii][jj]) return false;
            } else {
                if (s.at(i).at(j) == '#') return false;
            }
        }
    }

    return true;
}

vector<string> rotateBy90(vector<string>& s) {
    vector<string> res;

    for (int i = 0; i < n; i++) {
        string tmp = "";
        for (int j = n - 1; j >= 0; j--) {
            tmp += s[j][i];
        }
        res.push_back(tmp);
    }

    return res;
}

ll count(vector<string> s) {
    ll res = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (s[i][j] == '#') res++;

    return res;
}

void solve() {
    cin >> n;
    vector<string> S(n), T(n);

    for (int i = 0; i < n; i++) cin >> S[i];
    for (int i = 0; i < n; i++) cin >> T[i];

    if (count(S) != count(T)) {  // symbols must be equal in both s,t
        cout << "No" << endl;
        return;
    }
    bool ok = 0;
    for (int i = 0; i < 4; i++) {  // 4 time rotation
        if (same(S, T)) {
            ok = 1;
            break;
        }
        S = rotateBy90(S);
    }

    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main() {
    ll t = 1;  // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}