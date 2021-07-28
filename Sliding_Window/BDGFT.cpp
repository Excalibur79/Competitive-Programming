#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#include<cmath>
using namespace std;
int main(){
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;       
        ll windowZeroes=0;
        ll windowOnes=0;
        ll beauty=0;
        ll n=s.length();
        for(ll size=1;(size*size+size)<=n;size++){
             windowZeroes=0;
             windowOnes=0;
            ll range=size*size+size;
            for(ll i=0;i<range;i++){
                if(s[i]=='0')
                    windowZeroes++;
                else
                    windowOnes++;
            }
            if(windowZeroes==windowOnes*windowOnes)               
                beauty++;
            
            
            for(ll i=range;i<n;i++){
                if(s[i-range]=='0')
                    windowZeroes--;
                else
                    windowOnes--;
                if(s[i]=='0')
                    windowZeroes++;
                else
                    windowOnes++;
                if(windowZeroes==windowOnes*windowOnes)                   
                    beauty++;
                 
            }
      
        }
        cout<<beauty<<endl;
    }
    return 0;
}