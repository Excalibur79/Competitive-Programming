#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }   
    int sum=0,ans=0;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==k)
            ans=i+1;
        
        auto it=m.find(sum);
        if(it==m.end())
            m[sum]=i;
        if(m.find(sum-k)!=m.end())
            ans=max(ans,i-m[sum-k]);
    }
    cout<<ans;
    return 0;
}