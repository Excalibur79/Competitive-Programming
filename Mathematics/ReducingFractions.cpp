#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    ll numerator=1,denominator=1;
    for(ll i =0;i<n;i++){
        ll x;
        cin>>x;
        numerator*=x;
    }
    for(ll i =0;i<m;i++){
        ll x;
        cin>>x;
        denominator*=x;
    }
    ll gcd = __gcd(numerator,denominator);
    cout<<1<<" "<<1<<endl;
    cout<<(numerator/gcd)<<endl;
    cout<<(denominator/gcd)<<endl;
    
    return 0;
}