#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vect;
    stack<int> st;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        vect.push_back(x);
    }
    st.push(0);
    vector<int> nge(n,-1);
    for(int i=1;i<n;i++){
        while(!st.empty() && vect[i]>vect[st.top()]){
            nge[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    for(auto value:nge)
        cout<<(value==-1?-1:vect[value])<<" ";

    return 0;

}   