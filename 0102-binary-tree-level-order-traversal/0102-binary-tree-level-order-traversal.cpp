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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<pair<TreeNode*, int>> q;
        if(!root)
            return result;
        q.push(pair<TreeNode*, int>(root, 0));
        while(q.size()) {
           
            TreeNode* t = q.front().first;
            int level = q.front().second;
            if(level < result.size())
                result[level].push_back(t->val);
            else{
                result.push_back({t->val});
            }
            q.pop();
            if(t->left)
                q.push(pair<TreeNode*, int>(t->left, level + 1));
            if(t->right)
                q.push(pair<TreeNode*, int>(t->right, level + 1));
            
        }
        
        return result;
    }
};