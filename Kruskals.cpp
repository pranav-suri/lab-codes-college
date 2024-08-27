#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// A structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// A structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function to find the subset of an element `i`
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Function to do union of two subsets `x` and `y`
void unionSubsets(Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank) {
        subsets[rootX].parent = rootY;
    } else if (subsets[rootX].rank > subsets[rootY].rank) {
        subsets[rootY].parent = rootX;
    } else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Compare two edges according to their weights
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Function to implement Kruskal's algorithm
void kruskalMST(vector<Edge>& edges, int V) {
    // Sort all the edges in non-decreasing order of their weight
    sort(edges.begin(), edges.end(), compareEdges);

    // Allocate memory for creating `V` subsets
    Subset* subsets = new Subset[V];
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    vector<Edge> result;  // This will store the resultant MST

    for (Edge& edge : edges) {
        int x = find(subsets, edge.src);
        int y = find(subsets, edge.dest);

        // If including this edge doesn't cause a cycle
        if (x != y) {
            result.push_back(edge);
            unionSubsets(subsets, x, y);
        }
    }

    // Print the resultant MST
    cout << "Edges in the MST:" << endl;
    for (Edge& edge : result) {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
    }

    // Free the memory allocated for subsets
    delete[] subsets;
}

int main() {
    int V = 4;  // Number of vertices in graph
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
    };

    kruskalMST(edges, V);

    return 0;
}
