/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode * p = new ListNode(0);
        ListNode *q;
        p = head;
        q = head;

        while ( head != NULL and head -> val == val ){
            head = head -> next;
        }
        while ( q != NULL ){
            if ( q -> val == val){
                p -> next = q -> next;
                q = p -> next;
            }
            else{
                p = q;
                q = p -> next;
            }
            }
        return head;
    }
};

