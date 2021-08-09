#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
using namespace std;

char graph[1000][1000];
bool visited[1000][1000];
int dist[1000][1000];
int n, m;
bool pathExist = false;
int pathLength = 0;

bool isValid(int i, int j) {
    if (i < 0 || i > n - 1 || j < 0 || j > m - 1) return false;
    if (visited[i][j] == true || graph[i][j] == '#') return false;
    return true;
}

void dfs(int i, int j) {
    visited[i][j] = true;
    if (graph[i][j] == 'B') pathExist = true;
    if (isValid(i - 1, j)) {
        dfs(i - 1, j);
    }
    if (isValid(i + 1, j)) {
        dfs(i + 1, j);
    }
    if (isValid(i, j - 1)) {
        dfs(i, j - 1);
    }
    if (isValid(i, j + 1)) {
        dfs(i, j + 1);
    }
}

void bfs(int i, int j) {
    int iConfig[] = {-1, 1, 0, 0};
    int jConfig[] = {0, 0, -1, 1};
    queue<pair<int, int>> q;
    visited[i][j] = true;
    q.push(mp(i, j));

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (isValid(x + iConfig[i], y + jConfig[i])) {
                if (!visited[x + iConfig[i]][y + jConfig[i]]) {
                    visited[x + iConfig[i]][y + jConfig[i]] = true;
                    q.push(mp(x + iConfig[i], y + jConfig[i]));
                    dist[x + iConfig[i]][y + jConfig[i]] = dist[x][y] + 1;
                    if (graph[x + iConfig[i]][y + jConfig[i]] == 'B') {
                        pathExist = true;
                        break;
                    }
                }
            }
        }
        if (pathExist) break;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int startI, startJ;
    int endI, endJ;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            graph[i][j] = c;
            if (c == 'A') {
                startI = i;
                startJ = j;
            }
            if (c == 'B') {
                endI = i;
                endJ = j;
            }
        }
    }
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            dist[i][j] = 0;
        }
    }

    bfs(startI, startJ);
    if (pathExist) {
        cout << "YES" << endl;
        cout << dist[endI][endJ] << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}