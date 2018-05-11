# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        result = []
        for listA in lists:
            while listA:
                result.append(listA.val)
                listA = listA.next
        result.sort()
        return result
            
