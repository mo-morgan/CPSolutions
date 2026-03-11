# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        height_left = 0
        head = root
        while (head != None):
            head = head.left
            height_left += 1
    
        height_right = 0
        head = root
        while (head != None):
            head = head.right
            height_right += 1

        if (height_left == height_right):
            return 2 ** height_left - 1

        return 1 + self.countNodes(root.left) + self.countNodes(root.right)