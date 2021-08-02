#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;
//in sqrt time
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 2358811;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            int count = 0;
            while(n%i==0){
                count++;
                n=n/i;
            }
            cout<<i<<"^"<<count<<endl;
        }        
    }
    if(n>1)
        cout<<n<<"^"<<1<<endl;
    return 0;
}