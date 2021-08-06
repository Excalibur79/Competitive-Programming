// Author: Ankur Saha
// Linkedin: https://www.linkedin.com/in/ankur-saha/
// Github: https://github.com/Excalibur79

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
const int MOD = 1e9 + 7;
const ll INF = 1e18;
#define inputarr(arr, n)       \
    for (ll i = 0; i < n; i++) \
        cin >> arr[i];
#define printarr(arr, n)       \
    for (ll i = 0; i < n; i++) \
        cout << arr[i] << ' ';

bool sortComparator(pll a, pll b)
{
    if (a.first < b.first)
        return true;
    if (a.first > b.first)
        return false;
    return a.second < b.second;
}

void solve()
{
    vector<vector<int>> range = {{5, 6}, {1, 3}, {8, 10}};
    unordered_map<int, int> m;
    vector<int> arr;
    for (auto r : range)
    {
        m[r[0]] = 1;
        m[r[1]] = 2;
        arr.pb(r[0]);
        arr.pb(r[1]);
    }
    sort(arr.begin(), arr.end());
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        int index = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        if (arr[index] == x)
            cout << "YES" << arr[index] << endl;
        else
        {
            if (m[arr[index]] == 2)
            {
                cout << "YES" << arr[index] << endl;
            }
            else
            {
                cout << "NO" << arr[index] << endl;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}