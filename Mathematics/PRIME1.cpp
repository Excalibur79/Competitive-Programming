#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;

bool isPrime(ll number){
    for(ll i=2;i<=sqrt(number);i++){
        if(number%i==0)
            return false;
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>m>>n;        
        if(m==1)
            m++;
        for(ll i=m;i<=n;i++){
            if(isPrime(i))
                cout<<i<<endl;
        }
    }
    return 0;
}