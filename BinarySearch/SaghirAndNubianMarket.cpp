#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;
 ll m;

 //Didnt work correct program is SaghirAndNubianMarket2.cpp

bool canBuy(vector<pair<ll,ll>> &arr,ll numberOfItems,ll budget){
    ll sum=0;
    for(int i =1;i<=numberOfItems;i++){
        sum = sum + arr[i].first + ((arr[i].second)*numberOfItems);
    }   
    
   // cout<<"For m : "<<numberOfItems<<" and sum : "<<sum<<" result : "<<(sum<=budget?"TRUE":"FALSE")<<endl;
    return sum<=budget;
}
bool comparator(pair<ll,ll> a,pair<ll,ll> b){
    ll aValue = a.first + (a.second*m);
    ll bValue = b.first + (b.second * m);
    return aValue<bValue;
}
void printVector(vector<pair<ll,ll>> &arr){
    cout<<"For M : "<<m<<"   =>";
    for(auto value:arr){
        cout<<"("<<value.first<<","<<value.second<<")"<<" ";
    }
    cout<<endl;
}
int main(){
    ll n,s;
    cin>>n>>s;
    vector<pair<ll,ll>> arr;
    arr.push_back({0,0});
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        arr.push_back({x,i});
    }
    ll l=1,h=n,mid,res=0;
    while(l<=h){
        mid = (l+h)/2;
        m = mid;
        sort(arr.begin() , arr.end() , comparator);
        //printVector(arr);
        if(canBuy(arr,mid,s)){
            res = mid;
            l=mid+1;
        }
        else
            h = mid - 1;
    }
    cout<<res<<" ";
    
    ll sum = 0;
    for(int i =1;i<=res;i++){
        sum+=arr[i].first + (arr[i].second*res);
    }
    cout<<sum<<endl;
}