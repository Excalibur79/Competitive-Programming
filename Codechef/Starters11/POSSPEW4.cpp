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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    inputarr(arr, n);
    int firstLeft = -1;
    int firstRight = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            firstLeft = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] > 0) {
            firstRight = i;
            break;
        }
    }
    if (firstLeft == -1 || firstRight == -1) {
        cout << 0 << endl;
        return;
    }
    vector<int> leftArr(n, 0);
    vector<int> rightArr(n, 0);
    // generating leftDisttance
    int leftDistance = 0;
    for (int i = firstLeft; i < n; i++) {
        if (arr[i] > 0) {
            leftArr[i] = 0;
            leftDistance = 0;
        } else
            leftArr[i] = ++leftDistance;
    }
    for (int i = 0; i < firstLeft; i++) {
        leftArr[i] = ++leftDistance;
    }
    //==================================

    // generating rightDistance
    int rightDistance = 0;
    for (int i = firstRight; i >= 0; i--) {
        if (arr[i] > 0) {
            rightArr[i] = 0;
            rightDistance = 0;
        } else
            rightArr[i] = ++rightDistance;
    }
    for (int i = n - 1; i > firstRight; i--) {
        rightArr[i] = ++rightDistance;
    }
    //==========================

    // printarr(leftArr, n);
    // cout << endl;
    // printarr(rightArr, n);
    // cout << endl;
    int totalContribution = 0;
    for (int i = 0; i < n; i++) {
        totalContribution += arr[i];
        totalContribution +=
            (max((int)0, 2 * (k - min(leftArr[i], rightArr[i]))));
    }
    cout << totalContribution << endl;
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