/**
* Alfredo Renteria
* Leetcode Problem #42: Trapping Rain Water
* Grind 75 - Hard
* @Topics: Array, Two Pointers, Dynamic Programming, Stack, Monotonic Stack
* @Time: O(n) @Space: O(n) --DP Solution
* @Time: O(n) @Space O(1) --2 Ptrs. Solution
* Where n is the # of given heights,
* Space for DP b/c vector, constant for pointer solution
*/

#include <algorithm>
#include <iostream>
#include <vector>

//Dynamic Programming Solution
int trap(std::vector<int>& height) {
    int ans = 0, size = height.size();
    std::vector<int> leftMax(size), rightMax(size);

    leftMax[0] = height[0];
    righMax[0] = height[size-1];

    for (int i = 1; i < size; i++) {
        leftMax[i] = std::max(height[i], leftMax[i-1]);
    }

    for (int i = size-2; i >= 0; i--) {
        rightMax[i] = std::max(height[i], rightMax[i+1]);
    }

    for (int i = 1; i < size-1; i++) {
        ans += std::min(leftMax[i], rightMax[i]) - height[i];
    }

    return ans;
}

//Two Pointers Solution
int trap2(std::vector<int>& height) {
    //Init. two pointers, left & right
    int left = 0, right = height.size()-1;
    //Init. max height holders for left & right sides
    int leftMax = 0, rightMax = 0;
    int ans = 0;
    //Until the left ptr reaches the right ptr
    while (left < right) {
        //If height @ left ptr is less than height at right ptr
        if (height[left] < height[right]) {
            //If height @ left ptr is greater than left max height
            if (height[left] > leftMax) {
                //Reassign left max height
                leftMax = height[left];
            } else {
                //Else height @ left ptr is less than left max height
                //Add the diff b/n left max height and height @ left ptr.
                ans += (leftMax - height[left]);
            }
            left++; //Move left ptr along
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                ans += (rightMax - height[right]);
            }
            right--;
        }
    }
    return ans;
}