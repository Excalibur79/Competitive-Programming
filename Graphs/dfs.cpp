#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> ans;
void dfs(vector<bool> &visited,vector<vector<int>> &graph,int node){
    if(!visited[node]){
        ans.push_back(node);
        visited[node] = true;
        for(auto neighbour:graph[node]){
            dfs(visited,graph,neighbour);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
    vector<vector<int>> graph = {
        {},
        {2,3,4},
        {1,3},
        {1,2,4,5},
        {1,3,5},
        {4,3,6,7},
        {5},
        {5}
    };

    graph = {
        {1,3},{2},{1},{0}
    };
    vector<bool> visited(graph.size());
    
    dfs(visited,graph,0);
    for(auto value:ans)
        cout<<value<<" ";
    return 0;
}