#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;

int sieve(vector<bool> &arr,vector<int> &ans){
    int res = INT_MAX;
    for(int i=2;i<=sqrt(arr.size());i++){
        if(arr[i]){
            for(int j=i*i;j<arr.size();j+=i){
                arr[j] = false;
                if(ans[j] == ans[i])
                    ans[j]++;
                res = min(res,ans[j]);                
            }
        }
    }
    return arr.size()>4?res:1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<bool> arr(n+2,true);
    vector<int> ans(n+2,1);
    int res = sieve(arr,ans);
    // for(int i=0;i<arr.size();i++)
    //     cout<<i<<" ";
    // cout<<endl;    
    cout<<res<<endl;
    for(int i=2;i<arr.size();i++)
        cout<<ans[i]<<" ";
      cout<<endl;
    return 0;
}