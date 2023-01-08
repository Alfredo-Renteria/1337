/**
* Alfredo Renteria
* Leetcode Problem #2095: Delete The Middle Node of a Linked List
* Leetcode 75 Level 1 - Medium
* @Topics: Linked List, Two Pointers
* @Time: O(n) @Space: O(1)
*/

ListNode* deleteMiddle(ListNode* head) {
    if (!head->next) {
        return nullptr;
    }
    ListNode* slow = head, * fast = head, *mod = head;
    while (fast && fast->next) {
        mod = slow;
        fast = fast->next->next;
        slow = slow->next;
    }
    mod->next = slow->next;
    delete slow;
    slow = nullptr;
    
    return head;
}