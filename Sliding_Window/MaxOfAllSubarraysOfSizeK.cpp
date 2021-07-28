#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;

void printList(vector<int> &arr,list<int> &l){
    for(auto id:l){
        cout<<arr[id]<<" ";
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    } 
    //Note we will store indexes not original values  
    list<int> l;
    for(int i=0;i<k;i++){
        while(!l.empty() && arr[l.back()]<arr[i]){
            l.pop_back();
        }
        l.push_back(i);
    }
    //printList(arr,l);
    cout<<arr[l.front()]<<" ";
    for(int i=k;i<n;i++){
        if(i-k==l.front())
            l.pop_front();
        while(!l.empty()&& arr[l.back()]<arr[i]){
            l.pop_back();
        }
        l.push_back(i);
        cout<<arr[l.front()]<<" ";
    }

    return 0;
}