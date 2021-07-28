#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;
int main(){
    ll fact =1;
    int n=21;
    for(int i=1;i<=n;i++){
        fact = fact * i;
    }
    cout<<fact;
    return 0;
}