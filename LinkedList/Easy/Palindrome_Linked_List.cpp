/**
* Alfredo Renteria
* Leetcode Problem #234: Palindrome Linked List
* Leetcode 75 Level 2 - Medium
* @Topics: Linked List, Two Pointers, Stack, Recursion
* Two Pointers: @Time: O(n) @Space: O(1)
* Stack: @Time: O(n) @Space: O(n)
* Recursion: @Time: O(n) @Space: O(n)
* Where n is the # of nodes in the linked list
*/

#include <iostream>
#include <stack>

//Two Pointers
bool isPalindrome(ListNode* head) {
    //For head of the 1st half of the list (reversed); [mid - start]
    ListNode* firstHalfHead = nullptr;
    //Head of the 2nd half of the list (not reversed); [mid - end]
    ListNode* secondHalfHead = head;
    ListNode* fast = head;
    
    //Reversing the 1st half of the list
    while (fast && fast->next) {
        fast = fast->next->next;
        ListNode* temp = secondHalfHead->next;		    
        secondHalfHead->next = firstHalfHead;
        firstHalfHead = secondHalfHead;
        secondHalfHead = temp;
    }

    //If palindrome is odd fast settles on a node, even; null
    if (fast) {
        secondHalfHead = secondHalfHead->next;
    }

    //Loop through both lists, if values mismatch, it is not a valid palindrome
    while (secondHalfHead) {
	    if (secondHalfHead->val != firstHalfHead->val) {
            return false;
        }
	    secondHalfHead = secondHalfHead->next;
        firstHalfHead = firstHalfHead->next;
    }

    return true;
}

//Stack
bool isPalindrome(ListNode* head) {
    std::stack<int> valStack;
    ListNode* sH = head;
    ListNode* temp = head;

    while (temp && temp->next) {
        temp = temp->next->next;
        valStack.push(sH->val);
        sH = sH->next;
    }
    if (temp) {
        sH = sH->next;
    }

    while (sH) {
        if (sH->val != valStack.top()) {
            return false;
        }
        valStack.pop();
        sH = sH->next;
    }

    return true;
}

//Recursion
//Helper
bool recursePalCheck(ListNode* curr, ListNode*& firstHalf) {
    if (curr) {
        //Recurse calls will get the curr. node to tail of list
        if (!recursePalCheck(curr->next, firstHalf)) {
            return false;
        }
        //Palindrome check; occurs b/n curr. tail & curr. head vals
        if (curr->val != firstHalf->val) {
            return false;
        }
        //Move first half of list ptr along
        firstHalf = firstHalf->next;
    }

    return true;
}

//Main
bool isPalindrome(ListNode* head) {
    ListNode* firstHalf = head;
    return recursePalCheck(head, firstHalf);
}