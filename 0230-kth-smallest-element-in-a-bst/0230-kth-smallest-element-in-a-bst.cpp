/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int count = 0;
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root)
            return -1;
        int left = kthSmallest(root->left, k);
        ++count;
        if(count == k)
            return root->val;
        int right = kthSmallest(root->right, k);
        return (left > right) ? left : right; 
    }
};