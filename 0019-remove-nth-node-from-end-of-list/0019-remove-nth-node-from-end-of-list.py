# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        count = 0
        start = head
        while(start is not None):
            count += 1
            start = start.next
        count = count - n
        fast = head
        slow = None
        if count == 0:
            head = head.next
        else:
            while(count):
                prev = fast
                fast = fast.next
                count -= 1
            # print(prev.val)
            # print(fast.val)
            prev.next = fast.next
        return head