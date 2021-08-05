#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isValid(vector<vector<char>> &graph,int i,int j){
    if(i<0 || i >n-1 || j<0 || j>n-1)
        return false;
    if(graph[i][j]=='.')
        return true;
    return false;
}

void bfs(vector<vector<char>> &graph,map<pair<int,int>,bool> &visited,pair<int,int> &id){
    visited[id] = true;
    queue<pair<int,int>> q;
    queue.push(id);
    while(!q.empty){
        auto node  = q.front();
        q.pop();
        if(isValid(graph,id.first-1,id.second)){
            visited[{id.first-1,id.second}] = true;
            q.push({id.first-1,id.second});
        }
        if(isValid(graph,id.first+1,id.second)){
             visited[{id.first+1,id.second}] = true;
             q.push({id.first+1,id.second});
        }
        if(isValid(graph,id.first,id.second-1)){
             visited[{id.first,id.second-1}] = true;
             q.push({id.first,id.second-1});
        }
        if(isValid(graph,id.first,id.second+1)){
             visited[{id.first,id.second+1}] = true;
             q.push({id.first,id.second+1});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<char>> graph;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        vector<char> p;
        for(auto character:s)
            p.push_back(character);
        graph.push_back(p);
    }
    map<pair<int,int>,bool> visited;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j]=='.')
                visited[{i,j}] = false;
        }
    }
    int counter=0;
    for(auto value:visited){
        if(value.second==false){
            counter++;
            bfs(graph,visited,value.first);
        }        
    }
    cout<<counter<<endl;
    return 0;
}