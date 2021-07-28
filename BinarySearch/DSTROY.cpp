#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<ll> arr;
    vector<int> prefixArr;
    ll sum =0;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        arr.push_back(x);
        sum+=x;
        prefixArr.push_back(sum);
    }
    int beam=0;
    int ans=0;
    for(int i=0;i<n;i++){
        beam+=k;       
        auto it = lower_bound(prefixArr.begin(),prefixArr.end(),beam);
        if(it!=prefixArr.end()){
            ans++;
        }
        else{           
            break;
        }
    }
    cout<<ans<<endl;
   
}