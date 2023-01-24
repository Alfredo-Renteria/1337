/**
* Alfredo Renteria
* Leetcode Problem #815: Bus Routes
* Grind 75, Leetcode 75 Level 2 - Hard
* @Topics: Array, Hash Table, BFS
* Hash Table + BFS: @Time: O(M * N) @Space: O(M * N)
* Where M is the # of routes (buses), and N is the max # of stops in a route
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>

//Hash Table + Breadth First Search
int numBusesToDestination(std::vector<std::vector<int>>& routes, int source, int target) {
    //No need to take buses
    if (source == target) {
        return 0;
    }

    //Number of routes is the number of rows in the routes grid
    int nRoutes = routes.size();
    
    //Bus stops will map what routes (buses) stop at their station
    std::unordered_map<int, std::vector<int>> otherRoutes;

    //For all routes available and all stop stations within those routes    
    for (int i = 0; i < nRoutes; i++) {
        for (const auto& stop : routes[i]) {
            //Map the stop station to the route
            otherRoutes[stop].push_back(i);
        }
    }
    
    //Set will assist with noting visited stations
    std::unordered_set<int> visited = {source};
    
    //Queue carries integer pairs, for {station, busCount}
    //Used to manage station traversal
    std::queue<std::pair<int, int>> Q;
    //Start at source station, yet to ride a bus (busCount = 0)
    Q.push({source, 0});
        
    while (!Q.empty()) {
        //Get the stop station and total buses used to travel
        int stop = Q.front().first;
        int bus = Q.front().second;
        Q.pop();
        
        //We have arrived!
        if (stop == target) {
            //Return the total number of buses it took to get here
            return bus;
        }

        //For all routes accessible via this stop station
        for (const auto& route : otherRoutes[stop]) {
            //Inspect all the other stops
            for (const auto& otherStop : routes[route]) {
                //If we've never stopped there before
                if (visited.find(otherStop) == visited.end()) {
                    //Add it to visited, as it is added to the route plan
                    visited.insert(otherStop);
                    Q.push({otherStop, bus + 1});
                }
            }
            //Clear all stations for this route
            routes[route].clear();
        }
    }

    //Not possible
    return -1;        
}