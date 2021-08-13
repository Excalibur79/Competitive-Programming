#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int

const int INF = 1e17;
const int NINF = INF * (-1);

struct triplet {
    int first;
    int second;
    int third;
};

int n, m;
vector<triplet> edges;
vector<int> dist;

void bellman_ford() {
    for (int i = 1; i < n; ++i) {
        for (auto e : edges) {
            int u = e.first;
            int v = e.second;
            int d = e.third;
            if (dist[u] == INF) continue;
            dist[v] = min(dist[v], d + dist[u]);
            dist[v] = max(dist[v], NINF);
        }
    }  // n relaxations

    for (int i = 1; i < n; ++i) {
        for (auto e : edges) {
            int u = e.first;
            int v = e.second;
            int d = e.third;
            if (dist[u] == INF) continue;
            dist[v] = max(dist[v], NINF);
            if (dist[u] + d < dist[v]) {
                dist[v] = NINF;
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    dist.resize(n + 1);
    edges.resize(m);
    for (int i = 0; i < m; ++i) {
        struct triplet inp;
        cin >> inp.first >> inp.second >> inp.third;
        inp.third *= -1;
        edges[i] = inp;
    }

    for (int i = 2; i <= n; ++i) {
        dist[i] = INF;
    }

    bellman_ford();
    if (dist[n] == NINF) {
        cout << -1 << endl;
        return 0;
    }
    cout << dist[n] * (-1) << endl;
}