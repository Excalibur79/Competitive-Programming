#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
    int n,sum=0,mysum=0,i=0;
    cin>>n;
    vector<int> vect;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        vect.push_back(x);
        sum=sum+x;
    }
    sort(vect.begin(),vect.end(),greater<int>());
    for(i=0;i<n;i++){
        mysum=mysum+vect[i];
        if(mysum>sum-mysum){
            break;
        }
    }
    cout<<i+1;
    return 0;
}