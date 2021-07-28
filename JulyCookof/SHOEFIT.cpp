#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        bool leftShoePresent=false;
        bool rightShoePresent=false;
        if(a==0 || b==0 ||c==0)
            leftShoePresent=true;
        if(a==1||b==1||c==1)
            rightShoePresent = true;
        cout<<(leftShoePresent && rightShoePresent)<<endl;
    }
    return 0;
}