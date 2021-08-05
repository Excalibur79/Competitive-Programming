#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pair<ll,int>> arr;
    vector<pair<ll,int>> copyArr;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        arr.push_back({x,i});
        copyArr.push_back({x,i});
    }
    sort(copyArr.begin(),copyArr.end());   
    set<pair<int,int>> ans;
    for(int i=0;i<n;i++){
        if(arr[i].second !=copyArr[i].second){           
            ans.insert({min(arr[i].second,copyArr[i].second),max(arr[i].second,copyArr[i].second)});
        }
    }
    cout<<ans.size()<<endl;
    for(auto value:ans)
        cout<<value.first<<" "<<value.second<<endl;
    return 0;
}