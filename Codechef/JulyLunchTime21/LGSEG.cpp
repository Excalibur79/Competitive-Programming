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
        ll n,k,s;
        cin>>n>>k>>s;
        vector<ll> arr;
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
            arr.push_back(x);
        }
        ll i=0,j=0,sum=arr[i];
        ll ans = INT_MIN;
        while(j<n){         
           sum+=arr[j];
           if(sum>s){
               while(sum>s){
                   sum-=arr[i];
                   i++;
               }
           }
            if(sum==s){
               if((j-i+1)%k==0){
                   ans = max(ans,j-i+1);
               }
           }
           j++;
        
        }
        // for(ll i=0;i<n;i++){
        //     sum+=arr[i];
        //     if(sum>=s){
        //         if((i+1)%k==0)
        //             ans =i+1;
        //     }
                
        // }
        cout<<ans<<endl;
    }
    
    return 0;
}