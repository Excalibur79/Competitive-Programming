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
        ll n;
        cin>>n;       
        ll res;
        if(n<=6)
            ans =15;        
        else{
            if(n%2!=0)n++;
            ans = (n*5)/2;
        }
        cout<<ans<<endl;

    }
    return 0;
}