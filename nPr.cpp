#include <bits/stdc++.h>

#include <cmath>
#include <iostream>
#define ll long long
using namespace std;

ll fact(ll n) {
    if (n <= 1) return 1;
    return n * fact(n - 1);
}

ll binomialCoeff(ll n, ll k) {
    if (n < k) return 0;
    if (n == k) return 1;
    ll res = 1;
    if (k > n - k) k = n - k;
    for (ll i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

ll nPr(ll n, ll r) { return fact(r) * binomialCoeff(n, r); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> arr;
        unordered_map<ll, ll> m;
        for (ll i = 0; i < n; i++) {
            ll x;
            cin >> x;
            arr.push_back(x);
            m[x]++;
        }

        ll second = 0;
        for (auto value : m) {
            if (value.second > 1) {
                second = second + nPr(value.second, 2);
            }
        }
        ll first = nPr(n, 2);
        cout << (first - second) << endl;
    }
    return 0;
}