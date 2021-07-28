#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;
int main(){
    vector<int> customers = {4,10,10};
    vector<int> grumpy = {1,1,0};
    int minutes = 3;  
    int sum = 0;
    int i,j;
    for(i=0;i<customers.size();i++){
        if(grumpy[i]==0)
            sum+=customers[i];   
    }   
    int maxValue = INT_MIN;
    for(i=0;i<minutes;i++){
        if(grumpy[i]==1)
            sum+=customers[i];           
    }  
    maxValue=max(sum,maxValue);   
    for(i=minutes;i<customers.size();i++){
       if(grumpy[i]==1)
        sum+=customers[i];
       if(grumpy[i-minutes]==1)
        sum-=customers[i-minutes];
       maxValue=max(maxValue,sum);
    }
  
   cout<<maxValue<<endl;

    return 0;
}