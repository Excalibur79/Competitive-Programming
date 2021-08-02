#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;

bool isPrime(int n){
    if(n==1) return false;
    double s = sqrt(n);
    for(int i=2;i<=s;i++){
        if(n%i==0)
            return false;
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<(isPrime(n)?"yes":"no")<<endl;

    }
    return 0;
}