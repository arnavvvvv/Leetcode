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
    stack<int> st;
public:
    int goodNodes(TreeNode* root) {
        int val;
        int count = 0;
        if(!root)
            return 0;
        if(!st.size()) {
            val = root->val;
            count += 1;
        }
        else if(st.size() && root->val >= st.top()) {
            count += 1;
            val = root->val;
        }
        else if(st.size() && root->val < st.top()) {
            val = st.top();
        }
        st.push(val);
        count += goodNodes(root->left);
        count += goodNodes(root->right);
        st.pop();
        return count;
            

    }
};