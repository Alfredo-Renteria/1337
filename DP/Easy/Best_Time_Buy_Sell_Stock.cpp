/**
* Alfredo Renteria
* Leetcode Problem #121: Best Time To Buy And Sell Stock
* Leetcode 75 Level 1 - Easy
* @Topics: Array, Dynamic Programming
* @Time: O(n) @Space: O(1)
* Where n is the # of prices given
*/

#include <algorithm>
#include <iostream>
#include <vector>

int maxProfit(std::vector<int>& prices) {
    const int n = prices.size();
    //Initialize buyIn at first price; day-0 & profit to $0
    int buyIn = prices[0], profit = 0;
    
    for (int i = 1; i < n; i++) {
        //Curr. day's price > previous day's price
        //Take a shot at maximum profits
        if (prices[i] > prices[i - 1]) {
            profit = std::max(profit, prices[i] - buyIn);
        // Else, see about getting a better buy in price
        } else {
            buyIn = std::min(buyIn, prices[i]);
        }
    }
    
    return profit;
}


/**
* Leetcode Problem #121: Best Time To Buy And Sell Stock II
* Medium
* @Topics: Array, Dynamic Programming, Greedy
* @Time: O(n) @Space: O(1)
* Where n is the # of prices given
*/

int maxProfit(vector<int>& prices) {
    const int n = prices.size();
    int maxTotalProfit = 0;
    
    for (int i = 1; i < n; i++) {
        if (prices[i] > prices[i-1]) {
           maxTotalProfit += prices[i] - prices[i-1];
        }
    }

    return maxTotalProfit;
}