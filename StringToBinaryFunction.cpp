
#include <cmath>
#include <iostream>
using namespace std;

#define long long ll;

// string decimalToBinary(ll n, ll fix) {
//     string bin = "";
//     while (n) {
//         bin += to_string(n % 2);
//         n /= 2;
//     }
//     reverse(bin.begin(), bin.end());
//     // Make of Size fix
//     int cur = bin.size();
//     string res = string(fix - cur, '0');
//     res += bin;
//     return res;
// }

int main() {
    string s;
    cin >> s;
    int powr = 0;
    int ans = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '1') {
            ans += pow(2, powr);
        }
        powr++;
    }
    cout << ans << endl;
    return 0;
}