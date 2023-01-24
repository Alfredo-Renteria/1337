/**
* Alfredo Renteria
* Leetcode Problem #210: Course Schedule II
* Grind 75, Leetcode 75 Level 2 - Medium
* @Topics: DFS, BFS, Graph, Topological Sort
* Topological Sort: @Time: O(V + E) @Space: O(V + E)
* Where V is the # of vertices (courses), and E is the # of edges (prereqs)
*/

#include <iostream>
#include <vector>
#include <queue>

//Topological Sort
std::vector<int> findOrder(int nCourses, std::vector<std::vector<int>>& prereqs) {
    //Every course has a list of upper courses available after completion
    std::vector<std::vector<int>> adj(nCourses);
    //Will keep count of courses that must be completed prior to enrollment
    std::vector<int> inDegree(nCourses, 0);
    
    //Loop through prereqs list
    for (const auto& p : prereqs) {
        //Map prereq with upper course
        adj[p[1]].push_back(p[0]);
        //Add to courses to be completed count for this upper course
        inDegree[p[0]]++;
    }

    //To manage enrolling and completing courses
    std::queue<int> Q;
    
    //Loop through all courses
    for (int i = 0; i < nCourses; i++) {
        //If there is a course available for enrollment, then enroll
        if (inDegree[i] == 0) {
            Q.push(i);
        }
    }
    
    //Return vector, to store courses in order
    std::vector<int> top_order;
    
    while (!Q.empty()) {
        //Completed the course
        int course = Q.front();
        Q.pop();
        top_order.push_back(course);
        
        //Look at upper courses, if elligible, then enroll
        for (const auto& a : adj[course]) {
            inDegree[a]--;
            if (inDegree[a] == 0) {
                Q.push(a);
            }
        }
    }
    
    //More classes were completed than available, there is a cycle in the graph
    //Impossible to finish all courses
    if (top_order.size() != nCourses) {
        return std::vector<int>{};
    
    }
    
    return top_order;
}