#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s;    
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cin>>s;
    bool possible = true;
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                if(s[j]=='1'){
                    int temp = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = temp;
                }
                else{
                    possible = false;
                    break;
                }
            }
        }
        if(!possible)
            break;
    }
    cout<<(possible?"YES":"NO")<<endl;

    return 0;
}