#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
        ll count =0;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){    
                if(i!=j){
                    float value = ((arr[i] - arr[j])*1.0/arr[i]*1.0) - ((arr[i] - arr[j])*1.0/arr[j]*1.0);
                    if(value<0)
                        count++;
                }
            }
        }
        cout<<count<<endl;
       
    }
    return 0;
}