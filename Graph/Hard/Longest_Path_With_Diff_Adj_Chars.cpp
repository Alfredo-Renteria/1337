/**
* Alfredo Renteria
* Leetcode Problem #2246: Longest path With Different Adjacent Characters
* January '23 LeetCoding Challenge - Hard
* @Topics: Array, String, Tree, DFS, Graph, Topological Sort
* BFS: @Time: O(n) @Space: O(n)
* Where n is the # of nodes in the tree
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

//Breadth First Search
int longestPath(std::vector<int>& parent, std::string s) {
    const int n = parent.size();
    int longestPath = 1;
    
    std::vector<int> childrenCount(n);
    
    for (int node = 1; node < n; node++) {
        childrenCount[parent[node]]++;
    }
    
    std::vector<std::pair<int, int>> longestChains(n);
    std::queue<int> q;
    
    for (int node = 0; node < n; node++) {
        if (childrenCount[node] == 0 && node != 0) {
            q.push(node);
            longestChains[node].first = 1;
        }
    }
    
    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        int par = parent[currentNode];
    
        if (s[currentNode] != s[par]) {
            if (longestChains[currentNode].first > longestChains[par].first) {
                longestChains[par].second = longestChains[par].first;
                longestChains[par].first = longestChains[currentNode].first;
            } else if (longestChains[currentNode].first > longestChains[par].second) {
                longestChains[par].second = longestChains[currentNode].first;
            }
        }
    
        longestPath = max(longestPath, longestChains[par].first + longestChains[par].second + 1);
        childrenCount[par]--;
    
        if (childrenCount[par] == 0 && par != 0) {
            longestChains[par].first++;
            q.push(par);
        }
    }

    return longestPath;
}