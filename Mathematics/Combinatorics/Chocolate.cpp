#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr;
    int numberOfNuts=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
        if(x==1)
            numberOfNuts++;
    }    
    if(numberOfNuts == 0)
        cout<<0<<endl;
    else if(numberOfNuts==1)
        cout<<1<<endl;
    else{
        stack<ll> st; //stores the indexes of 1
        ll res = 1;
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                if(st.empty()){
                    st.push(i);
                }
                else{
                    int firstIndex = st.top();
                    st.pop();
                    int secondIndex = i;
                    ll possibilities = secondIndex - firstIndex ;
                    res*=possibilities;
                    st.push(i);
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}