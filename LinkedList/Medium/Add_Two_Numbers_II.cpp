/**
* Alfredo Renteria
* Leetcode Problem #445: Add Two Numbers II
* Leetcode 75 Level 1 - Medium
* @Topics: Linked List, Math, Stack
* @Time: O() @Space: O()
* 
*/


#include <iostream>
#include <stack>
#include <utility>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode *curr = nullptr, *next = head->next;
    while (next) {
        head->next = curr;
        curr = head;
        head = next;
        next = head->next;
    }
    head->next = curr;
    return head;
}

ListNode* addNode(ListNode* node1, ListNode* node2) {
    ListNode *prev = nullptr;
    int carry = 0, sum = 0;
    
    while (node1 || node2 || carry > 0) {
        
        if (node1) {
            sum += node1->val;
            node1 = node1->next;
        }
        if (node2) {
            sum += node2->val;
            node2 = node2->next;
        }
        if (carry) {
            sum += carry;
        }
        
        ListNode* curr = new ListNode(sum % 10);
        curr->next = prev;
        prev = curr;
        carry = sum / 10;
        sum = 0;
    }
    return prev;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* revL1 = reverseList(l1);
    ListNode* revL2 = reverseList(l2);
    return addNode(revL1, revL2);
}


ListNode* testList(std::vector<int> arr) {
    const int n = arr.size();
    
    if (n == 0) {
        return nullptr;
    }
    
    ListNode* list = nullptr;
    list = new ListNode(arr.front());
    ListNode* temp = list;

    for (int i = 1; i < n; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return list;
}

int main() {

    ListNode* t1 = testList({7,2,4,3});
    ListNode* t2 = testList({5,6,4});

    ListNode* ans = addTwoNumbers(t1, t2);


    return 0;
}