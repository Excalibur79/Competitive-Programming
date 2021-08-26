#include <bits/stdc++.h>

#include <cmath>
#include <iostream>
#define ll long long
using namespace std;

ll binaryToDecimal(string s) {
    ll number = 0;
    for (int i = 0; i < s.length(); i++) {
        number += (s[s.length() - i - 1] - '0') * pow(2, i);
    }
    return number;
}

int main() {
    string n;
    cin >> n;
    cout << binaryToDecimal(n) << endl;
    return 0;
}