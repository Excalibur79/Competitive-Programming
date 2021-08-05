#include <bits/stdc++.h>
#define ll long long
using namespace std;

char graph[1000][1000];
bool visited[1000][1000];
int n,m;
bool pathExist = false;

bool isValid(int i,int j){
    if(i<0 || i >n-1 || j<0 || j>m-1)
        return false;
    if(visited[i][j]==true || graph[i][j]=='#')
        return false;
    return true;
    
}


void dfs(int i,int j){
    visited[i][j] = true;
    if(graph[i][j]=='B')
        pathExist = true;
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
    int startI,startJ;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           char c;
           cin>>c;
           graph[i][j] = c;
           if(c == 'A'){
               startI = i;
               startJ = j;
           }        

        }
    }  
    dfs(startI,startJ);
    cout<<(pathExist?"YES":"NO")<<endl;
    return 0;
}