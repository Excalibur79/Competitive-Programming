#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
      string s;
    int k;
    cin>>s>>k;
    int i=0,j=0,count=0,ans=INT_MIN,x,y;
    unordered_map<char,int> m;
    for(auto character:s)
        m[character]=0;
    while(j<s.length()){  
         m[s[j]]++;
         if(m[s[j]]==k)
            count+=k;
        else if(count){
            while(m[s[j]]>k){
                m[s[i]]--;
                if(m[s[i]]==k-1)
                    count-=k;
                i++;
            }
        }
       
       if(count==j-i+1){
           ans=max(ans,count);
           x=i;
           y=j;
       }
       j++;
     
       
    }
    cout<<(ans!=INT_MIN?s.substr(x,y-x+1):"")<<endl;
    return 0;
}