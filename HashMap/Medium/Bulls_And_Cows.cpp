/**
* Alfredo Renteria
* Leetcode Problem #299: Bulls And Cows
* Leetcode 75 Level 1 - Medium
* @Topics: Hash Table, String, Counting
* @Time: O(n) @Space: O(n)
* Where n is the length of secret
*/

#include <iostream>
#include <string>
#include <unordered_map>  
  
std::string getHint(std::string secret, std::string guess) {
    const int n = secret.size();
    int bulls = 0, cows = 0;
    
    //Map digits as keys and their counts as values
    std::unordered_map<int, int> map;
    
    //Set up keys & vals
    for (const auto& c : secret) {
        map[c]++;
    }

    //Finding bulls
    for (int i = 0; i < n; i++) {
        //Guessed digit is in the correct pos.
        if (secret[i] == guess[i]) {
            //Increment bulls count & decrease digit count val from map
            bulls++;
            --map[guess[i]];
        }
    }

    //Finding cows
    for (int i = 0; i < n; i++) {
        //Guessed digit is in the wrong pos.; this digit is in the secret #
        if (secret[i] != guess[i] && map[guess[i]] > 0) {
            cows++;
            --map[guess[i]];
        }
    }
    
    return to_string(bulls) + "A" + to_string(cows) + "B";
}