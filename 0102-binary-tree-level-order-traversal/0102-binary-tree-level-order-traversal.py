# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        l = []
        ans = []
        l.append(root)
        level_count = 1
        while len(l) > 0:
            row = []
            count = level_count
            level_count = 0
            while count:
                t = l[0]
                l.pop(0)
                if t.left:
                    l.append(t.left)
                    level_count += 1
                if t.right:
                    l.append(t.right)
                    level_count += 1
                count -= 1
                row.append(t.val)
            ans.append(row)
        return ans

                





        