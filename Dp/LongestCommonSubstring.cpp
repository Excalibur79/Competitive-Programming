#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int recur(string x,string y,int n,int m,int count){
    if(n==0||m==0)
        return count;
    if(x[n-1]==y[m-1]){
        count = recur(x,y,n-1,m-1,count+1);
    }
    count = max(count,max( recur(x,y,n-1,m,0) , recur(x,y,n,m-1,0) ));
    return count;
}

int main(){
    string n,m;
    cin>>n>>m;
    int ans = recur(n,m,n.length(),m.length(),0);
    cout<<ans;
}