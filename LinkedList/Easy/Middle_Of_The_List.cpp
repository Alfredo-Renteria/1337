/**
* Alfredo Renteria
* Leetcode Problem #876: Middle Of The Linked List
* Leetcode 75 Level 1 - Easy
* @Topics: Linked List, Two Pointers
* @Time: O(n) @Space: O(1)
*/

#include <iostream>

ListNode* middleNode(ListNode* head) {
    //Initiliaze slow and fast ptr. to the head of the list
    ListNode* slow = head, * fast = head;
    //Fast ptr. is at a node & that node is not the end of the list
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}