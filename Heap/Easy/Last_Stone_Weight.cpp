/**
* Alfredo Renteria
* Leetcode Problem #1046: Last Stone Weight
* Leetcode 75 Level 1 - Medium
* @Topics: Array, Heap (Priority Queue)
* @Time: O(n*logn) @Space: O(n)
* Where n is the size of stones
* Time: O(n) to construct PQ & O(logn) for push() & pop()
*/

#include <iostream>
#include <queue>
#include <vector>

int lastStoneWeight(std::vector<int>& stones) {
    std::priority_queue<int> pq(stones.begin(), stones.end());
    
    while (pq.size() > 1) {
        //Max element
        int y = pq.top();
        pq.pop();
        
        //2nd max element
        int x = pq.top();
        pq.pop();
        
        //Since y is max element; x <= y
        //If elements differ, push difference onto PQ
        if (y != x) {
            pq.push(y-x);
        //Elements are equal, 'both stones are destroyed'
        } else {
            pq.push(0);
        }
    }

    return pq.top();
}