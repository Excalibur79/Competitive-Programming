#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            arr.push_back(x);
        }
        unordered_map<int,int> m;
        int count = 0;
        for(int i=0;i<n;i++){
            m[arr[i]] = arr[i]-1;
        }
        
        for(int i =0;i<n;i++){
            if(m[arr[i]]>0){
                count++;
                m[arr[i]]--;
            }
        }
        cout<<count<<endl;
    }
}