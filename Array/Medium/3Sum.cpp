/**
* Alfredo Renteria
* Leetcode Problem #452: Minimum Number of Arrows to Burst Balloons
* Grind 75 - Medium
* @Topics: Array, Two Pointers, Sorting
* Sorting + Two Pointers: @Time: O(n^2) @Space: O(log(n))
* Where n is the size of nums
*/

vector<vector<int>> threeSum(vector<int>& nums) {
    const int n = nums.size();
    
    //2D vector that will store triplets; results
    vector<vector<int>> res;
    
    //Sort nums in ascending order
    //This facilitates the management of duplicate triplets
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        if (i == 0 || nums[i] != nums[i-1]) {
            //Initialize left cursor one pos. to the right of curr. 
            int l = i + 1;
            //Initialize right cursor to the last elem. of nums
            int r = n - 1;
            while (l < r) {
                //Calculate 3sum; curr. + left + right elems.
                int threeSum = nums[i] + nums[l] + nums[r];
                //If total sum is 0
                if (threeSum == 0) {
                    //Add vector of elems. to result
                    res.push_back({nums[i],nums[l], nums[r]});
                    //Move left cursor one pos. down
                    l++;
                    //Prevent duplicates
                    while (nums[l] == nums[l-1] && l < r) {
                        l++;
                    }
                //Sum is negative, move left one pos. to the right    
                } else if (threeSum < 0) {
                    l++;
                //Else, sum is positive, move right one pos. to the left
                } else {
                    r--;
                }
            }
        }
    }

    return res;
}