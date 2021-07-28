#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;

bool isValid(ll sum,ll n,vector<ll> &prefixArr){
   
    //cout<<"sum :"<<sum<<" n :"<<n<<" ans:"<<(s<=sum)<<endl;
    return prefixArr[n]<=sum;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> prefixArr(n+1);
        for(ll i=1;i<=n;i++){
            prefixArr[i] = prefixArr[i-1] + i;
        }
        ll l=1,h=n,mid,res=-1;
        while(l<=h){
            mid=(l+h)/2;
            if(isValid(n,mid,prefixArr)){
                res = mid;
                l=mid+1;
            }
            else    
                h=mid-1;
        }
        cout<<res<<endl;
    }
	return 0;
}
