#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;
 bool arr[90000001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin>>k;

    //preprocessing with sieve
    //vector<bool> arr(90000000,false);
   
    for(int i=2;i<=sqrt(90000000);i++){
        if(!arr[i]){
            for(int j = i*i;j<=90000000;j+=i)
                arr[j] = true;
        }
    }
    vector<int> preprocessedPrimes;
    for(int i=2;i<=90000000;i++){
        if(!arr[i])
            preprocessedPrimes.push_back(i);
    }
    //========================

    while(k--){
        int x;
        cin>>x;
        cout<<preprocessedPrimes[x-1]<<endl;
    }
    return 0;
}