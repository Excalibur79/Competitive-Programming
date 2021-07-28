#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;

int recur(vector<int> &arr,int n,int m,int a,int b){
    if(n==0)
        return 0;
    if(arr[n]!=-1)
        return arr[n];
    else if(n>=m){//have two options open
        int returnValue = min( (a+recur(arr,n-1,m,a,b)) , (b+recur(arr,n-m,m,a,b)) );
        arr[n]=returnValue;
        return arr[n];
    }         
    else{
        int returnValue=a+recur(arr,n-1,m,a,b);
        arr[n]=returnValue;
        return arr[n];
    }
}

int main(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    vector<int> arr(n+1,-1);
    int ans=recur(arr,n,m,a,b);
    cout<<ans<<endl;
}