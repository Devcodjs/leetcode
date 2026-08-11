# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        if not root : return None
        if root.val == p.val or root.val== q.val:
            return root
        lh = self.lowestCommonAncestor(root.left , p , q)
        rh = self.lowestCommonAncestor(root.right , p , q)

        if lh and rh : return root
        if not lh: return rh
        return lh