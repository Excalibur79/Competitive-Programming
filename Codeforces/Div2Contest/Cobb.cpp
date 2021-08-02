#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll ans = INT_MIN;
        ll n,k;
        cin>>n>>k;
        vector<ll> arr;
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
            arr.push_back(x);
        }
        ll start = max(0ll,n-201);
        for(ll i=start;i<n;i++){
            for(ll j=i+1;j<n;j++){
                ans = max(ans, (i+1)*(j+1) - (k*(arr[j]|arr[i])) );
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}