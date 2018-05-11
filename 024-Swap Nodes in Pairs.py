# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy = prev = ListNode(0)
        dummy.next = head
        while (head and head.next):
            nxt = head.next
            head.next = nxt.next
            nxt.next = head
            prev.next = nxt
            head = head.next
            prev = nxt.next
        return dummy.next
