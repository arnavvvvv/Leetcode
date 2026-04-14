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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(!root)
            return v;
        queue<pair<TreeNode*, int>> q;
        q.push(pair<TreeNode*, int>(root, 0));
        while(q.size()) {
            TreeNode* t = q.front().first;
            int level = q.front().second;
            q.pop();
            if(level < v.size())
                v[level] = t->val;
            else
                v.push_back(t->val);
            if(t->left)
                q.push(pair<TreeNode*, int>(t->left, level + 1));
            if(t->right)
                q.push(pair<TreeNode*, int>(t->right, level + 1));
            
        }
        return v;
        
    }
};
