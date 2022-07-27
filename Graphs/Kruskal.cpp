#include <bits/stdc++.h>
#define ll long long
using namespace std;

class node {
   public:
    int u, v, wt;
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};
vector<node> edges;
bool comparator(node a, node b) { return a.wt <= b.wt; }

// set functions
void makeset(vector<int> &parent, vector<int> &rank, int m) {
    for (int i = 0; i < m; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find(int nodeX, vector<int> &parent) {
    if (parent[nodeX] == nodeX) return nodeX;
    return parent[nodeX] = find(parent[nodeX], parent);
}

void Union(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = find(u, parent);
    v = find(v, parent);
    if (rank[u] > rank[v]) {
        parent[v] = u;
    } else if (rank[v] > rank[u])
        parent[u] = v;
    else {
        parent[u] = v;
        rank[v]++;
    }
}
//=============

int main() {
    int n;
    int m;
    cin >> n >> m;  // number of edges m is number of nodes

    for (int i = 0; i < n; i++) {
        int u, v, wt;
        cin >> wt >> u >> v;
        node newNode(u, v, wt);
        edges.push_back(newNode);
    }
    sort(edges.begin(), edges.end(), comparator);
    vector<int> parent(m);
    vector<int> rank(m);
    makeset(parent, rank, m);
    vector<node> ans;
    int cost = 0;
    for (auto edge : edges) {
        //  cout<<(find(edge.u,parent)!=find(edge.v,parent))<<endl;
        if (find(edge.u, parent) != find(edge.v, parent)) {
            cost += edge.wt;
            Union(edge.u, edge.v, parent, rank);
            ans.push_back(edge);
        }
        // cout<<"asd"<<endl;
    }
    cout << endl;
    for (auto edge : ans)
        cout << edge.u << "-" << edge.v << " " << edge.wt << endl;
    cout << cost << endl;
    return 0;
}