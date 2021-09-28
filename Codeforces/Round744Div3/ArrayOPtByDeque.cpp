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

int invCount = 0;
vector<int> temp;

void merge(vector<int> &arr, int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;

    // cout << "Merging :";
    // for (int x = low; x <= mid; x++) cout << arr[x] << " ";
    // cout << " + ";
    // for (int x = mid + 1; x <= high; x++) cout << arr[x] << " ";
    // cout << " = ";

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i];
            i++;
        } else {
            temp[k++] = arr[j];
            invCount += mid - i + 1;
            j++;
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= high) {
        temp[k++] = arr[j++];
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i];
    }

    // for (int i = low; i <= high; i++) cout << temp[i] << " ";
    // cout << endl;
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

void solve() {
    invCount = 0;
    temp = {};
    int n;
    cin >> n;
    vi arr(n);
    vi newArr = {};
    temp.resize(n, 0);
    inputarr(arr, n);
    list<int> l;
    for (auto value : arr) {
        if (l.empty())
            l.push_back(value);
        else {
            if (value <= l.front())
                l.push_front(value);
            else
                l.push_back(value);
        }
    }
    while (!l.empty()) {
        cout << l.front() << " ";
        newArr.pb(l.front());
        l.pop_front();
    }
    cout << endl;
    mergeSort(newArr, 0, n - 1);
    cout << invCount << endl;
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