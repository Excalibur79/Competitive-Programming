#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;

int main(){
    //Find All minimum values of all windows of size k
    int t;
    cin>>t;
    while(t--){
        vector<int> arr = {601,35,45,304,449,452,190};
        int k =2+1;
        int n = arr.size();
        vector<int> dp(n);
        list<int> l;
        for(int i =0;i<k;i++){
            dp[i] = arr[i];
            while(!l.empty() && arr[l.front()]>arr[i])
                l.pop_front();
            l.push_back(i);
        }
        if(!l.empty()){
            cout<<arr[l.front()]<<" ";
        }
        for(int i=k;i<n;i++){
            if(i-k == l.front()){
                l.pop_front();
            }
            dp[i] = arr[i] + arr[l.front()];
            while(!l.empty() && arr[l.front()]>arr[i])
                l.pop_front();
            l.push_back(i);
            if(!l.empty())
                cout<<arr[l.front()]<<" ";
        }
        cout<<endl;
        for(auto value:dp)
            cout<<value<<" ";
        cout<<endl;
    }
    
    return 0;
}