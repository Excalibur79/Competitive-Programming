#include <bits/stdc++.h>
#define ll long long
using namespace std;

void bfs(vector<vector<int>> &graph,vector<bool> &visited,int startNode){
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;
    while(!q.empty()){
        int node = q.front();        
        q.pop();
        for(auto neighbour:graph[node]){
            if(!visited[neighbour]){
                visited[neighbour] =true;
               // cout<<neighbour<<" ";
                q.push(neighbour);
            }
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
   // cin.ignore();
    vector<vector<int>> graph ={    
       {4},
       {2},
       {1,3},
       {2},
       {0,5,7},
       {4,6},
       {5,7},
       {4,6}
    };
    vector<bool> visited(8);
   
    int counter = 0;
    for(int i=0;i<8;i++){        
        if(!visited[i]){
            counter++;
            bfs(graph,visited,i);
        }
    }
    cout<<counter<<endl;
    return 0;
}