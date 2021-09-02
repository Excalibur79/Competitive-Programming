// Wrong

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

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    inputarr(arr, n);
    reverse(arr.begin(), arr.end());
    vector<int> nge(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            nge[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    int steps = 0;
    int currIndex = 0;
    int nextIndex = nge[currIndex];
    bool pathExist = true;
    while (true) {
        if (nextIndex == -1) {
            if (currIndex != n - 1) pathExist = false;
            break;
        }
        currIndex = nextIndex;
        nextIndex = nge[currIndex];
        steps++;
    }
    cout << (pathExist ? steps : -1) << endl;
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