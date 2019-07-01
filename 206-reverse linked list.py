# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
        #recursive method
        if head.next == None or head == None:
            return head
        else:
            p = self.reverseList(head.next)
            head.next.next = head
            head.next = None
            return p
        
        #straightforward stupid method
        tmp = []
        p = head
        ans = ListNode (0)
        cur = ans
        while p:
            tmp.insert(0,p.val)
            p = p.next
        for n in tmp:
            cur.next = ListNode (n)
            cur = cur.next
        return ans.next
    
        #iterative method
        prev = None
        curr = head
        while (curr != None):
            nextTemp = curr.next
            curr.next = prev
            prev = curr
            curr = nextTemp
        return prev