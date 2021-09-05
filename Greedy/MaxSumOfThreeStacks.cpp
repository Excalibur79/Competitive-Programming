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

void solve() {
    int p, q, r;
    cin >> p >> q >> r;
    vi a(p), b(q), c(r);
    inputarr(a, p);
    inputarr(b, q);
    inputarr(c, r);

    int sumA = accumulate(a.begin(), a.end(), 0),
        sumB = accumulate(b.begin(), b.end(), 0),
        sumC = accumulate(c.begin(), c.end(), 0);
    int aPointer = 0;
    int bPointer = 0;
    int cPointer = 0;
    while (((sumA != sumB) || (sumA != sumC) || (sumB != sumC)) &&
           (aPointer < p && bPointer < q && cPointer < r)) {
        cout << "SumA :" << sumA << " SumB :" << sumB << " sumC :" << sumC
             << endl;
        if (sumA >= sumB && sumA >= sumC) {
            sumA -= a[aPointer];
            aPointer++;
        } else if (sumB >= sumA && sumB >= sumC) {
            sumB -= b[bPointer];
            bPointer++;
        } else if (sumC >= sumA && sumC >= sumB) {
            sumC -= c[cPointer];
            cPointer++;
        }
    }
    cout << ((sumA == sumB && sumB == sumC) ? sumA : 0) << endl;
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