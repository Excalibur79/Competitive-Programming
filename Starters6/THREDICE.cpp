#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        int sum=x+y;
        int required=6-sum;
        required = max(required,0);
        if(required==0)
            cout<<0<<endl;
        else
            cout<<required/6.0<<endl;
    }
	return 0;
}
