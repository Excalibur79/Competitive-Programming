#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll Pow(ll n,ll x){
    ll res = 1;
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
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x;
    cin>>x;
    ll sum=0;
    while(x>0){
        sum+=Pow(2,x);
        x--;
    }
    cout<<sum<<endl;
    return 0;
}