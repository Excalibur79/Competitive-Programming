#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vect(n,0);
    int q,value;
    cin>>q>>value;
    vector<int> sumVect;
    while(q--){
        int l,r;
        cin>>l>>r;
        vect[l]+=value;
        if(r+1<n)
            vect[r+1]-=value;
    }
    int sum=0;
    for(auto val:vect){
        sum=sum+val;
        sumVect.push_back(sum);
    }
    for(auto val:sumVect)
        cout<<val<<" ";

    return 0;
}