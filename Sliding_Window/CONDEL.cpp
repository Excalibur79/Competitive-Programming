#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr;
        queue<int> q;
        int totalSum=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            arr.push_back(x);
            totalSum+=x;
        }
        int sum=0;
        int cost=0;      
      
        while(totalSum>0){
          
            vector<int> pending;
            int sum=0;
           for(int i=0;i<k;i++){
               sum=sum+arr[i];
               if(arr[i]==1)
                q.push(i);
           }
           if(!q.empty()){
               cout<<q.front()<<endl;
               pending.push_back(q.front());
               cost+=sum;
               totalSum--;
               q.pop();
           }
           for(int i=k;i<n;i++){
               sum=sum-arr[i-k]+arr[i];
               if(arr[i]==1)
                q.push(i);
               if(!q.empty()){
                    cout<<q.front()<<endl;
                   pending.push_back(q.front());
                   cost+=sum;
                   totalSum--;
                   q.pop();
               }
           }
           for(auto value:pending){
               arr[value]=0;
           }
           for(auto value:arr)
            cout<<value<<" ";
          
        }
        // cout<<cost;
    }
        
    
    return 0;
}