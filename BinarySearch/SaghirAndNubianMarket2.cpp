#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;
 ll m;

bool canBuy(vector<ll> &arr,ll numberOfItems,ll budget){
    ll sum=0;
    for(int i =0;i<numberOfItems;i++){
        sum += arr[i];
    }   
   // cout<<"For m : "<<numberOfItems<<" and sum : "<<sum<<" result : "<<(sum<=budget?"TRUE":"FALSE")<<endl;
    return sum<=budget;
}


int main(){
    ll n,s;
    cin>>n>>s;
    vector<ll> arr;   
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        arr.push_back(x);
    }
    ll l=1,h=n,mid,res=0,cost=0;
    while(l<=h){
        mid = (l+h)/2;
        m = mid;
        //reinitializing arrray
        vector<ll> newArray;
        for(ll i=0;i<n;i++){
            ll value = arr[i] + ((i+1)*m);
            newArray.push_back(value);
        }
        sort(newArray.begin(),newArray.end());
        //=====================
        ll sum = 0;
        for(ll i=0;i<mid;i++){
            sum +=newArray[i];
        }
        //printVector(arr);
        if(canBuy(newArray,mid,s)){
            res = mid;
            cost=sum;
            l=mid+1;
        }
        else
            h = mid - 1;
    }
    cout<<res<<" ";
    
    
    cout<<cost<<endl;
}