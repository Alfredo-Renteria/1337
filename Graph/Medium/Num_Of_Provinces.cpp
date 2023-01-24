/**
* Alfredo Renteria
* Leetcode Problem #547: Number Of Provinces
* leetcode 75 Level 2 - Medium
* @Topics: DFS, BFS, Union Find, Graph
* DFS: @Time: O(n * n) @Space: O(n * n)
* Where n is the size of the isConnected matrix
*/

#include <iostream>
#include <vector>

//Depth First Search
void dfs(std::vector<std::vector<int>>& adjList, std::vector<bool>& visited, int src) {
    //City has been visited, nothing to do --Return
    if (visited[src]) {
        return;
    }
    //Mark city as visited
    visited[src] = true;
    //For every directly connected city
    for (auto& adjCity : adjList[src]) {
        //If it hasn't been visited
        if (!visited[adjCity]) {
            //Run DFS on directly connected city
            dfs(adjList, visited, adjCity);
        }
    }        
}

int findCircleNum(std::vector<std::vector<int>>& isConnected) {
    //Since isConnected is n*n matrix, we only collect n once from rows
    int n = isConnected.size();
    //For returning total # of provinces
    int count = 0;
    //To mark whether cities have been visited
    std::vector<bool> visited(n+1, false);
    //List of directly connected cities to city
    std::vector<std::vector<int>> adjList(n+1);

    //Fill list of directly connected cities
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && isConnected[i][j] == 1) {
                adjList[i+1].push_back(j+1);
            }
        }
    }
    //For every city that has not been visited
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            //Run DFS on the city
            dfs(adjList, visited, i);
            //Increment provinces count
            count++;
        }
    }

    return count;
}