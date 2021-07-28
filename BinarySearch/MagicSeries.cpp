#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;
int main(){
    vector<int> arr = {0,0,0,0,0,1,2,3,4,5,4,3,2,1,2,3,4,5,4,3,2};
    int n = arr.size();
    vector<bool> Left(n);
    vector<bool> Right(n);
    //processing left=================
    int k = 0;
    for(int i =0;i<n;i++){
        if(arr[i]>=k+1){
            k++;
            if(k==5){
                Left[i]=true;
                k--;
            }
        }
        else
            k=arr[i];
    }
    //===============================
    //processing right===============
    k=0;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>=k+1){
            k++;
            if(k==5){
                Right[i]=true;
                k--;
            }
        }
        else
            k=arr[i];
    }
    //===============================

    for(auto value:arr)
        cout<<value<<" ";
    cout<<endl;
    for(auto value:Left)
        cout<<value<<" ";
    cout<<endl;
    for(auto value:Right)
        cout<<value<<" ";
    cout<<endl;

    bool found=false;
    for(int i=0;i<n;i++){
        if(Left[i] && Right[i]){
            found=true;
            break;
        }
    }
    cout<<(found?"Special mountain series with m exists":"special mountain series with m doesnt exist")<<endl;
    return 0;
}