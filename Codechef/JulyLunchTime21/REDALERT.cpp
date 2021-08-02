#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,d,h;
        cin>>n>>d>>h;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            arr.push_back(x);
        }
        int maxWater = 0;
        bool redalert = false;
        for(int i=0;i<n;i++){
            if(arr[i]!=0)
                maxWater+=arr[i];
            if(maxWater>h){
                redalert = true;
                break;
            }
            if(arr[i]==0){
                maxWater = max(0,maxWater - d);
            }
        }
        if(redalert)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}