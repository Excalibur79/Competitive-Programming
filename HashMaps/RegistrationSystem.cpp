#include<iostream>
#include <bits/stdc++.h>
#include <string>
#define ll long long
using namespace std;
int main(){
    unordered_map<string,int> m;
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        if(m.find(s)!=m.end()){
            cout<<s<<m[s]<<endl;
            m[s]++;
        }
        else{
            m[s]=1;
            cout<<"OK"<<endl;
        }
    }
    return 0;
}