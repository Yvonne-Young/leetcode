/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
using namespace std;

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int num1;
        int num2;
        int carry = 0;
        ListNode * res = new ListNode(0);
        ListNode * result = res;
        while( l1 != NULL or l2 != NULL or carry != 0 ){
            ListNode * n = new ListNode(0);
            res -> next = n;
            if (l1 != NULL){
                num1 = l1 -> val;
            }
            else{
                num1 = 0;
            }
            if (l2 != NULL){
                num2 = l2 -> val;
            }
            else{
                num2 = 0;
            }
            int sum = (num1 + num2 + carry) % 10;
            res -> next -> val = sum;

            if ( l1 != NULL){
                l1 = l1 -> next;
            }
            if ( l2 != NULL){
                l2 = l2 -> next;
            }

            res = res -> next;
            carry = (num1 + num2 + carry) / 10;
            }
        return result -> next;
    }
};

