# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if head == None or head.next == None:
            return head
        # find length of the linked list. 
        # let n = length of list
        # if k == n: then the rotated list is the same as before the rotation
        n = 0
        temp = head
        while temp:
            temp = temp.next
            n += 1
        
        if k == n:
            return head
        elif k > n:
            k = k % n

        for i in range(k):
            prev = None
            temp = head
            while temp.next:
                prev = temp
                temp = temp.next
            
            prev.next = None
            temp.next = head
            head = temp
            
        return head