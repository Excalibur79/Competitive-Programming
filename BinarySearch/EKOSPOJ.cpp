#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;

const int N =1e6+10;
int n;
long long m;
long long trees[N];

bool isWoodSufficient(int h){
    long long wood = 0;
    for(int i =0;i<n;i++){
        if(trees[i]>=h)
            wood+=trees[i] - h;
    }
    return wood>=m;
}   

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>trees[i];
    }
    long long l=0,h=1e9,mid,res;
    //T T T T F F F F F 
    while(l<=h){
        mid = (l+h)/2;
        if(isWoodSufficient(mid)){
            res = mid;
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    cout<<res<<endl;
}