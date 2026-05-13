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
    int res = INT_MIN;
    int traverse(TreeNode* root) {
        if(!root)
            return 0;
        // cout<<root->val<<endl;
        int left = max(traverse(root->left), 0);
        int right = max(traverse(root->right), 0);
        // cout<<root->val<<" "<<left<<" "<<right<<" "<<res<<endl;
        if(root->val + left + right > res) {
            res = root->val + left + right;
        }
        // cout<<res<<endl;
        return max(left, right) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        traverse(root);
        return res;
    }
};