/**
* Alfredo Renteria
* Leetcode Problem #202: Happy Number
* Leetcode 75 Level 2 - Easy
* @Topics: Hash Table, Math, Two Pointers
* Two Pointers: @Time: O(m) @Space: O(1)
* Where m is the # of sums of squares of n's digits
*/

#include <iostream>

//Floyd's Cycle-Finding Algorithm
// Helper
int getNext(int n) {
    int totalSum = 0;
    
    while (n > 0) {
        int d = n % 10;
        n /= 10;
        totalSum += d * d;
    }
    
    return totalSum;
}

//Main
bool isHappy(int n) {
    //Slow ptr moves up by 1 & fast ptr by 2
    int slow = n, fast = getNext(n);
    
    //Fast points at 1, we have a happy number
    //Slow points at fast, we have a cycle
    while (fast != 1 && slow != fast) {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
    }

    return fast == 1;
}