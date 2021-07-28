#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
   
    int n,q;
    cin>>n>>q;   
    vector<long long>vect(n+1);   
    vector<long long>sumVect(n+1);  
    while(q--){
        long long l,r;
        cin>>l>>r;
        vect[l]++;
        if(r+1<=n){
            vect[r+1]--;
            sumVect[r+1]=sumVect[r+1] - (r-l+1);
        }
    }
    
  
    //doing first prefix on vect===
    long long sum=0;
    for(int i=1;i<=n;i++){
        sum=sum+vect[i];
        vect[i]=sum;
    }
   
    //=============================
    //doing prefix sum of sumVect ( here we ad vect[i] to elements of sumVect prefix array hence this is the second prefix sum )
    sum=0;
    for(int i=1;i<=n;i++){
        sum=sum+sumVect[i]+vect[i];
        sumVect[i]=sum;
    }
    for(auto value:sumVect)
        cout<<value<<" ";
    cout<<endl;
    //===========================================================================================================================
    return 0;
}