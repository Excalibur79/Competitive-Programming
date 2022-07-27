#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
vector<int> dist;

void dijkstra(auto &graph, auto &sources, int v, int e) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for (int data : sources) {
        dist[data] = 0;
        pq.push({0, data});
    }
    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        int node = top.second;
        int minValue = top.first;
        pq.pop();
        if (dist[node] < minValue) continue;
        for (int neighbour : graph[node]) {
            int newDist = dist[node] + 1;
            if (newDist < dist[neighbour]) {
                dist[neighbour] = newDist;
                pq.push({dist[neighbour], neighbour});
            }
        }
    }
}

int main() {
    int v = 6, e = 9;
    vector<vector<int>> graph(v + 1);
    for (int i = 0; i < 9; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dist.resize(v + 1, INT_MAX);
    vector<int> sources(2, 0);
    sources[0] = 1;
    sources[1] = 5;
    bfs(graph, sources, v, e);
    for (int data : dist) cout << data << " ";
    return 0;
}