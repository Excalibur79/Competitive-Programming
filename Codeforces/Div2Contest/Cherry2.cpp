#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;
int main(){
     ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> arr;
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
            arr.push_back(x);
        }
        ll ans = 0;
        for(int i =1;i<n;i++){
            ans = max(ans,arr[i-1]*arr[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}