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
    int sum = 0;
    void preorder(TreeNode* root, string s) {
        if(root) {
            if(root->left == NULL && root->right == NULL) {
                s += to_string(root->val);
                cout<<s<<endl;
                int idx = 1;
                int value = 0;
                for(int i = s.size()-1; i>=0; --i) {
                    if(s[i] == '1') {
                        value += idx;
                        cout<<"idx "<<idx<<endl;;
                    }
                        
                    idx *= 2;
                }
                cout<<value<<endl;
                sum += value;
                return;
            }
            s += to_string(root->val);
            preorder(root->left, s);
            preorder(root->right, s);
        }
        return;
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        preorder(root, "");
        return sum;
    }
};