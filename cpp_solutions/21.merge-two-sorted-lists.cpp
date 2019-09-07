/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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

//Iterative:
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * head = new ListNode(0);
        ListNode * res = head;
        while( l1 != NULL && l2 != NULL ){
            if( l1 -> val < l2 -> val){
                head -> next = l1;
                l1 = l1 -> next;
            }
            else{
                head -> next= l2;
                l2 = l2 -> next;
            }
            head = head -> next;
        }
        if( l1 == NULL && l2 != NULL ){
            head -> next = l2;
        }   
        if( l2 == NULL & & l1 != NULL ){
            head -> next = l1;
        }
        return res -> next;
    }
};

//Recursion:
class Solution {
public:
    ListNode* mergeTwoLists( ListNode* l1, ListNode* l2 ){
        //ListNode * head = new ListNode(0);
        if( l1 == NULL ){
            return l2;
        }
        if( l2 == NULL ){
            return l1;
        }
        if( l1 -> val < l2 -> val ){
            l1 -> next = mergeTwoLists( l1 -> next, l2 );
            return l1;
        }
        else{
            l2 -> next = mergeTwoLists( l2 -> next, l1 );
            return l2;
        }
    }
};

