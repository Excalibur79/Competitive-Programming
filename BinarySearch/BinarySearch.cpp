#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int to_find;
    cin>>to_find;

    int l=0,h=n-1,mid;
    while(l<=h){
        mid=(l+h)/2;
        if(arr[mid]==to_find){
            cout<<"found";
            break;
        }
        else if(to_find>arr[mid])
            l=mid+1;
        else
            h=mid-1;
    }
}