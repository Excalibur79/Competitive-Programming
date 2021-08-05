#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<int>>  grid = {{1,1,1,0},{0,0,1,0},{0,0,0,1}};
vector<vector<bool>> visited ;
int ans = INT_MIN;
int size = 0;
const int n=3,m=4;

bool isValid(int i,int j){
    if(i<0 || i >n-1 || j<0 || j>m-1)
        return false;
    if(visited[i][j]==true || grid[i][j]==0)
        return false;
    return true;    
}


void dfs(int i,int j){
    visited[i][j] = true;
    size++;
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
    if(isValid(i-1,j-1))
        dfs(i-1,j-1);
    if(isValid(i-1,j+1))
        dfs(i-1,j+1);
    if(isValid(i+1,j-1))
        dfs(i+1,j-1);
    if(isValid(i+1,j+1))
        dfs(i+1,j+1);
}

void bfs(int i,int j){
    queue<pair<int,int>> q;
    visited[i][j] = true;
    size++;
    q.push({i,j});
    while(!q.empty()){
        pair<int,int> node;
        node = q.front();
        q.pop();
        i = node.first;
        j = node.second;
        if(isValid(i-1,j)){
            size++;
            visited[i-1][j] = true;
            q.push({i-1,j});
        }
        if(isValid(i+1,j)){
            size++;
            visited[i+1][j] = true;
            q.push({i+1,j});
        }
        if(isValid(i,j-1)){
            size++;
            visited[i][j-1] = true;
            q.push({i,j-1});
        }
        if(isValid(i,j+1)){
            size++;
            visited[i][j+1] = true;
            q.push({i,j+1});
        }
        if(isValid(i-1,j-1))
        {
            size++;
            visited[i-1][j-1] = true;
            q.push({i-1,j-1});
        }
           
        if(isValid(i-1,j+1))
        {
            size++;
            visited[i-1][j+1] = true;
            q.push({i-1,j+1});
        }
           
        if(isValid(i+1,j-1)){
            size++;
            visited[i+1][j-1] = true;
            q.push({i+1,j-1});
        }
           
        if(isValid(i+1,j+1)){
            size++;
            visited[i+1][j+1] = true;
            q.push({i+1,j+1});
        }
            
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0;i<grid.size();i++){
       vector<bool> p;
       for(int j=0;j<grid[0].size();j++)
        p.push_back(false);
       visited.push_back(p);            
    }

    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(!visited[i][j] && grid[i][j]==1){
                size=0;
                bfs(i,j);
                ans = max(ans,size);
            }
        }

    }
    cout<<ans<<endl;
    return 0;
}