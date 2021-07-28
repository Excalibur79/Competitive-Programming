#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> vect;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        vect.push_back({x,y});
    }
    sort(vect.begin(),vect.end());
    int happy=false;
    for(int i=1;i<n;i++){
        if(vect[i-1].second>vect[i].second){
            happy=true;
            break;
        }
    }
    cout<<(happy?"Happy Alex":"Poor Alex");
    return 0;
}