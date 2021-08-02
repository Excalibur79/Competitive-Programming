#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll> arr;
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            arr.push_back(x);
        }
        int X =arr[0];
        for(int i=1;i<n;i++){
            X = X & arr[i];
        }
        ll minValue=arr[0]^X;
        for(int i=1;i<n;i++){
            minValue=minValue |( arr[i]^X);
        }
        cout<<X<<" "<<minValue<<endl;
    }
    return 0;
}