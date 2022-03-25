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

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

vi split_str(string s) {
    vi arr;
    string tmpx = "";
    for (int i = 0; i < (int)s.length(); ++i) {
        if (s[i] == ' ') {
            arr.pb(stoi(tmpx));
            tmpx = "";
        } else {
            tmpx += s[i];
        }
    }
    arr.pb(stoi(tmpx));
    return arr;
}

void solve() {
    string s;
    getline(cin, s);
    vector<int> arr;
    arr = split_str(s);
    // printarr(arr, arr.size());
    int minNumber = *min_element(arr.begin(), arr.end());
    int gcdVal = 1;
    int m = 1;
    for (int data : arr) {
        if (data != minNumber) {
            gcdVal = __gcd(gcdVal, data);
            m *= data;
        }
    }
    int lcm = m / gcdVal;
    // cout << "lcm : " << lcm << endl;
    if (isPrime(lcm + minNumber))
        cout << lcm + minNumber;
    else {
        bool f = false;
        for (int data : arr) {
            if (data != minNumber && data % 2 == 0) f = true;
        }
        if (minNumber % 2 == 0 && f) {
            cout << "None";
            return;
        }

        int y = lcm;
        for (int i = 2; y <= pow(10, 10); i++) {
            if (isPrime(y + minNumber)) {
                cout << y + minNumber;
                return;
            }
            y = lcm * i;
        }
        cout << "None";
    }
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