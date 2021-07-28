#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;
#define ll long long

int main(){
    vector<int> arr = {0,0,0,0,0,0,0};
    vector<int> ps(arr.size()+1);
    vector<int> ps2(arr.size()+1);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        ps[l]++;
        if(r+1<arr.size()){
            ps[r+1]--;
            ps2[r+1]-=(r-l+1);

        }
        
        for(int i=1;i<=arr.size();i++){
            ps[i] = ps[i] + ps[i-1];
        }
         for(int i=1;i<=arr.size();i++){
            ps[i] = ps[i] + ps[i-1] + ps2[i];
        }
        for(auto value:ps)
            cout<<value<<" ";
        cout<<endl;

    }
}