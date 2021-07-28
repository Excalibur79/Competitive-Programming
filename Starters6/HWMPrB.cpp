#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;

int recur(vector<vector<int>> t,vector<int> &arr,int n,int k,int initialK){
    if(n==0){
        t[n][k]=0;
        return 0;
    }
    if(t[n][k]!=-1)
        return t[n][k];        
    if(k>0){
        t[n][k] = min( arr[n-1]+recur(t,arr,n-1,initialK,initialK) , recur(t,arr,n-1,k-1,initialK) );
        return t[n][k];
    }
    else{
        t[n][k] = arr[n-1]+recur(t,arr,n-1,initialK,initialK);
        return  t[n][k];
    }        
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            arr.push_back(x);
        }
        vector<vector<int>> t;
        for(int i=0;i<n+1;i++){
            vector<int> p;
            for(int j=0;j<k+1;j++)
                p.push_back(-1);
            t.push_back(p);
        }
        int ans=recur(t,arr,n,k,k);
        cout<<ans<<endl;
    }
    return 0;
}