/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
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
    // Intersection means from all are the same
    // So, if lenA > lenB, skip A for (lenA - lenB) nodes
    //     else, skip B for (lenB - lenA) nodes
    // Then, move two head pointers together and check if they are the same
    // We only need to find the first same pointer
    // Runtime: 44ms, beats 70.48%
    // Memory usage: 15MB, beats 5.06%
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {return NULL;}
        int m = 0; 
        int n = 0;
        ListNode * p1, * p2;
        for (p1 = headA; p1 -> next != NULL; p1 = p1 -> next) {
            m ++;
        }
        for (p2 = headB; p2 -> next != NULL; p2 = p2 -> next) {
            n ++;
        }
        if (m >= n) {
            for (int i = 0; i < m - n; i ++) {
                headA = headA -> next;
            }
            while (headA != NULL && headB != NULL) {
                if (headA == headB) {return headA;}
                headA = headA -> next;
                headB = headB -> next;
            }
        }
        if (m < n) {
            for (int i = 0; i < n - m; i ++) {
                headB = headB -> next;
            }
            while (headA != NULL && headB != NULL) {
                if (headA == headB) {return headA;}
                headA = headA -> next;
                headB = headB -> next;
            }
        }
        return NULL;
    }
};
// @lc code=end

