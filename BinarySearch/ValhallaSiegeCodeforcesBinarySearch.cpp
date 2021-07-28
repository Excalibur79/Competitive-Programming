#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    vector<long long> warriors;
    vector<ll> arrows;
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        warriors.push_back(x);        
    }
    for(int i=0;i<q;i++){
        ll x;
        cin>>x;
        arrows.push_back(x);
    }
    vector<ll> prefixArray;
    ll Sum=0;
    for(int i=0;i<n;i++){
        Sum+=warriors[i];
        prefixArray.push_back(Sum);
    }
    ll arrowsUptilNow=0;
    for(int i=0;i<q;i++){
        arrowsUptilNow+=arrows[i];
        if(arrowsUptilNow>=Sum) arrowsUptilNow=0;
        auto it = lower_bound(prefixArray.begin(),prefixArray.end(),arrowsUptilNow);
        cout<<distance(it,prefixArray.end()) - (*it==arrowsUptilNow)<<endl;
    }
    return 0;
}