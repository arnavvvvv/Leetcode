/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* front = head->next;
        ListNode* back = head;
        head->next = NULL;
        while(front) {
            ListNode* t = front->next;
            front->next = back;
            back = front;
            if(t == NULL)
                head = front;
            front = t;
        }
        return head;
    }
};