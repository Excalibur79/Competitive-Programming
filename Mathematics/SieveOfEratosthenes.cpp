#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;
int main(){
    int n = 50;
    vector<bool> arr(n+1,true);
    for(int i =2;i<=sqrt(n);i++){
        if(arr[i]){
            for(int j=i*i;j<=n;j=j+i)
                arr[j] = false;
        }
    }
    for(int i=0;i<=n;i++){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto value : arr)
        cout<<value<<" ";
    return 0;
}