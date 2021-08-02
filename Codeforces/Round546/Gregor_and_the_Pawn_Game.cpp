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
        vector<int> enemyPawns ;
        vector<int> myPawns;
        string s1,s2;
        cin>>s1>>s2;
        for(int i=0;i<n;i++){            
            enemyPawns.push_back((int)s1[i]-48);
        }
        for(int i=0;i<n;i++){           
            int value = (int)s2[i]-48==0?0:(int)s2[i]-48+1;
            myPawns.push_back(value);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(myPawns[i]==2){
                if(enemyPawns[i]==0){
                 enemyPawns[i] = 2;
                 ans++;
                }
                else{
                 if(i==0){
                     if(enemyPawns[i+1]==1){
                         enemyPawns[i+1]=2;
                         ans++;
                     }
                }
                if(i==n-1){
                    if(enemyPawns[i-1]==1){
                         enemyPawns[i-1]=2;
                         ans++;
                    }
                    }
                    else{
                        if(enemyPawns[i-1]==1){
                            enemyPawns[i-1]=2;
                            ans++;
                        }
                        else if(enemyPawns[i+1]==1){
                            enemyPawns[i+1]=2;
                            ans++;
                        }
                    }
                }   
            }            
           
        }
        cout<<ans<<endl;
        
    }
    return 0;
}