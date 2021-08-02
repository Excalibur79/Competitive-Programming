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
        int n;
        cin>>n;
        vector<ll> arr;
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            arr.push_back(x);
        }
        if(n>1){
            int i=0,j=1,ans = 2;
            ll divisor = arr[1] - arr[0];
            if(divisor%2==0)
                divisor = 2;
            while(j<n-1){
                ll testDivisor = arr[j+1] - arr[j];
                if(testDivisor%2==0)
                    testDivisor=2;
                if(testDivisor==divisor)
                {
                    j++;
                    ans = max(ans,j-i+1);
                }
                else{
                    i=j;
                    j++;
                    divisor = arr[j] - arr[i];
                    if(divisor%2==0)
                        divisor=2;
                }                       

            }
            cout<<ans<<endl;
        }
        else
            cout<<1<<endl;

        
    }
    return 0;
}