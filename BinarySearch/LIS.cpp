#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    set<int> s;
    s.insert(arr[0]);
    // s.insert(arr[1]);
    // s.insert(arr[2]);
    // cout << *(--s.end()) << endl;
    for (int data : arr) {
        int largestVal = *(--s.end());
        if (data > largestVal)  // non decreasing hole >= hoye jabe
            s.insert(data);
        else {
            auto removeIt = s.lower_bound(data);
            s.erase(removeIt);
            s.insert(data);
        }
    }
    // for (int data : s) cout << data << " ";
    cout << s.size() << endl;

    return 0;
}