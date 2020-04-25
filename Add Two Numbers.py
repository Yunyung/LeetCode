"""
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
"""


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
"""
    Method1
"""
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode):
        p = l1
        q = l2
        dummyHead = ListNode(0)
        current = dummyHead

        carry = 0 
        sum = 0
        v1 = 0
        v2 = 0
        while(p != None or q != None):
            if p == None:
                v1 = 0
            else:
                v1 = p.val
                p = p.next
            if q == None:
                v2 = 0
            else:
                v2 = q.val
                q = q.next
            sum = v1 + v2 + carry
            carry = 1 if (sum >= 10) else 0
            
            new_node = ListNode(sum % 10)
            current.next(new_node)
            current = new_node
        return current
"""
    Method2
"""
# class Solution:
#     def addTwoNumbers(self, l1, l2):
#         dummy = cur = ListNode(0)
#         carry = 0
#         while l1 or l2 or carry:
#             if l1:
#                 carry += l1.val
#                 l1 = l1.next
#             if l2:
#                 carry += l2.val
#                 l2 = l2.next
#             cur.next = ListNode(carry%10)
#             cur = cur.next
#             carry //= 10
#         return dummy.next
#sol = Solution()
#sol.addTwoNumbers()