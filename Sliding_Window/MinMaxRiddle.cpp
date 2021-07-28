#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;

vector<long long> riddle(vector<long long> arr){
    for(int size=1;size<=arr.size();size++){
        for(int i=0;i<size;i++){
            
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<long long> arr;
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        arr.push_back(x);
    }
    auto res=riddle(arr);
    for(auto value:res)
        cout<<value<<" ";
    return 0;
}