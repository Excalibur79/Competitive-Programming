#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
    string s;
    int k;
    cin>>s;
    cin>>k;
    int length=s.length();
    unordered_map<char,int> m;
    int j=0,i=0;
    int ans=INT_MIN;
    while(j<length){
        m[s[j]]++; 
        if(m.size()<k)
            j++;
        else if(m.size()>k){
            while(m.size()>k){
                m[s[i]]--;
                if(m[s[i]]==0)
                    m.erase(s[i]);
                i++;
            }
            j++;
        }
        else if(m.size()==k){
           // cout<<j-i+1<<endl;
            ans=max(ans,j-i+1);
             j++;
        }
       
    }
  
    cout<<ans;
}