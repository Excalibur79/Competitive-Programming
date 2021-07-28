#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;

void printMatrix(vector<vector<long long>> &v){
    for(auto x:v){
        for(auto value:x)
            cout<<value<<" ";
        cout<<endl;
    }
}

int main(){
   long long n,m,u,q;
    cin>>n>>m>>u>>q;  
    vector<vector<long long>> matrix(n,vector<long long>(m));
    vector<vector<long long>> bumpMatrix(n,vector<long long>(m));
    vector<vector<long long>> prefixMatrix(n,vector<long long>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }

    while(u--){
       long long k,r1,c1,r2,c2;
        cin>>k>>r1>>c1>>r2>>c2;
        bumpMatrix[r1][c1]+=k;
        if(c2+1<m)
            bumpMatrix[r1][c2+1]-=k;
        if(r2+1<n)
            bumpMatrix[r2+1][c1]-=k;
        if(r2+1<n && c2+1<m)
            bumpMatrix[r2+1][c2+1]+=k;
    }
    //=====bumpMatrix Evaluation=====
    //row prefix evaluation
    for(int i=0;i<n;i++){
       long long sum=0;
        for(int j=0;j<m;j++){
            sum=sum+bumpMatrix[i][j];
            bumpMatrix[i][j]=sum;
        }
    }
    //column prefix evaluation
    for(int j=0;j<m;j++){
        long long sum=0;
        for(int i=0;i<n;i++){
            sum=sum+bumpMatrix[i][j];
            bumpMatrix[i][j]=sum;
        }
    }  
    
    //==================================

    //updating bumMatrix to real Value
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            bumpMatrix[i][j]+=matrix[i][j];
    }
   
    //================================

    //calculating 2d prefix sum in prefixmatrix
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            long long a=0,b=0,c=0,d=0;
            if(i-1>=0)
                a=prefixMatrix[i-1][j];
            if(j-1>=0)
                b=prefixMatrix[i][j-1];
            if(i-1>=0 && j-1>=0)
                c=prefixMatrix[i-1][j-1];
             prefixMatrix[i][j]=bumpMatrix[i][j] +  a+ b -  c ;
        }
    }
     //printMatrix(prefixMatrix);    
    //=========================================

    //Taking Queries
    while(q--){
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
       long long ans;
        long long a=0,b=0,c=0;
        if(r1-1>=0)
            a=prefixMatrix[r1-1][c1];
        if(c1-1>=0)
            b=prefixMatrix[r2][c1-1];
        if(r1-1 && c1-1>=0)
            c=prefixMatrix[r1-1][c1-1];
        ans=prefixMatrix[r2][c2] - a - b + c;
        cout<<ans<<endl;
    }
    //==============

    return 0;
}