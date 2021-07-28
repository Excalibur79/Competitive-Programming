#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;

void reviveWarriors(vector<long long> &warriors,vector<long long> initialWarriors){
    for(int i=0;i<warriors.size();i++){
        warriors[i]=initialWarriors[i];
    }
}

int main(){
    int n,q;
    cin>>n>>q;
    vector<long long> warriors;
    vector<long long> initialWarriors;
    vector<long long> arrows;
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        warriors.push_back(x);
        initialWarriors.push_back(x);
    }
    for(int i=0;i<q;i++){
        long long x;
        cin>>x;
        arrows.push_back(x);
    }
    int i=0;
    long long sum=0;
    // for(int j=0;j<q;j++){
    //     while(sum<arrows[j] && warriors[i]<=arrows[j]){
    //         if(i>=warriors.size()){
    //             i=0;
    //             break;
    //         }
    //         else{               
    //             sum+=warriors[i];
    //             i++;            
    //         }
    //     }
    //     while(warriors[i]>arrows[j]){

    //     }
    //     cout<<warriors.size()-i<<endl;
    //     sum=0;           
    // }
    int j=0;i=0;
    int lastIndex=warriors.size()-1;
    while(j<q){
        if(warriors[i]<arrows[j]){
            arrows[j] = arrows[j] - warriors[i]; 
            if(arrows[j]==0)
                j++;          
            i++;
            if(i>=warriors.size()){
                i=0;
                reviveWarriors(warriors,initialWarriors);
                cout<<(lastIndex - i +1)<<endl;
                j++;

            }
        }
        else if(warriors[i]==arrows[j]){
           
            i++;
            j++;
            if(i<=lastIndex)
             cout<<(lastIndex - i +1)<<endl;
            if(i>=warriors.size()){
                i=0;
                reviveWarriors(warriors,initialWarriors);
                cout<<(lastIndex - i +1)<<endl;
               
            }
        }
        else if(warriors[i]>arrows[j]){
            warriors[i] = warriors[i] - arrows[j];
            cout<<(lastIndex - i +1)<<endl;
            j++;
        }

    }
    return 0;
}