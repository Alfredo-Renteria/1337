/**
* Alfredo Renteria
* Leetcode Problem #692: Top K Frequent Words
* Grind 75, Leetcode 75 Level 1 - Medium
* @Topics: Array, Hash Table, Greedy, Sorting, Heap (Priority Queue), Counting
* @Time: O(k*26log26) @Space: O(26)
* Where k is the # of tasks
*/

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int leastInterval(std::vector<char>& tasks, int n) {
    int totalTime = 0;
    int count[26] = {};
    std::priority_queue <int> max_heap;
    std::queue<std::pair<int,int>> Q;
    
    for (auto& t : tasks) {
        count[t - 'A']++;
    }
    
    for (auto& c : count) {
        if (c > 0) {
            max_heap.push(c);
        }
    }
    
    while (!max_heap.empty() || !Q.empty()) {
        totalTime++;
        if (!Q.empty()) {               
            if (totalTime > Q.front().second) {
                max_heap.push(Q.front().first);
                Q.pop();
            }
        }

        if (!max_heap.empty()) {
            int taskTime = max_heap.top();
            max_heap.pop();
            taskTime--;
            if (taskTime > 0) {
                Q.push({taskTime, totalTime + n});
            }
        }
    }

    return totalTime;
}
