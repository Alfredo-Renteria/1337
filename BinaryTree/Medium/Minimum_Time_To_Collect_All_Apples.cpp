/**
* Alfredo Renteria
* Leetcode Problem #1443: Minimum Time to Collect All Apples in a Tree
* Januar '23 LeetCoding Challenge - Medium
* @Topics: Hash Table, Tree, DFS, BFS
* @Time: O(V + E) @Space: O(V + E)
* Where V is the # of nodes and E is the # of edges
*/

#include <iostream>
#include <vector>

using vecOfbools = std::vector<bool>;
using vecOfVecInts = std::vector<std::vector<int>>;

int  traversal(int u, int lvlsFromLastApp, vecOfBools& hasapple, vecOfBools& seen, vecOfVecInts& adj, int& time) {    
    //Every node will explore one depth height unless apple is found
    int depthToExplore = 1;
    //Mark visited node
    seen[u] = true;

    //This node has an apple
    if (hasapple[u]) {
        //Add to time the distance you have walked since last seeing an apple
        time += lvlsFromLastApp;
        //No more depth to explore since this node has an apple
        depthToExplore = 0;
    }

    //Traverse all adjacent nodes that have not been visited
    for (auto v : adj[u]) {
        if (!seen[v]) {
            depthToExplore *= traversal(v, lvlsFromLastApp * depthToExplore + 1, hasapple, seen, adj, time);
        }
    }

    return depthToExplore;
}

int minTime(int n, std::vector<std::vector<int>>& edges, std::vector<bool>& hasApple) {
    constexpr int thereNBack = 2;
    int time = 0;
    std::vector<std::vector<int>> adj(n);
    std::vector<bool> seen(n, false);
    
    for (const auto& e : edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    traversal(0, 0, hasApple, seen, adj, time);
    
    return time * thereNBack;   
}   