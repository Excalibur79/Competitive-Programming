#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
    string t,s;
    cin>>s>>t;
    int slength=s.length();
    int tlength=t.length();
    unordered_map<char,int> m;
    for(auto character:t)
        m[character]++;
    int ans=INT_MAX;
    int i=0,j=0,x=0,y=0,count=m.size();
    while(j<slength){
        if(count>0){
            if(m.find(s[j])!=m.end()){
                m[s[j]]--;
                if(m[s[j]]==0)
                    count--;
            }
           
        }        
         if(count==0){
            while(count==0){  
                 if(j-i+1<ans){
                    ans=j-i+1;
                    x=i;
                    y=j;
                }              
                if(m.find(s[i])!=m.end()){
                    m[s[i]]++;
                    if(m[s[i]]==1)
                        count++;
                }
                i++;               
            }    
                   
        }
        j++;      
    }
    cout<<(ans!=INT_MIN?s.substr(x,y-x+1):"");
}