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

int revCount = 0;

void Merge(auto &arr, auto &temp, int low, int mid, int high) {
    int j = mid + 1;
    for (int i = low; i <= mid; i++) {
        while (j <= high && arr[i] > 2 * arr[j]) {
            j++;
        }
        revCount += (j - (mid + 1));
    }
    j = mid + 1;
    int i = low, k = low;
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= high) temp[k++] = arr[j++];

    for (int i = low; i <= high; i++) arr[i] = temp[i];
}

void mergeSort(auto &arr, auto &temp, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, temp, low, mid);
        mergeSort(arr, temp, mid + 1, high);
        Merge(arr, temp, low, mid, high);
    }
}
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> temp(n);
    inputarr(arr, n);
    mergeSort(arr, temp, 0, n - 1);
    cout << revCount << endl;
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