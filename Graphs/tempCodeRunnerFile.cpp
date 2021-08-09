int node = cycleEnd;
        while (prev[node] != 0) {
            cout << node << endl;
            node = prev[node];
        }