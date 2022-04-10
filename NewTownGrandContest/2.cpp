#include <bits/stdc++.h>  // header file includes every Standard library
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int nutan = 0, tulsa = 0;
    for (char data : s) {
        if (data == 'N')
            nutan++;
        else
            tulsa++;
    }
    if (nutan > tulsa)
        cout << "Nutan";
    else
        cout << "Tulsa";
    return 0;
}