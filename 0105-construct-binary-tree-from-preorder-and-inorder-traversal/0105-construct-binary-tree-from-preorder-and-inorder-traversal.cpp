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
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() <= 0 || inorder.size() <= 0)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        int idx = find(begin(inorder), end(inorder), preorder[0]) - begin(inorder);
        vector<int> preleft(begin(preorder) + 1, begin(preorder) + idx + 1);
        vector<int> preright(begin(preorder) + idx + 1, end(preorder));
        vector<int> inleft(begin(inorder), begin(inorder) + idx);
        vector<int> inright(begin(inorder) + idx + 1, end(inorder));
        root->left = buildTree(preleft, inleft);
        root->right = buildTree(preright, inright);
        return root;
    }
};