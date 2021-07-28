#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> vect;
    queue<int> q;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        vect.push_back(x);
    }
    int i=0,j=0;
    
    for(int i=0;i<k;i++){
        if(vect[i]<0)
            q.push(vect[i]);        
    }

    if(!q.empty())
        cout<<q.front()<<" ";
    else
        cout<<0<<" ";
    
    for(int i=k;i<n;i++){
        if(vect[i-k]==q.front())
            q.pop();
        if(vect[i]<0)
            q.push(vect[i]);
        if(!q.empty())
            cout<<q.front()<<" ";
        else
            cout<<0<<" ";
    }
   
    return 0;
}