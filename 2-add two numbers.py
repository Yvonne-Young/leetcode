# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        num1 = l1.val
        num2 = l2.val
        i = 1
        j = 1
        while(l1.next != None):
            num1 += l1.next.val * (10**i)
            i += 1
            l1 = l1.next
        while(l2.next != None):
            num2 += l2.next.val * (10**j)
            j += 1
            l2 = l2.next
        sum = num1 + num2
        result = ListNode(sum%10)
        tmp = result
        while (sum/10 != 0):
            sum = sum/10
            l = ListNode(sum%10)
            tmp.next = l
            tmp = tmp.next 
        return result 