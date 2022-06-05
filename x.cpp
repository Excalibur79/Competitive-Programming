#include <bits/stdc++.h>
using namespace std;

double fun1(int n) {
    double ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += ((1 * 1.0) / i);
    }
    return ans;
}

double fun2(int n) { return log(n); }

int main() {
    // int i = 0;
    // cout << i << " " << i++ << endl;
    cout << fun1(55) << endl;
    cout << fun2(55) << endl;
    return 0;
}