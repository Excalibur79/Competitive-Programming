#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool comparator(int a,int b){
    return a>b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a;
        vector<int> b;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a.push_back(x);
        }
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            b.push_back(x);
        }
        int sum=0;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end(),comparator);
        int j=0;
        for(int i =0;i<n;i++){
            if(k){
                if(a[i]>=b[j]){
                    sum+=a[i];
                }
                else{
                    sum+=b[j];
                    j++;
                    k--;
                }                
            }
            else
                sum+=a[i];
          
        }
        cout<<sum<<endl;
    }
    return 0;
}