#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
    string s;
    cin>>s;
    int ans=INT_MIN;
    int i=0,j=0;
    int length=s.length();
    unordered_map<char,int> m;
    while(j<length){
        m[s[j]]++;
        if(m.size()<j-i+1){
            while(m.size()<j-i+1){
                m[s[i]]--;
                if(m[s[i]]==0)
                    m.erase(s[i]);
                i++;
            }
            j++;
        }
        else if(m.size()==j-i+1){
            ans=max(ans,j-i+1);
            j++;
        }
    }
    cout<<ans;
    return 0;
}