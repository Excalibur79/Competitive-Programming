#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<bool> arr(100000001,true);
    for(ll i=2;i<=100000000;i++){
        if(arr[i]){
            for(ll j=i*i;j<=100000000;j+=i){
                arr[j] = false;
            }
        }
    }
   vector<ll> ans;
   for(ll i=2;i<=100000000;i++){
       if(arr[i])
        ans.push_back(i);
   }
   for(ll i=0;i<ans.size();i+=100)
    cout<<ans[i]<<endl;
    return 0;
}