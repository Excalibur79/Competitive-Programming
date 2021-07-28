#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vect;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        vect.push_back(x);
    }
    vector<int>sumVect;
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+vect[i];
        sumVect.push_back(sum);
    }
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        if(x==0)
            cout<<sumVect[y]<<endl;
        else
            cout<<sumVect[y]-sumVect[x-1]<<endl;
    }
}