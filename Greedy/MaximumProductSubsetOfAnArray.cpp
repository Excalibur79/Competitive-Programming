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

string decimalToBinary(ll n, ll fix) {
    string bin = "";
    while (n) {
        bin += to_string(n % 2);
        n /= 2;
    }
    reverse(bin.begin(), bin.end());
    // Make of Size fix
    int cur = bin.size();
    string res = string(fix - cur, '0');
    res += bin;
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.pb(x);
    }
    int zeroCount = 0, maxNegetive = INT_MIN, negetiveNumbers = 0, prod = 1;
    for (int value : arr) {
        if (value == 0) {
            zeroCount++;
            continue;
        } else if (value < 0) {
            negetiveNumbers++;
            maxNegetive = max(maxNegetive, value);
        }
        prod = prod * value;
    }
    if (zeroCount == n)  // all zero numbers hole max ans ofc zero
        cout << 0 << endl;
    else if (negetiveNumbers == 1 &&
             zeroCount == n - 1) {  // if 0,0,0,0,0,0,0,-1  hoi ba kichu then
                                    // max ans is ofc 0
        cout << 0 << endl;
    } else {
        if (negetiveNumbers % 2 !=
            0) {  // signifying numbers of neg numbers is odd , NOTE: even
                  // numbers  of neg numbers makes it pos while odd numbers of
                  // neg umbers makes it negetive.Now if its odd numbers of neg
                  // numbers -1,-2,-5,9,7 then ommiting -1 is best which means
                  // maxNumber among the neg numbers
            prod = prod / maxNegetive;
        }
        cout << prod << endl;
    }
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