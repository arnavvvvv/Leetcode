/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    int idx = 0;
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "N,";
        string s = to_string(root->val) + ",";
        s += serialize(root->left);
        s += serialize(root->right);
        // cout<<s<<endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data[idx] == 'N') {
            idx += 2;
            return nullptr;
        }
            
        TreeNode* t = new TreeNode;
        int val = 0;
        bool neg = false;
        if(data[idx] == '-') {
            neg = true;
            ++idx;
        }
        while(data[idx] != ',') {
            val = val * 10 + (data[idx] - '0');
            ++idx;
        }
        if(neg)
            val = val * -1;
        t->val = val;
        idx += 1;
        t->left = deserialize(data);
        t->right = deserialize(data);
        return t;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));