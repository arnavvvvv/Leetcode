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
    void reorderList(ListNode* head) {
        if(head->next == NULL)
        return;
      ListNode* fast = head;
      ListNode* slow = head;
      while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
      }
      ListNode* mid = slow->next;
      slow->next = NULL;
      ListNode* a = NULL;
      ListNode* b = mid;
      while(b) {
        ListNode* t = b->next;
        b->next = a;
        a = b;
        b = t;
      }
      mid = a;
      ListNode* start = head;
      while(mid) {
        ListNode* t = start->next;
        start->next = mid;
        start = t;
        t = mid->next;
        mid->next = start;
        mid = t;   
      }
    }
};