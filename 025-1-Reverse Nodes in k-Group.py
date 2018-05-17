# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy
        i = 0
        while (head):
            i += 1
            if (i % k == 0):
                prev = self.reverse(prev, head.next)
                head = prev.next
            else:
                head = head.next
        return dummy.next

    def reverse(self, prev, nxt):
        last = prev.next
        curr = last.next
        while (curr != nxt):
            last.next = curr.next
            curr.next = prev.next
            prev.next = curr
            curr = last.next
        return last
