#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;

bool isSeriesPossible(vector<ll> &arr , int m){
    int n = arr.size();
    vector<bool> Left(n);
    vector<bool> Right(n);
    //processing left=================
    int k = 0;
    for(int i =0;i<n;i++){
        if(arr[i]>=k+1){
            k++;
            if(k==m){
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
            if(k==m){
                Right[i]=true;
                k--;
            }
        }
        else
            k=arr[i];
    }
    //===============================
    bool found = false;
    for(int i=0;i<n;i++){
        if(Left[i] && Right[i]){
            found = true;
            break;
        }
    }
    return found;

}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll> arr;
         for(int i=0;i<n;i++){
             ll x;
             cin>>x;
             arr.push_back(x);
         }
         ll sum=0;
         for(auto value:arr)
            sum+=value;

         ll l=0,h=n,mid,res = INT_MAX;
         while(l<=h){
             mid = (l+h)/2;
             if(isSeriesPossible(arr,mid)){
                res = sum-(mid*mid);
                 l = mid+1;
             }
             else
                h = mid -1;
         }
         cout<<res<<endl;
    }
    return 0;
}