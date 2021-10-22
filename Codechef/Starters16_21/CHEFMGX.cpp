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

vector<bool> primeData(10000001, true);
vector<int> numberOfPrimes(10000001, 0);

void sieve() {
    for (int i = 2; i <= sqrt(10000000); i++) {
        if (primeData[i]) {
            for (int j = i * i; j <= 10000000; j = j + i) {
                primeData[j] = false;
            }
        }
    }
    int summ = 0;
    for (int i = 1; i <= 10000000; i++) {
        if (primeData[i]) {
            numberOfPrimes[i] = ++summ;
        }
        numberOfPrimes[i] = summ;
    }
}

void solve() {
    int x, y;
    cin >> x >> y;
    // for (int i = 0; i <= y; i++) cout << primeData[i] << " ";
    // cout << endl;
    // for (int i = 0; i <= y; i++) cout << numberOfPrimes[i] << " ";
    // cout << endl;
    if (y == x)
        cout << 0 << endl;
    else if (y - x == 1)
        cout << 1 << endl;
    else {
        int primes = numberOfPrimes[y] - numberOfPrimes[x + 1];
        cout << y - x + 1 - primes - 1 << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}