#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long int
#define vi vector<int>
#define inputarr(arr, n) \
    for (ll i = 0; i < n; i++) cin >> arr[i];

int maxDifference(int n, vector<int> arr) {
    sort(arr.begin(), arr.end());
    return accumulate(arr.begin() + n / 2, arr.end(), 0) -
           accumulate(arr.begin(), arr.begin() + n / 2, 0);
}

int main() {}