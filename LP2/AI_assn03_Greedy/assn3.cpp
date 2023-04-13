// Atharv Kulkarni
// Kruskal's MST
// greedy


#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V, E;
    vector<pair<int, pair<int, int>>> edges;

public:
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int w) {
        edges.push_back({w, {u, v}});
    }

    int kruskalMST();
};

class DisjointSet {
    int *parent, *rank;
    int n;

public:
    DisjointSet(int n) {
        this->n = n;
        parent = new int[n+1];
        rank = new int[n+1];

        for (int i = 0; i <= n; i++) {
            rank[i] = 0;
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void merge(int x, int y) {
        x = find(x), y = find(y);

        if (rank[x] > rank[y])
            parent[y] = x;
        else
            parent[x] = y;

        if (rank[x] == rank[y])
            rank[y]++;
    }
};

int Graph::kruskalMST() {
    int mst_weight = 0;
    sort(edges.begin(), edges.end());

    DisjointSet ds(V);

    vector<pair<int, pair<int, int>>>::iterator it;
    for (it = edges.begin(); it != edges.end(); it++) {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        if (set_u != set_v) {
            cout << u << " - " << v << endl;
            mst_weight += it->first;
            ds.merge(set_u, set_v);
        }
    }

    return mst_weight;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    Graph g(V, E);

    cout << "Enter the edges with their weights: \n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    cout << "The Minimum Spanning Tree is: \n";
    int mst_weight = g.kruskalMST();
    cout << "Total Weight: " << mst_weight << endl;

    return 0;
}
