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
       ll indexOfMax=-1;
       ll maxValue = INT_MIN;
        for(ll i=0;i<n;i++){
            if(arr[i]>maxValue){
                maxValue = arr[i];
                indexOfMax = i;
            }
        }
        ll j1=0,j2=0;
        //Left Window Valid
        ll leftMinValue = INT_MAX;
        ll leftAns = INT_MIN;
        if(indexOfMax>0){
            for(ll j=indexOfMax-1;j>=0;j--){
                if(arr[j]<leftMinValue){
                   leftAns = max(leftAns,maxValue * arr[j]);
                   leftMinValue = arr[j];
                }                
            }
        }
        //Right Window Valid
        ll rightMinValue = INT_MAX;
        ll rightAns = INT_MIN;
        if(indexOfMax<n-1){
            for(ll j=indexOfMax+1;j<n;j++){
                if(arr[j]<rightMinValue){
                    rightAns = max(rightAns,maxValue *arr[j]);
                    rightMinValue = arr[j];
                }
            }
        }
        //Mid WIndow
        ll midMinValue = INT_MAX;
        ll midAns = INT_MIN;
        ll x=indexOfMax;
        ll y = indexOfMax;
         leftMinValue = INT_MAX;
         rightMinValue = INT_MAX;
        while(x!=0 || y!=n-1){
            if(x!=0){
                x--;
            }
            if(y!=n-1){
                y++;
            }
            if(arr[x]<leftMinValue){
                leftMinValue = arr[x];
            }
            if(arr[y]<rightMinValue){
                rightMinValue=arr[y];
            }
            ll minValue = min(leftMinValue,rightMinValue);
            midAns = max(midAns,maxValue*minValue);

        }
        ll m = max(leftAns,rightAns);
        cout<<(max(m,midAns))<<endl;

    }
    return 0;
}