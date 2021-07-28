#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,q;
        cin>>n>>q;
        vector<ll> arr(n+1);
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            arr[i] = x;
        }
        vector<ll> forwardGCD(n+1);
        vector<ll> backwardGCD(n+1);
        ll gcdF=0;
        ll gcdB=0;
        for(int i =1;i<=n;i++){
            gcdF = gcd(gcdF,arr[i]);           
            forwardGCD[i] = gcdF;
        }
        for(int i = n;i>0;i--){
            gcdB = gcd(gcdB,arr[i]);
            backwardGCD[i] = gcdB;
        }      
        while(q--){
            ll l,r;
            cin>>l>>r;
            ll forwardValue = l-1>=1?forwardGCD[l-1]:0;
            ll backwardValue = r+1<=n?backwardGCD[r+1]:0;
            //cout<<forwardValue<<"    "<<backwardValue<<" "<<endl;
            ll value = __gcd( forwardValue, backwardValue );
            cout<<value<<endl;
        }

    }
   
    return 0;
}