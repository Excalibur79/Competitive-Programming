#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;

bool arr[10000001];int ans[10000001];

void sieve(){
    arr[0]=arr[1]=true;
    for(int i=2;i<=10000000;i++){
        if(!arr[i]){
            ans[i]++;
            for(int j=i+i;j<=10000000;j+=i){
                arr[j] = true;
                ans[j]++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p;
    cin>>p;
    int t;
    cin>>t;
    sieve();
    while(t--){
        ll n;
        cin>>n;
        cout<<( ans[n]>=p?"YES":"NO" )<<endl;
        cout<<ans[n]<<endl;
    }
    return 0;
}