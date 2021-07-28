#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> vect(k+1,0);
    vector<int> sumVect;
    while(n--){
        int streetLight,spread;
        cin>>streetLight>>spread;
        int x=streetLight-spread;
        int y=streetLight+spread;
        if(x>=0)
            vect[x]+=1;
        else
            vect[0]+=1;
        if(y+1<=k)
            vect[y+1]-=1;
    }
    int sum=0;   
    for(auto value:vect){
        sum+=value;
        sumVect.push_back(sum);
    }  
    int maxValue=0;
    int counter=0;
    for(auto value:sumVect){
        if(value!=1)
            counter++;
        else          
            counter=0;        
         maxValue=max(maxValue,counter);
    }
    cout<<maxValue<<endl;
    return 0;
    
}