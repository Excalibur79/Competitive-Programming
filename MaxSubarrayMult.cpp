#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> arr = {-1};

    vector<int> prefix(arr.size(), 0);
    int counter = 0;
    for (int i = arr.size() - 1; i >= 0; i--) {
        if (arr[i] < 0)
            counter++;
        else if (arr[i] == 0)
            counter = 0;
        prefix[i] = counter;
    }
    // check if all eles are 0s
    int zeroes = 0;
    int negs = 0;
    for (int data : arr) {
        if (data == 0) zeroes++;
        if (data < 0) negs++;
    }
    if (zeroes == arr.size() || zeroes + negs == arr.size()) {
        cout << 0 << endl;
        return 0;
    }
    if()
    // for (int data : prefix) cout << data << " ";
    // cout << endl;
    int ans = 1;
    int subb = 1;
    bool takeit = false;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 0) {
            subb = 1;
            takeit = false;
        } else if (arr[i] > 0)
            subb = subb * arr[i];
        else if (takeit || (!takeit && prefix[i] % 2 == 0)) {
            takeit = true;
            subb = subb * arr[i];
        }
        ans = max(ans, subb);
        // cout << ans << " ";
    }
    // cout << endl;
    cout << ans << endl;
    return 0;
}