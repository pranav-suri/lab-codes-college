#include <bits/stdc++.h>
using namespace std;

#define INF 999

void floydWarshall(vector<vector<int>> graph, int V) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (graph[i][k] != INF && graph[k][j] != INF)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    cout << "The shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == INF)
                cout << "INF ";
            else
                cout << graph[i][j] << "   ";
        }
        cout << endl;
    }
}

void printVector(vector<vector<int>> vec) {
    for (unsigned int i = 0; i < vec.size(); i++) {
        for (unsigned int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter the adjacency matrix (use " << INF << " for no direct edge):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    floydWarshall(graph, V);

    return 0;
}
