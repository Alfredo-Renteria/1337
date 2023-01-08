/**
* Alfredo Renteria
* Leetcode Problem #127: Word Ladder
* Grind 75 - Hard
* @Topics: Hash Table, String, BFS
* @Time: O(m^2 * n) @Space: O(m^2 * n)
* Where m is the length of each word,
* and n is the total # of words in the input word list
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using stringVec = std::vector<std::string>;
using stringIntPairQ = std::queue<std::pair<std::string, int>>;
using stringUnorderedSet = std::unordered_set<std::string>;

int ladderLength(std::string bWord, std::string eWord, stringVec& wordList) {
    //Queue will hold string and integer pairs
    //The string is a word involved in the 'shortest transformation sequence'
    //And the integer is the count for # of words; ladder length
    stringIntPairQ q;
    int ladderLen = 1;
    //Add the beginning word and count of 1 to the queue
    q.push({bWord, ladderLen});

    //Unordered set holds all words from the dictionary; wordList
    stringUnorderedSet set (wordList.begin(), wordList.end());
    //Remove the beginning word from the set, in case it's in the dictionary
    set.erase(bWord);

    while (!q.empty()) {
        //Pop off the current word and ladder length from the queue
        std::string word = q.front().first;
        ladderLen = q.front().second;
        q.pop();
        //If this word is the end word, we are done -- return ladder length
        if (word == eWord) {
            return ladderLen;
        }
        //Otherwise, for each character in the word, try all lowercase ASCII
        //Combinations to see if word can be found in the set
        for (auto& c : word) {
            //Log original character state
            char og = c;
            for (char ch = 'a'; ch <= 'z'; ch++) {
                c = ch;
                //If the word is found in the set, it will be removed
                //And placed in the queue along with the current # of words
                if (set.find(word) != set.end()) {
                    set.erase(word);
                    q.push({word, ladderLen+1});
                }
            }
            //Return to original state
            c = og;
        }
    }
    //Loop ended without finding the end word, no such sequence exists
    return 0;
}