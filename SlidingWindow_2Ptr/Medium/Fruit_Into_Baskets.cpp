/**
* Alfredo Renteria
* Leetcode Problem #904: Fruit Into Baskets
* February '23 LeetCoding Challenge - Medium
* @Topics: Array, Hash Table, Sliding Window
* @Time: O(n) @Space: O(n)
* Where n is the size of fruits
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using countMap = std::unordered_map<int, int>;

bool moreThanTwoFruits(countMap& basket) {
    return basket.size() > 2;
}

bool basketIsEmpty(countMap& basket, int i) {
    return basket[i] == 0;
}

int totalFruit(std::vector<int>& fruits) {
    const int n = fruits.size();
    //Two pointers used to define window
    int left = 0, right = 0;
    //Hash map stores the count of each fruit type in the window
    countMap basket;
    
    while (right < n) {
        //Add 1 count of the curr. fruit type to basket
        basket[fruits[right]]++;
    
        if (moreThanTwoFruits(basket)) {
            //Remove 1 count of the left fruit type from basket
            basket[fruits[left]]--;
        
            if (basketIsEmpty(basket, fruits[left])) {
                //Remove fruit type from basket
                basket.erase(fruits[left]);
            }
            left++;
        }
        right++;
    }
    
    //Return length of longest subarray
    return right - left;
}