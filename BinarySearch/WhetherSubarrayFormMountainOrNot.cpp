#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;
int main(){
    vector<int> arr = {2,3,2,4,4,6,3,2};
    vector<int> Left(arr.size());
    vector<int> Right(arr.size());

    //preprocess===============
    int lastIncr=0;
    for(int i=1;i<arr.size();i++){
        if(arr[i]>arr[i-1]){
            lastIncr = i;
        }
        Left[i] = lastIncr;
    }
    int n = arr.size();
    int firstDecr = n-1;
    Right[n-1] = n-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]>arr[i+1]){
            firstDecr = i;
        }
        Right[i] = firstDecr;
    }

    for(auto value:arr)
        cout<<value<<" ";
    cout<<endl;
    for(auto value:Left)
        cout<<value<<" ";
    cout<<endl;
    for(auto value : Right) 
        cout<<value<<" ";
    cout<<endl;

    //=================================


    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        bool ans = Right[l]==Left[r];
        cout<<(ans?"YES":"NO")<<endl;
    }

    return 0;
}