/**
* Alfredo Renteria
* Leetcode Problem #1971: Find If Path Exists In Graph
* December '22 LeetCoding Challenge - Easy
* @Topics: BFS, DFS, Union Find, Graph
* BFS: @Time: O(n + m) Space: O(n + m)
* Where n, m represents the # of nodes, and # of edges respectively
* DFS: @Time: O(n + m) Space: O(n + m)
* Union Find: @Time: O(amortized(n) * m) Space: O(n)
*/

#include <iostream>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <vector>

using adjList = std::unordered_map<int,std::vector<int>>;
using graph = std::vector<std::vector<int>>;
/*
//Breadth First Search
bool validPath(int n, graph& edges, int src, int dest) {
    //Initialize unordered_map that will store all edges in the graph
    adjList graph;
    for (const auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    //Vector will keep track whether nodes have been visited
    std::vector<bool> visited(n);
    visited[src] = true;
    //Queue stores nodes to be visited
    std::queue<int> Q;
    Q.push(src);
    
    while (!Q.empty()) {
        int currNode = Q.front();
        Q.pop();
        if (currNode == dest) {
            return true;
        }
        //For every node in the adjacency list
        for (const auto& nextNode : graph[currNode]) {
            //If the node has not been visited
            if (!visited[nextNode]) {
                //Update the visited marker
                visited[nextNode] = true;
                //And add the node to the queue of nodes to be visited
                Q.push(nextNode);
            }
        }
    }
    return false;
}

//Depth First Search
bool dfs(adjList& graph, std::vector<bool>& visited, int currNode, int dest) {
    if (currNode == dest) {
        return true;
    }
    if (!visited[currNode]) {
        visited[currNode] = true;
        for (const auto& nextNode : graph[currNode]) {
            if (dfs(graph, visited, nextNode, dest)) {
                return true;
            }
        }
    }
    return false;
}

bool validPath(int n, graph& edges, int src, int dest) {
    adjList graph;
    for (const auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    std::vector<bool> visited(n);

    return dfs(graph, visited, src, dest);
}
*/
//Disjoint Set Union
struct UnionFind {
    std::vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 1) {
        std::iota(parent.begin(), parent.end(), 0);
    }
    int Find(int x) {
        if (x != parent[x]) {
            parent[x] = Find(parent[x]);
        }
        return parent[x];
    }   
    void Union(int x, int y) {
        //Replace nodes by roots
        int rootX = Find(x), rootY = Find(y);
        std::cout << rootX << rootY << std::endl;
        //If roots are in the same set --Get out
        if (rootX == rootY) {
            return;
        }
        //Without union by rank, time complexity will be O((m+n)logn)
        if (rank[rootX] < rank[rootY]) {
            std::swap(rootX, rootY);
        }
        parent[rootY] = rootX;
        if (rank[rootX] == rank[rootY]) {
            rank[rootX] += 1;
        }
    }
};

bool validPath(int n, graph& edges, int src, int dest) {
    UnionFind uf(n);
    for (int i = 0; i < n; i++) {
        std::cout << uf.parent[i] << std::endl;
    }
    for (const auto& edge : edges) {
        uf.Union(edge[0], edge[1]);
    }
    
    return uf.Find(src) == uf.Find(dest);
}

int main() {
    std::vector<std::vector<int>> ex1 = {{0,1},{1,2},{0,2},{3,1},{3,4}};
    if (validPath(6, ex1, 0, 4)) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }
    return 0;
}