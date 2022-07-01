#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {};
    arr.insert(arr.begin() + 0, 5);
    for (int data : arr) cout << data << " ";
    cout << endl;
    cout << arr.size() << endl;
    return 0;
}