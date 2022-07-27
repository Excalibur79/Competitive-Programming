#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define int long long int

void dijsktra(vector<vector<pii>> &graph, vector<int> &dist, int start) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty()) {
        pii top = pq.top();
        pq.pop();
        int node = top.second;
        int minValue = top.first;
        if (dist[node] < minValue) continue;
        for (pii neighbourData : graph[node]) {
            int newDist = neighbourData.first + minValue;
            if (newDist < dist[neighbourData.second]) {
                dist[neighbourData.second] = newDist;
                pq.push({newDist, neighbourData.second});
            }
        }
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    vector<int> dist(n + 1, INT_MAX);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
    }
    dijsktra(graph, dist, 1);
    for (int i = 1; i <= n; i++) cout << dist[i] << " ";
    cout << endl;
    return 0;
}