/**
* Alfredo Renteria
* Leetcode Problem #142: Linked List Cycle II
* Leetcode 75 Level 1 - Medium
* @Topics: Hash Table, Linked List, Two Pointers
* Hash Table - @Time: O(n) @Space: O(n)
* Two Pointers - @Time: O(n) @Space: O(1)
*/

#include <iostream>
#include <unordered_map>

ListNode* detectCycle(ListNode* head) {
    std::unordered_map<ListNode* , int> hashMap;
    ListNode* curr = head;
    while (curr) {
        if (hashMap.find(curr) == hashMap.end()) {
            hashMap[curr] = curr->val;
            curr = curr->next;
        } else {
            return curr;
        }
    }
    return nullptr;
}

ListNode* detectCycle(ListNode* head) {
    ListNode* slow_ptr = head, * fast_ptr = head;   
    while (fast_ptr && fast_ptr->next) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;    
        
        if (slow_ptr == fast_ptr) {
            slow_ptr = head;
            while (slow_ptr != fast_ptr) {
                slow_ptr = slow_ptr->next;
                fast_ptr = fast_ptr->next;
            }
            return slow_ptr;
        }
    }
    return nullptr;   
}