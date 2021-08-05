#include <bits/stdc++.h>
#define ll long long
using namespace std;

int parent[10000];
int rank[10000];

void makeset(){
    for(int i=0;i<n;i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int find(int node){
    if(parent[node] == node)
        return node;
    return parent[node] = find(parent[node]);
}

void Union(int u,int v){
    u = find(u);
    v = find(v);
    if(rank[u]<rank[v]){
        parent[u] = v;       
    }
    else if(rank[v]<rank[u])
        parent[v] = u;
    else{
        parent[v] = u;
        rank[u]++;
    }
}

int main()
{
   
    
    return 0;
}