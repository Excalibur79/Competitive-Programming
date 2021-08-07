#include <bits/stdc++.h>

#include <cmath>
#include <iostream>
using namespace std;

bool canPlaceCows(vector<long long> &arr, long long minSpace,
                  int numberOfCows) {
    int i = 0;
    numberOfCows--;
    for (int j = 1; j < arr.size(); j++) {
        if ((arr[j] - arr[i]) >= minSpace) {
            numberOfCows--;
            i = j;
        }
        if (numberOfCows == 0) break;
    }
    return numberOfCows == 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<long long> arr;
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            arr.push_back(x);
        }
        sort(arr.begin(), arr.end());
        int l = 0, h = 1e9, mid, res;
        // T T T T T F F F F F F F
        while (l <= h) {
            mid = (l + h) / 2;
            if (canPlaceCows(arr, mid, c)) {
                res = mid;
                l = mid + 1;
            } else {  // its false
                h = mid - 1;
            }
        }
        cout << res << endl;
    }
}