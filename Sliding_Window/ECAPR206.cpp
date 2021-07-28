#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#include<cmath>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            arr.push_back(x);
        }
        for(int i=0;i<k-1;i++)
            arr.push_back(arr[i]);
       
        int maxValue=0;
        int sum=0;
        for(int i=0;i<k;i++)
            sum=sum+arr[i];
        maxValue=max(maxValue,sum);
        for(int i=k;i<arr.size();i++){
            sum=sum-arr[i-k]+arr[i];          
            maxValue=max(sum,maxValue);
        }
        cout<<maxValue<<endl;
    }
}