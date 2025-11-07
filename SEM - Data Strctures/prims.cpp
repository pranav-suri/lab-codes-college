#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int prims(int n, const vector<vector<pii>>& graph) {
    vector<bool> inMST(n, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int totalWeight = 0;

    pq.push({0, 0});  // starting from node 0

    while (!pq.empty()) {
        int weight = pq.top().first;  // weight
        int u = pq.top().second;      // source
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        totalWeight += weight;

        for (const auto& edge : graph[u]) {
            int v = edge.second;
            int edgeWeight = edge.first;
            if (!inMST[v]) {
                pq.push({edgeWeight, v});
            }
        }
    }
    return totalWeight;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<pii>> graph(n);
    cout << "Enter each edge as 'u v w' (from u to v with weight w):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }

    int mstWeight = prims(n, graph);
    cout << "Total weight of Minimum Spanning Tree: " << mstWeight << endl;

    return 0;
}
