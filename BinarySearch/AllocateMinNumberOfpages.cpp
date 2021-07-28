#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;
#define ll long long

bool valuePossible(vector<ll> &pages,int numberOfStudents,int value){
    ll Sum=0;
    int currentStudent=1;
    for(int i=0;i<pages.size();i++){
        Sum+=pages[i];
        if(Sum>value){
            currentStudent++;
            Sum=pages[i];
        }
    }
   // cout<<"currentStudent : "<<currentStudent<<" "<<"value : "<<value<<" ans :"<<(currentStudent==numberOfStudents)<<endl; 
    return currentStudent<=numberOfStudents;

}

int main(){
    int n,m;
    cin>>n>>m;
    vector<ll> pages;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        pages.push_back(x);
    }
    ll l=0,h,sum=0;
    for(auto value:pages){
        sum+=value;
        l=max(l,value);
    }
    ll res=0,mid;
    h=sum;
    while(l<=h){
        mid = (l+h)/2;
        if(valuePossible(pages,m,mid)){
            res=mid;
            h=mid-1;
        }
        else
            l=mid+1;
    }
    cout<<res<<endl;
    return 0;
}