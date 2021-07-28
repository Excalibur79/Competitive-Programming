#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int minIndex=1;
    int minValue=INT_MAX;
    int sum=0;
    for(int i=1;i<=k;i++)
        sum=sum+arr[i];
    
    if(sum<minValue){
        minValue=sum;
        minIndex=1;
    }

    for(int i=k+1;i<=n;i++){
        sum=sum-arr[i-k]+arr[i];
        if(sum<minValue){
            minValue=sum;
            minIndex=i-k+1;
        }
    }
    cout<<minIndex<<endl;
    
    return 0;
}