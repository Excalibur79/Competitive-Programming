#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    if(n%2==0){
        ll mid = n/2;
        cout<<(mid/2 - (mid%2==0) )<<endl;
    }
    else{
        cout<<0<<endl;
    }
    return 0;
}