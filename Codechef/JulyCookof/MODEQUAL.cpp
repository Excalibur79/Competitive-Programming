#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#include <typeinfo>
#define ll long long

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll> arr;
        map<ll,int> m;
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            arr.push_back(x);
            m[x]++;
        }
        auto minimumValue = m.begin()->first;
        auto minimumValueCount = m.begin()->second;
        ll isDivisbleByMinimum = true;
        for(int i=0;i<n;i++){           
            if(ceil(arr[i]*1.0/2.0)-1<minimumValue && arr[i]!=minimumValue ){
                isDivisbleByMinimum = false;
                break;
            }
        }
      
        if(isDivisbleByMinimum)
            cout<<n-minimumValueCount<<endl;
        else
            cout<<n<<endl;
      
       
    }
    return 0;
}