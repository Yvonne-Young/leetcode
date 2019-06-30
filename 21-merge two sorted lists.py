#Definition for singly-linked list.
#class ListNode(object):
    #def __init__(self, x):
        #self.val = x
        #self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        tmp1 = l1
        tmp2 = l2
        head = ListNode (0)
        tmp = head
        while(tmp1 != None or tmp2 != None):
            if tmp1.val > tmp2.val:
                tmp.next = tmp2
                tmp2 = tmp2.next
            else:
                tmp.next = tmp1
                tmp1 = tmp1.next
            tmp = tmp.next
        if tmp1 != None:
            tmp.next = tmp1
        if tmp2 != None:
            tmp.next = tmp2
        return head.next