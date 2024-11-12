#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int src, dest, weight;
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

bool compareEdge(Edge a, Edge b) {
    return a.weight < b.weight;
}

class UnionFind {
   private:
    vector<int> parent, rank;

   public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV])
                parent[rootU] = rootV;
            else if (rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

vector<Edge> kruskalMST(int V, vector<Edge> &edges) {
    vector<Edge> mst;
    UnionFind uf(V);

    sort(edges.begin(), edges.end(), compareEdge);

    for (const Edge &edge : edges) {
        int u = edge.src;   // source
        int v = edge.dest;  // destination

        if (uf.find(u) != uf.find(v)) {
            mst.push_back(edge);
            uf.unite(u, v);

            if (mst.size() == V - 1)
                break;
        }
    }

    return mst;
}

int main() {
    int V = 4;
    vector<Edge> edges;

    edges.push_back(Edge(0, 1, 10));
    edges.push_back(Edge(0, 2, 6));
    edges.push_back(Edge(0, 3, 5));
    edges.push_back(Edge(1, 3, 15));
    edges.push_back(Edge(2, 3, 4));

    vector<Edge> mst = kruskalMST(V, edges);

    cout << "Edges in the Minimum Spanning Tree:\n";
    for (const Edge &edge : mst) {
        cout << edge.src << " - " << edge.dest << " (Weight: " << edge.weight << ")\n";
    }

    return 0;
}
