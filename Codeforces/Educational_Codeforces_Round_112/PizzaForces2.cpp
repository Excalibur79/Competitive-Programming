#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll time = 15;      
        ll slicesPending = n%6;
        if(n<=6)
            time = 15;
        else{
            time = n/6 *15;
            if(slicesPending == 1 || slicesPending == 2 )
                time = time - 15 +20;
            else if(slicesPending == 3 || slicesPending == 4 )
                time = time - 15 +25;
            else if(slicesPending ==5)
                time +=15;

        }
        cout<<time<<endl;

    }
    return 0;
}