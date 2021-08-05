#include <bits/stdc++.h>
#define ll long long
using namespace std;

void bfs(vector<vector<int>> &graph){
    vector<bool> visited(graph.size());
    queue<int> q;
    visited[1] = true;
    q.push(1);
    cout<<1<<endl;
    while(!q.empty()){       
        int node = q.front();
        q.pop();
        for(auto neighbour:graph[node]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                cout<<neighbour<<endl;
                q.push(neighbour);
            }
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
    bfs(graph);
    return 0;
}