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
    int d = 0;
    int height(TreeNode* root) {
        if(!root)
            return 0;
        int dl = height(root->left);
        int dr = height(root->right);
        if((dl + dr) > d)
            d = dl + dr;
        return 1 + max(dl, dr);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
       
        height(root);
        return d;
    }
};
