/**
* Alfredo Renteria
* Leetcode Problem #98: Validate Binary Search Tree
* Grind 75, Mock Onsite - Medium
* @Topics: Array, String, DFS, BFS, Union Find
* DFS: @Time: O(n * k * logn*k) @Space: O(n * k)
* Where n is the size of accounts and k is the max size of an account
* Time: nk operations if all emails belong to one person, lognk for std::sort()
*/

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using vecOfVecStrs = std::vector<std::vector<std::string>>;
using strVecStrsUmap = std::unordered_map<std::string, std::vector<std::string>>;
using strUset = std::unordered_set<std::string>;

//Depth First Search
void dfs(vecOfVecStrs& ans, std::string& email, strVecStrsUmap& adjList, strUset& seen) {
    seen.insert(email);
    
    ans.back().push_back(email);
    
    for (auto& adjEmail : adjList[email]) {
        if (seen.count(adjEmail) == 0) {
            dfs(ans, adjEmail, adjList, seen);
        }
    }
}

vecOfVecStrs accountsMerge(vecOfVecStrs& accounts) {
    vecOfVecStrs ans;
    
    strVecStrsUmap adjList;
    
    strUset seen;        
    
    for (const auto& acc : accounts) {
        for (int i = 2; i < acc.size(); i++) {
            adjList[acc[i]].push_back(acc[i-1]);
            adjList[acc[i-1]].push_back(acc[i]);
        }
    }

    for (auto& acc : accounts) {
        if (seen.count(acc[1]) == 0) {
            ans.push_back({acc[0]});
            dfs(ans, acc[1], adjList, seen);
            std::sort(ans.back().begin() + 1, ans.back().end());
        } 
    }

    return ans;
}