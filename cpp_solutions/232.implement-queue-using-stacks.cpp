/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
// private: 
//         stack<int> input_buff, output_buff;
public:
    /** Initialize your data structure here. */
    stack<int> input_buff, output_buff;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        input_buff.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (!output_buff.empty()) {
            int res = output_buff.top();
            output_buff.pop();
            return res;
        }
        int res;
        while(!input_buff.empty()) {
            output_buff.push(input_buff.top());
            input_buff.pop();
        }
        res = output_buff.top();
        output_buff.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        if (!output_buff.empty()) {
            return output_buff.top();
        }
        int res;
        while(!input_buff.empty()) {
            output_buff.push(input_buff.top());
            input_buff.pop();
        }
        return output_buff.top();
    } 
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (input_buff.empty() && output_buff.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

