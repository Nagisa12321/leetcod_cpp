// io
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstdio>

// containers
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <vector>
#include <forward_list>
#include <stack>

// algorithm
#include <algorithm>
#include <iterator>
#include <numeric>

// memory
#include <memory>

using namespace std;

class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        left_stack.push(x);
    }
    
    int pop() {
        re_push();
        if (right_stack.empty())
            return -1;
        int peek = right_stack.top();
        right_stack.pop();
        return peek;
    }
    
    int peek() {
        re_push();
        if (right_stack.empty())
            return -1;
        return right_stack.top();
    }
    
    bool empty() {
        return left_stack.empty() && right_stack.empty();
    }
private:
    void re_push() {
        if (right_stack.empty()) {
            while (!left_stack.empty()) {
                int peek = left_stack.top();
                left_stack.pop();
                right_stack.push(peek);
            }
        }
    }

    stack<int> left_stack;
    stack<int> right_stack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */