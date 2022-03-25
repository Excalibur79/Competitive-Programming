#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

void dijkstra(map<int, vector<pair<int, int>>> &graph, vector<int> &dist,
              vector<bool> &visited, int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        q;
    dist[start] = 0;
    q.push({})
}

int main() {
    int e, n;
    cin >> e >> n;
    map<int, vector<pair<int, int>>> graph;
    for (int i = 0; i < e; i++) {
        int x, y, wt;
        cin >> x >> y >> Wt;
        graph[x].push_back(y, wt);
        graph[y].push_back(x, wt);
    }
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    dijkstra(graph, dist, visited, 0);
    for (int data : dist) cout << data << " ";
    return 0;
}