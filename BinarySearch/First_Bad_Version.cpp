/**
* Alfredo Renteria
* Leetcode Problem #278: First Bad Version
* Grind 75, Leetcode 75 Level 1 - Easy
* @Topics: Binary Search, Interactive
* @Time: O(logn) @Space: O(1)
* Where n is the # of versions
* Time: b/c search space is halved each time
*/

#include <iostream>

int firstBadVersion(int n) {
    //Initialize variables to first and last versions
    int low = 1;
    int high = n;

    while (low < high) {
        //Get mid version
        int mid = low + (high-low)/2;
        //Mid version is bad, so high version is moved to mid
        if (isBadVersion(mid)) {
            high = mid;
        //Else, low is moved ahead of mid by one version 
        } else {
            low = mid+1;            
        }
    }

    return low;
}