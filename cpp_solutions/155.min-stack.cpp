/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
private: 
    vector<int> inner_stack;
    vector<int> inner_min;
public:
    /** initialize your data structure here. */

    // Runtime: 28ms, beats 97.07%
    // Memory usage: 16.5MB, beats 8.67%
    MinStack() {
        inner_min.push_back(INT_MAX);
    }
    
    void push(int x) {
        inner_stack.push_back(x);
        if (x < inner_min.back()) {
            inner_min.push_back(x);
        }
        else {
            inner_min.push_back(inner_min.back());
        }
    }
    
    void pop() {
        inner_stack.pop_back();
        inner_min.pop_back();
    }
    
    int top() {
        return inner_stack.back();
    }
    
    int getMin() {
        return inner_min.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

