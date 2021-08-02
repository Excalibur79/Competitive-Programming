#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll P;
        cin>>P;
        ll a = P-1;
        ll b = a/2;
        cout<<b<<" "<<a<<endl;
    }
    return 0;
}