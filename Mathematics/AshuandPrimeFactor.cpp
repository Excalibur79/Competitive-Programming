#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;

bool arr[1000001];ll ans[1000001];

void sieve(){
    for(ll i=2;i<=sqrt(1000000);i++){
        if(arr[i]==false){//prime number
            ll count = 1;
            for(ll j=i*i;j<=1000000;j+=i){                
                if(arr[j]==false)
                    count++;
                arr[j] = true;
            }
            ans[i] = count;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int t;
    cin>>t;
    while(t--){
        ll x;
        cin>>x;
        cout<<ans[x]<<endl;
    }
    return 0;
}