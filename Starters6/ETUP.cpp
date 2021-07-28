#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;
#define ll long long

ll binomialCoeff(ll n, ll k) {
    if (n < k) return 0;
    if (n == k) return 1;
    ll res = 1;
    if (k > n - k) k = n - k;
    for (ll i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            arr.push_back(x);
        }
        int sum=0;
        vector<int> prefixArray(n+1);
        for(int i=1;i<=n;i++){
           prefixArray[i] = prefixArray[i-1] + (arr[i-1]%2==0);
        }
        while(q--){
            int l,r;
            cin>>l>>r;
            ll even =  (l==0?prefixArray[r]:prefixArray[r] - prefixArray[l-1]);
            ll odd = (r-l+1) - even;
            ll ans = binomialCoeff(even,3) + binomialCoeff(odd,2)*even;
            cout<<ans<<endl;
        }
    }
}