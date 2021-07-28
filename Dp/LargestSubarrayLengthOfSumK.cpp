#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int recur(vector<vector<int>> &t,vector<int> &arr,int k,int n,int count,int sum){   
    if(n==0 && sum==k){
        t[n][sum]=count;
        return count;
    }
    else if(n==0 && sum!=k){
        t[n][sum]=0;
        return 0;
    }
    if(t[n][sum]!=-1)
        return t[n][sum];
    if(sum==k){
        t[n][sum]=max(count,max( recur(t,arr,k,n-1,count+1,sum+arr[n-1]) , recur(t,arr,k,n-1,0,0) ));
        return t[n][sum];
    }
    t[n][sum]=max( recur(t,arr,k,n-1,count+1,sum+arr[n-1]) , recur(t,arr,k,n-1,0,0) );
    return t[n][sum];    
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr;
    vector<vector<int>> t;   
   int totalSum=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x); 
        totalSum+=x;   
    }

     for(int i=0;i<=n;i++){
        vector<int> p;
        for(int j=0;j<=totalSum;j++)
            p.push_back(-1);
        t.push_back(p);           
    }
    int ans=recur(t,arr,k,arr.size(),0,0);
    cout<<ans<<endl;
    return 0;
}