#include <bits/stdc++.h>
#define ll long long
using namespace std;

char graph[1000][1000];
bool visited[1000][1000];
int n,m;


bool isValid(int i,int j){
    if(i<0 || i >n-1 || j<0 || j>m-1)
        return false;
    if(visited[i][j]==true || graph[i][j]=='#')
        return false;
    return true;
    
}


void dfs(int i,int j){
    visited[i][j] = true;
    if(isValid(i-1,j)){
        dfs(i-1,j);
    }
    if(isValid(i+1,j)){
        dfs(i+1,j);
    }
    if(isValid(i,j-1)){
        dfs(i,j-1);
    }
    if(isValid(i,j+1)){
        dfs(i,j+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>graph[i][j];
        }
    }
    int counter=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && graph[i][j]=='.'){               
                counter++;
                dfs(i,j);
            }
        }
    }    
    cout<<counter<<endl;
    return 0;
}