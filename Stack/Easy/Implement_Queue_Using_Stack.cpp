/**
* Alfredo Renteria
* Leetcode Problem #232: Implement Queue Using Stacks
* December '22 LeetCoding Challenge - Easy
* @Topics: Stack, Design, Queue
*/

#include <iostream>
#include <stack>

class MyQueue {
public:
    MyQueue() {}

    //@Time: O(1) @Space: O(1)
    void push(int x) {
        if (writeStk.empty()) {
            front = x;
        }
        writeStk.push(x);
    }

    //@Time: Amortized O(1) Worst-Case O(n) @Space: O(1)
    int pop() {
        if (readStk.empty()) {
            while (!writeStk.empty()) {
                readStk.push(writeStk.top());
                writeStk.pop();
            }
        }
        int popVal = readStk.top();
        readStk.pop();
        return popVal;
    }
    
    //@Time: O(1) @Space: O(1)
    int peek() {
        if (!readStk.empty()) {
            return readStk.top();
        }
        return front;
    }

    //@Time: O(1) @Space: O(1)
    bool empty() {
        return writeStk.empty() && readStk.empty();
    }
    
private:
    std::stack<int> writeStk;
    std::stack<int> readStk;
    int front;
};