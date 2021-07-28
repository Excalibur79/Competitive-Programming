#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;

//To find x,y of equation ax + by = gcd(a,b) where a and b are given

int extendedEuclidean(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    int d = extendedEuclidean(b,a%b,x1,y1);
    x = y1;
    y = x1 - y1*(a/b);
    return d;
}

int main(){
    int a,b;
    cin>>a>>b;
    int x,y;
    extendedEuclidean(a,b,x,y);
    cout<<"x :"<<x<<" y : "<<y<<endl;
}