#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll m=1000;

// vector<vector<bool>(m+1)> graph(m+1);
// vector<vector<bool>(m+1)> visited(m+1);

bool graph[m+1][m+1];
bool visited[m+1][m+1];
map<pair<ll,ll>,pair<ll,ll>> hashMap;
ll x,y,p,q;
bool pathPresent = false;
ll pathLength = 0;

bool isValid(ll i,ll j){
    if(i<1 || i >m || j<1 || j>m)
        return false;
    if(visited[i][j]==true || graph[i][j]==false)
        return false;
    return true;    
};

void calculatePathLength(){
    ll i = p,j=q;
    while(i!=-1 && j!=-1){
        pathLength++;
        i = hashMap[{i,j}].first;
        j = hashMap[{i,j}].second;
    }
};

void dfs(ll i,ll j){
    visited[i][j] = true;
    if(i==p && j==q){
        pathPresent = true;
        calculatePathLength();
    }
    if(isValid(i-1,j)){
        hashMap[{i-1,j}] = {i,j};
        dfs(i-1,j);
    }
    if(isValid(i+1,j)){
        hashMap[{i+1,j}] = {i,j};
        dfs(i+1,j);
    }
    if(isValid(i,j-1)){
        hashMap[{i,j-1}] = {i,j};
        dfs(i,j-1);
    }
    if(isValid(i,j+1)){
        hashMap[{i,j+1}] = {i,j};
        dfs(i,j+1);
    }
};

int main()
{
   
    cin>>x>>y>>p>>q;
    ll n;
    cin>>n;
    while (n--){
       ll r,a,b;
       cin>>r>>a>>b;
       for(ll i=a;i<=b;i++){
           graph[r][i] = true;
       }
    }
    hashMap[{x,y}] = {-1,-1};
    dfs(x,y);
    if(pathPresent){
        cout<<pathLength<<endl;
    }
    else
        cout<<-1<<endl;
    return 0;
}