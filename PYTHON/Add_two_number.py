# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        
        dummy = ListNode(-1)
        head = dummy
        c, n = 0, 0
        
        while l1 or l2 or c:
            
            n1 = l1.val if l1 else 0
            n2 = l2.val if l2 else 0
            
            n = n1+n2+c
            if l1 or l2: 
                l1 = l1.next if l1 else None
                l2 = l2.next if l2 else None
                head.next = ListNode(n%10)
                head = head.next
                c = n//10
            else: head.next = ListNode(c); c = 0;

        return dummy.next