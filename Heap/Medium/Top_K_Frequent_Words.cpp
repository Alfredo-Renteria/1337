/**
* Alfredo Renteria
* Leetcode Problem #692: Top K Frequent Words
* Leetcode 75 Level 1 - Medium
* @Topics: Hash Table, String, Trie, Sorting, Heap (Priority Queue), Bucket Sort, Counting
* @Time: O(n*logn) @Space: O(n)
* Where n is the size of words
*/

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

//Can also be struct
class comparison {
public:
    bool operator() (const std::pair<std::string,int>& a, const std::pair<std::string,int>& b) {
        if (a.second < b.second) {
            return true;
        }

        if (a.second == b.second && a.first > b.first) {
            return true;
        }

        return false;
    }
};

using strIntPairs = std::pair<std::string, int>;
using myPQ = std::priority_queue<strIntPairs, std::vector<strIntPairs>, comparison>;

std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k) {
    std::unordered_map<std::string, int> freq;
    std::vector<std::string> kFreqStrs;
    
    for (auto w : words){
        freq[w]++;
    }

    myPQ PQ (freq.begin(), freq.end());

    while (k-- > 0) {
        kFreqStrs.push_back(PQ.top().first);
        PQ.pop();
    }

    return kFreqStrs;
}