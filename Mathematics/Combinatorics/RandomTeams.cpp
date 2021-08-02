#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll nCr(ll n, ll k) {
    if (n < k) return 0;
    if (n == k) return 1;
    ll res = 1;
    if (k > n - k) k = n - k;
    for (ll i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    if(m==1){
        cout<<nCr(n,2)<<" "<<nCr(n,2)<<endl;
    }
    else{
        ll maximumAns = nCr(n-m+1,2);
        ll divident = n/m;
        ll remainder = n%m;
        ll ans1 = (m - remainder) * nCr(divident,2);
        ll ans2 = remainder * nCr(divident+1,2);
        cout<<ans1+ans2<<" "<<maximumAns<<endl;

    }
    return 0;
}