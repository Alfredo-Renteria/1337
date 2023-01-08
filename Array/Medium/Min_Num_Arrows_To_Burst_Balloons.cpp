/**
* Alfredo Renteria
* Leetcode Problem #452: Minimum Number of Arrows to Burst Balloons
* January '23 LeetCoding Challenge - Medium
* @Topics: Array, Greedy, Sorting
* Greedy (No Container) @Time: O(n*logn) @Space: O(1)
* Greedy (Vector of Pairs): @Time: O(n*logn) @Space: O(n)
* Where n is the size of points
*/


#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

//Another method for lambda:
//auto ascByEnd = [] (std::vector<int>& a, std::vector<int>& b) {return a[1] < b[1];};
int findMinArrowShots(std::vector<std::vector<int>>& points) {
    const int n = points.size();
    
    //Ascending by points end
    std::sort(points.begin(), points.end(), [] (std::vector<int>& a, std::vector<int>& b) {
                                            return a[1] < b[1];
                                            });
    //Intiailize registered end to 1st point's end
    //Constraints guarantee 1 set of points so arrow starts at 1
    int end = points[0][1], arrows = 1;
    for (int i = 1; i < n; i++) {
        //Registered end is less than curr. point's start
        if (end < points[i][0]) {
            //Update number of arrows shot
            arrows++;
            //Registered end is now curr point's end
            end = points[i][1];
        }
    }

    return arrows;
}

int findMinArrowShots(std::vector<std::vector<int>>& points) {
    const int n = points.size();
    //Points are paired <end, start> orientation in vector
    std::vector<std::pair<int, int>> v;        
    for (auto x : points) {
        v.push_back({x[1],x[0]});
    }

    std::sort(v.begin(),v.end());
    
    int end = v[0].first, arrows = 1;
    for(int i = 1; i < n; i++) {
        if (end < v[i].second) {
            arrows++;
            end = v[i].first;
        }
    }

    return arrows;
}