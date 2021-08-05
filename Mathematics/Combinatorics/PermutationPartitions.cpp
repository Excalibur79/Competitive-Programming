#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    ll sum = 0;
    for(ll i=n;i>n-k;i--){
        sum+=i;
    }
    ll res = 1;
    stack<int> st;
    for(int i=0;i<n;i++){
        if(arr[i]>n-k){
           if(!st.empty()){
               res = (res *( i - st.top()))%998244353;
              // cout<<res<<endl;
               st.pop();
           }    
           st.push(i);
        }
    }
    cout<<sum<<" "<<res<<endl;
    return 0;
}