Graph algorithms are fundamental for solving problems in various fields, including networking, AI, and optimization. In C++, you can implement a variety of graph algorithms to solve problems like finding the shortest path, detecting cycles, and traversing graphs. Let's go through some common **graph algorithms** implemented in **C++**:

### **Graph Representation in C++**
Before diving into graph algorithms, it's important to understand how to represent a graph. The two most common representations are:

1. **Adjacency Matrix**: A 2D array where each cell represents the edge between two vertices.
2. **Adjacency List**: A list where each node has a list of adjacent nodes (or edges).

For most graph algorithms, the **adjacency list** representation is more efficient in terms of space complexity, especially for sparse graphs.

### Example of an Adjacency List Representation:
```cpp
#include <iostream>
#include <list>
#include <vector>

using namespace std;

// Graph class
class Graph {
public:
    int V;  // Number of vertices
    vector<list<int>> adjList;  // Adjacency list for storing graph

    Graph(int V);  // Constructor to initialize graph with V vertices
    void addEdge(int v, int w);  // Method to add an edge to the graph
    void printGraph();  // Method to print the adjacency list of the graph
};

// Constructor to initialize graph
Graph::Graph(int V) {
    this->V = V;
    adjList.resize(V);  // Resize the adjacency list to have V lists
}

// Method to add an edge
void Graph::addEdge(int v, int w) {
    adjList[v].push_back(w);  // Add w to v's list
    adjList[w].push_back(v);  // For undirected graph, add v to w's list
}

// Method to print the graph (adjacency list)
void Graph::printGraph() {
    for (int v = 0; v < V; v++) {
        cout << "Vertex " << v << ": ";
        for (int adj : adjList[v]) {
            cout << adj << " ";
        }
        cout << endl;
    }
}

int main() {
    Graph g(5);  // Create a graph with 5 vertices

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(3, 4);

    g.printGraph();  // Print the graph

    return 0;
}
```

---

### **Common Graph Algorithms in C++**

#### **1. Depth-First Search (DFS)**

Depth-First Search (DFS) is an algorithm for traversing or searching tree or graph data structures. It starts at the root (or an arbitrary node) and explores as far as possible along each branch before backtracking.

```cpp
#include <iostream>
#include <list>
#include <vector>
#include <stack>

using namespace std;

class Graph {
public:
    int V;
    vector<list<int>> adjList;

    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int start);
    void DFSUtil(int v, vector<bool>& visited);
};

Graph::Graph(int V) {
    this->V = V;
    adjList.resize(V);
}

void Graph::addEdge(int v, int w) {
    adjList[v].push_back(w);
}

void Graph::DFSUtil(int v, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (int adj : adjList[v]) {
        if (!visited[adj]) {
            DFSUtil(adj, visited);
        }
    }
}

void Graph::DFS(int start) {
    vector<bool> visited(V, false);
    DFSUtil(start, visited);
}

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(3, 4);

    cout << "DFS starting from vertex 0:" << endl;
    g.DFS(0);

    return 0;
}
```

#### **2. Breadth-First Search (BFS)**

Breadth-First Search (BFS) is an algorithm for traversing or searching tree or graph data structures. It starts at the root (or an arbitrary node) and explores all neighbors at the present depth before moving on to nodes at the next depth level.

```cpp
#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

class Graph {
public:
    int V;
    vector<list<int>> adjList;

    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int start);
};

Graph::Graph(int V) {
    this->V = V;
    adjList.resize(V);
}

void Graph::addEdge(int v, int w) {
    adjList[v].push_back(w);
}

void Graph::BFS(int start) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int adj : adjList[v]) {
            if (!visited[adj]) {
                visited[adj] = true;
                q.push(adj);
            }
        }
    }
}

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(3, 4);

    cout << "BFS starting from vertex 0:" << endl;
    g.BFS(0);

    return 0;
}
```

#### **3. Dijkstra's Algorithm (Shortest Path)**

Dijkstra's algorithm is used to find the shortest paths between nodes in a graph, which may represent, for example, road networks.

```cpp
#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

class Graph {
public:
    int V;
    vector<vector<pair<int, int>>> adjList;  // pair (node, weight)

    Graph(int V);
    void addEdge(int u, int v, int weight);
    void dijkstra(int start);
};

Graph::Graph(int V) {
    this->V = V;
    adjList.resize(V);
}

void Graph::addEdge(int u, int v, int weight) {
    adjList[u].push_back({v, weight});
    adjList[v].push_back({u, weight});  // For undirected graph
}

void Graph::dijkstra(int start) {
    vector<int> dist(V, INT_MAX);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto adj : adjList[u]) {
            int v = adj.first;
            int weight = adj.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from vertex " << start << " to other vertices:" << endl;
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << "Vertex " << i << " is unreachable." << endl;
        else
            cout << "Vertex " << i << " : " << dist[i] << endl;
    }
}

int main() {
    Graph g(9);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 5, 4);
    g.addEdge(2, 8, 2);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.dijkstra(0);  // Find shortest paths from vertex 0

    return 0;
}
```

---

### **4. Kruskal’s Algorithm (Minimum Spanning Tree)**

Kruskal’s algorithm is an algorithm for finding the minimum spanning tree (MST) of a graph. It finds an edge of the least possible weight that connects two trees in the forest.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
public:
    int V, E;
    vector<pair<int, pair<int, int>>> edges;  // (weight, (u, v))

    Graph(int V, int E);
    void addEdge(int u, int v, int weight);
    int find(int parent[], int i);
    void Union(int parent[], int rank[], int x, int y);
    void kruskal();
};

Graph::Graph(int V, int E) {
    this->V = V;
    this->E = E;
}

void Graph::addEdge(int u, int v, int weight) {
    edges.push_back({weight, {u, v}});
}

int Graph::find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

void Graph::Union(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (xroot != yroot) {
        if (rank[xroot] < rank[yroot])
            parent[xroot] = yroot;
        else if (rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else {
            parent

[yroot] = xroot;
            rank[xroot]++;
        }
    }
}

void Graph::kruskal() {
    vector<pair<int, pair<int, int>>> mst;
    int parent[V], rank[V];

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    sort(edges.begin(), edges.end());

    for (auto& edge : edges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (find(parent, u) != find(parent, v)) {
            mst.push_back(edge);
            Union(parent, rank, u, v);
        }
    }

    cout << "Edges in MST:" << endl;
    for (auto& edge : mst) {
        cout << edge.second.first << " - " << edge.second.second << " : " << edge.first << endl;
    }
}

int main() {
    Graph g(4, 5);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.kruskal();

    return 0;
}
```

---

These examples provide a basic understanding of how to implement **graph algorithms** in C++. Each of these algorithms is widely used in different applications, such as network routing, shortest path calculations, and optimizing resource usage. You can build more complex systems using these building blocks.