#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
    int a1,b1,a2,b2;
    cin>>a1>>b1>>a2>>b2;
    unordered_set<int> s;
    int side;
    s.insert(a1);
    s.insert(a2);
    s.insert(b1);
    s.insert(b2);
    if(s.size()==2){
        if(a1==a2){
            side=b2-b1;
            cout<<a1+side<<" "<<b1<<" "<<a2+side<<" "<<b2;
        }
        else if(b1==b2){
            side=a2-a1;
            cout<<a1<<" "<<b1+side<<" "<<a2<<" "<<b2+side;
        }
        else{
            side=b2-b1;
            cout<<a1+side<<" "<<b1<<" "<<a2-side<<" "<<b2;
           
        }
    }
    else{
        cout<<-1;
    }
    return 0;
}