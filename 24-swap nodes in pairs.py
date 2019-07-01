# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """

        #recursion
        if (not head  or not head.next):
            return head
        else:
            ans = head.next
            head.next = self.swapPairs(head.next.next)
            ans.next = head
            return ans