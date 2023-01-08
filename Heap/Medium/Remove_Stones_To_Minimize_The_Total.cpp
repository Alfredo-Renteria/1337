/**
* Alfredo Renteria
* Leetcode Problem #1962: Remove Stones To Minimize The Total
* December '22 LeetCoding Challenge - Medium
* @Topics: Array, Heap (Priority Queue)
* @Time: O(n + k*logn) @Space: O(n)
* Where n is the size of the piles
*/

#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

int minStoneSum(std::vector<int>& piles, int k) {
    //Get the total sum of stones in all the piles
    int totalSum = std::accumulate(piles.begin(), piles.end(), 0);
    //Initialize heap on the underlying piles vector
    std::priority_queue<int> heap(piles.begin(), piles.end());
    //Loop through exactly k times
    for (int i = 0; i < k; i++) {
        //Get the max heap element and remove it from heap to perform op.
        int curr = heap.top();
        heap.pop();
        //Remove floor(piles[i]/2) stones from piles[i]
        int remove = curr/2;
        //Deduct stones from the total sum
        totalSum -= remove;
        //Push remainder of stones from piles[i] back onto the heap
        heap.push(curr-remove);
    }
    return totalSum;
}