#include<iostream>
#include <bits/stdc++.h>
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
    int sum=0,i=0;
    while(sum<=k){
        sum=sum+arr[i];
        i++;
    }
    //to be  completed!
    return 0;
}