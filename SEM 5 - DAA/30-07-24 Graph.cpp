#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Graph {
    int V;
    vector<pair<int, int>>* adj;

   public:
    Graph(int V);
    void addEdge(int v, int w, int weight);
    void printGraph();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new vector<pair<int, int>>[V];
}

void Graph::addEdge(int v, int w, int weight) {
    adj[v].emplace_back(make_pair(w, weight));
}

void Graph::printGraph() {
    for (int v = 0; v < V; ++v) {
        cout << "Adjacency list of vertex " << v << "\n head";
        for (auto& x : adj[v])
            cout << " -> " << x.first << "(" << x.second << ")";
        cout << endl;
    }
}

int main() {
    int V = 5;
    Graph g(V);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 20);
    g.addEdge(1, 2, 30);
    g.addEdge(1, 3, 40);
    g.addEdge(1, 4, 50);
    g.addEdge(2, 3, 60);
    g.addEdge(3, 4, 70);

    g.printGraph();
    return 0;
}