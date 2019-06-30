# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        tmp = head
        tmp_list = []
        while (tmp != None):
            tmp_list.append(tmp.val)
            tmp = tmp.next

        size = len(tmp_list)
        ans = ListNode (0)
        cur = ans
        del tmp_list[size - n]
        for node in tmp_list:
            cur.next = ListNode (node)
            cur = cur.next
        return ans.next