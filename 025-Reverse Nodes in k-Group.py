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
# solution with extra O(k) memory
        if head == None:
            return None
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy
        stack = []
        nxt = prev.next
        while nxt != None:
            i = 0
            while (nxt is not None) and i != k:
                stack.append(nxt)
                nxt = nxt.next
                i += 1
            if nxt is None and i != k:
                return dummy.next
            else:
                for _ in range(k):
                    prev.next = stack.pop()
                    prev = prev.next
                prev.next = nxt
        return dummy.next
