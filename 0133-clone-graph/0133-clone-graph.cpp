/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;
        queue<Node*> q;
        unordered_map<int, Node*> m;
        q.push(node);
        Node* t = new Node;
        t->val = node->val;
        m[t->val] = t;
        while(!q.empty()) {
            Node* node = q.front();
            q.pop();
            Node* new_node = m[node->val];
            for(int i = 0; i < node->neighbors.size(); ++i) {
                
                if(m.find(node->neighbors[i]->val) != m.end())
                    new_node->neighbors.push_back(m[node->neighbors[i]->val]);
                else {
                    Node* t = new Node;
                    t->val = node->neighbors[i]->val;
                    m[t->val] = t;
                    new_node->neighbors.push_back(m[node->neighbors[i]->val]);
                    q.push(node->neighbors[i]);
                }
            }

        }
        return t;
    }
};