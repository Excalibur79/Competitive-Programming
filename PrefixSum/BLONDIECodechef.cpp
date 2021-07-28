#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> vect;
        vector<long long>sumVect;
        long long sum=0;
        int visited=0;
        for(int i=0;i<n;i++){
            long long x;
            cin>>x;
            if(x!=-1){
                vect.push_back(x);
                sum=sum+x;
                sumVect.push_back(sum);
            }   
            else{
                long long data = (long long)floor((sumVect[i-1]*1.0)/(visited*1.0));
                vect.push_back(data);
                sum=sum+data;
                sumVect.push_back(sum);
            }
            visited++;
        }

        for(auto value:vect)
            cout<<value<<" ";
        cout<<endl;
    }
    return 0;
}