#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        ll g = __gcd(a,b);
        if(g!=1)
            cout<<0<<endl;
        else if((a%2==0 && b%2!=0) || (b%2==0 && a%2!=0))
            cout<<1<<endl;       
        else
            cout<<2<<endl;
    }
    return 0;
}