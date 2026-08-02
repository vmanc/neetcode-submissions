# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) ->int:
        max_diameter = 0
        
        def dfs(tree_node: Optional[TreeNode]):
            nonlocal max_diameter

            if not tree_node:
                return 0

            length_left = dfs(tree_node.left)
            length_right = dfs(tree_node.right)

            current_diameter = length_left + length_right
            max_diameter = max(max_diameter, current_diameter)
            return 1 + max(length_left, length_right)
        
        dfs(root)
        return max_diameter
