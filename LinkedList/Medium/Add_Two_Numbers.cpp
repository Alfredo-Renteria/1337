/**
* Alfredo Renteria
* Leetcode Problem #2: Add Two Numbers
* Mock OA - Medium
* @Topics: Linked List, Math, Recursion
* @Time: O(MAX(m,n)) @Space: O(MAX(m,n)+1)
* Where m & n are the lengths of l1 & l2 respectively
*/

ListNode* addingOneList(ListNode* list, ListNode* currList, int& carry) {
    //'Temp' ptr. points to the last node in the sum list
    ListNode* temp = currList;
    while (list) {
        int calc = list->val + carry;
        carryOps(calc, carry);
        temp->next = new ListNode(calc);
        temp = temp->next;
        list = list->next;
    }
    return temp;
}

//Carry operations helper function
void carryOps(int& calc, int& carry) {
    //Reset carry
    carry = 0;
    //If addition produces a carry
    if (calc > 9) {
        carry = 1;
        calc %= 10;
    }
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //Intiliaze 'calc' w/ addition of the 1st node values from both lists
    //'Carry' will help when evaluations exceed > 9 
    int calc = l1->val + l2->val, carry = 0;
    carryOps(calc, carry);
    //Initialize sum list with node carrying the 1st calculation
    //'Adder' ptr. will assist with the remaining list additions
    ListNode* head = new ListNode(calc), *adder = head;

    l1 = l1->next, l2 = l2->next;
    //This section of code handles when the lists have equal # of nodes
    while (l1 && l2) {
        //Compute addition w/ new values & carry
        calc = l1->val + l2->val + carry;
        carryOps(calc, carry);
        //Add node w/ new calcualtion to the sum list            
        adder->next = new ListNode(calc);
        adder = adder->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    //Take care of remaining nodes in list1 or list2
    adder = addingOneList(l1, adder, carry);
    adder = addingOneList(l2, adder, carry);
    //If there was a carry on the last calculation, add it to the list
    if (carry) {
        adder->next = new ListNode(carry);
    }
    return head;
}