#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;

int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        ll g = __gcd(a,b);
        if(g==1){
            cout<<((a*b)-a-b)+1<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}