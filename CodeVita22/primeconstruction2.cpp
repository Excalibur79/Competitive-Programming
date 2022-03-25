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
    for (int i = 0; i < s.length(); ++i) {
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
    int lcm = 1;
    for (int data : arr) {
        lcm = lcm * data / __gcd(lcm, data);
    }
    int val1 = lcm + minNumber;
    int val2 = 2;
    while (val1 > val2) {
        if (val1 % val2 == 0 && val2 != val1) {
            cout << "None";
            val2++;
            break;
        } else {
            cout << val1;
            val2 = val1 + 1;
        }
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