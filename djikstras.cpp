#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<int> dijkstra(int source, int n, const vector<vector<pii>>& graph) {
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;  // current node
        int d = pq.top().first;   // distance from source
        pq.pop();

        // If the distance in pq is not the least, skip it
        if (d > dist[u]) continue;

        for (const auto& edge : graph[u]) {
            int v = edge.second;      // Neighbor node
            int weight = edge.first;  // Edge weight

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});  // Push updated distance and node into pq
            }
        }
    }
    return dist;
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

    int source;
    cout << "Enter the source node: ";
    cin >> source;

    vector<int> distances = dijkstra(source, n, graph);

    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": " << distances[i] << endl;
    }

    return 0;
}
