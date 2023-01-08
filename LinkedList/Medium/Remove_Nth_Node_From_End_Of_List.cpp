
/**
* Alfredo Renteria
* Leetcode Problem #19: Remove Nth Node From End Of List
* Leetcode 75 Level 2 - Medium
* @Topics: Linked List, Two Pointers
* @Time: O(n) @Space: O(1)
* Where n is the # of nodes in the linked list
*/

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    
    while (head) {
        head = head->next;
        curr->next = prev;
        prev = curr;
        curr = head;
    } 
    
    return prev;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* start = new ListNode(0, reverseList(head));
    ListNode* slow = start;
    ListNode* fast = start;
    
    while (n > 0) {
        fast = fast->next;
        n--;
    }
    
    while (slow->next != fast) {
        slow = slow->next;
    }
    
    slow->next = slow->next->next;
    
    delete fast;
    
    return reverseList(start->next);  
}