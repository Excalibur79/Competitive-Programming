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
    int hc, dc, hm, dm, k, healthIncrease, attackIncrease;
    cin >> hc >> dc >> hm >> dm >> k >> attackIncrease >> healthIncrease;
    bool canDefeat = false;
    for (int i = 0; i <= k; i++) {
        int newAttack = i * attackIncrease + dc;
        int newHealth = (k - i) * healthIncrease + hc;
        int playerDeadIn = ceil((newHealth * 1.0) / (dm * 1.0));
        int monsterDeadIn = ceil((hm * 1.0) / (newAttack * 1.0));
        // cout << "monster dead in :" << monsterDeadIn
        //      << " player dead in : " << playerDeadIn << endl;
        if (monsterDeadIn <= playerDeadIn) {
            canDefeat = true;
            break;
        }
    }
    if (canDefeat)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}