# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        if (head == None):
            return head
        
        totlen = 1
        headtmp = head
        while (headtmp is not None):
            headtmp = headtmp.next
            totlen += 1
            
        totlen -= 1
        index = 0
        headtmp2 = head
        if n >= totlen:
            return head.next
        else:
            while (headtmp2 is not None):
                if index == totlen - n:
                    break
                prev = headtmp2
                headtmp2 = headtmp2.next
                index += 1
            prev.next = prev.next.next
        return head
