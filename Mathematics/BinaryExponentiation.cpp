#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=2;
    int x = 13;
    int res = 1;
    while(x){
        if(x%2!=0){//means odd
            res = res * n;
            x--;
        }
        else{
            n=n*n;
            x=x/2;
        }
    }
    cout<<res<<endl;
    return 0;
}