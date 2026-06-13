#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <algorithm>
#include <set>

using namespace std;

class Graph
{
private:
    unordered_map<int, vector<pair<int, double>>> adjList;
    int numVertices;
    bool isDirected;

    void DFSUtil(int node, unordered_map<int, bool>& visited, vector<int>& result);
    bool hasCycleDFS(int node, unordered_map<int, int>& color);
    void topologicalSortUtil(int node, unordered_map<int, bool>& visited, stack<int>& st);

public:
    Graph(int vertices = 0, bool directed = false);
    ~Graph();

    // Basic operations
    void addEdge(int u, int v, double weight = 1.0);
    void removeEdge(int u, int v);
    void updateWeight(int u, int v, double newWeight);
    void displayGraph() const;
    int getNumVertices() const;
    vector<int> getAllVertices() const;

    // Traversals
    vector<int> BFS(int start);
    vector<int> DFS(int start);

    // Shortest paths
    vector<double> Dijkstra(int source);
    vector<double> BellmanFord(int source);

    // MST
    vector<pair<int, int>> PrimMST();
    vector<pair<int, int>> KruskalMST();

    // DAG operations
    vector<int> TopologicalSort();
    bool hasCycle();

    // Connectivity
    bool hasPath(int u, int v);
    vector<vector<int>> findConnectedComponents();

    // Utility
    vector<pair<int, double>> getNeighbors(int vertex) const;
    double getEdgeWeight(int u, int v) const;
    int getNumEdges() const;
    vector<int> reconstructPath(vector<int>& parent, int source, int destination);
};

#endif // GRAPH_H
