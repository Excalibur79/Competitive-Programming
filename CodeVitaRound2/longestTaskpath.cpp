// Author: Ankur Saha
// Linkedin: https://www.linkedin.com/in/ankur-saha/
// Github: https://github.com/Excalibur79

#include <bits/stdc++.h>

#include <string>
using namespace std;

#define ll long long
#define int long long int
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
const int MOD = 1e9 + 7;
const ll INF = 1e18;
#define inputarr(arr, n) \
    for (ll i = 0; i < n; i++) cin >> arr[i];
#define printarr(arr, n) \
    for (ll i = 0; i < n; i++) cout << arr[i] << ' ';

int maxLength = INT_MIN;
int length = 0;

bool acyclic = true;

void dfs(map<int, vector<int>> &graph, map<int, bool> &visited, int node) {
    visited[node] = true;
    length++;
    maxLength = max(length, maxLength);
    for (int neighbour : graph[node]) {
        if (!visited[neighbour]) {
            dfs(graph, visited, neighbour);
        } else
            acyclic = false;
    }
    visited[node] = false;
}

void processTheData(string &s, map<int, vector<int>> &graph) {
    bool closed = true;
    string child = "", parent = "";
    string number = "";
    for (char c : s) {
        if (c == '.') {
            child = number;
            // cout << "inserting child " << child << endl;
            if (graph.find(stoi(child)) == graph.end()) graph[stoi(child)] = {};
            number = "";
        } else if (c == ',' && closed) {
            number = "";

        } else if (c == ',' && !closed) {
            parent = number;
            // cout << parent << " aaa" << endl;
            graph[stoi(parent)].pb(stoi(child));
            number = "";
        } else if (c == '{') {
            closed = false;
            number = "";
        } else if (c == '}') {
            closed = true;
            if (number != "") {
                parent = number;
                // cout << parent << " aaa" << endl;
                graph[stoi(parent)].pb(stoi(child));
                number = "";
            }

        } else {
            number += c;
        }
    }
}

void solve() {
    string s;
    getline(cin, s);
    string newString = "";
    for (char c : s) {
        if (c != ' ') newString += c;
    }
    s = newString;
    map<int, vector<int>> graph;
    processTheData(s, graph);

    // for (auto data : graph) {
    //     cout << data.first << "->";
    //     for (int neighbour : data.second) cout << neighbour << " ";
    //     cout << endl;
    // }
    map<int, bool> visited;
    for (auto data : graph) {
        visited[data.first] = false;
    }
    for (auto data : graph) {
        length = 0;
        dfs(graph, visited, data.first);
        if (!acyclic) {
            cout << "error";
            return;
        }
    }
    cout << maxLength;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}