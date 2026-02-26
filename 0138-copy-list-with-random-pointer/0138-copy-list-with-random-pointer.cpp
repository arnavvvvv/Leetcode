/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* start1 = head;
        Node* start2 = NULL;
        Node* head2 = NULL;
        unordered_map<Node*, Node*> m;
        while(start1) {
            Node* t = new Node(0);
            if(start2)
                start2->next = t;
            else
                head2 = t;
            start2 = t;
            start2->val = start1->val;
            start2->next = NULL;
            start2->random = NULL;
            m[start1] = start2;
            start1 = start1->next;
        
        }
        start1 = head;
        start2 = head2;
        while(start1) {
            start2->random = m[start1->random];
            start2 = start2->next;
            start1 = start1->next;
        }
        return head2;

    }
};