#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    int t;
    cin>>t;
    int initialT = t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int g = gcd(a,b);
        cout<<"Case "<<initialT-t<<": "<<(c%g==0?"Yes":"No")<<endl;
    }
    return 0;
}