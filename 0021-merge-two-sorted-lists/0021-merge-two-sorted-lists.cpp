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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t;
        ListNode* head = NULL;
        ListNode* start = list2;
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        if(list1->val >= list2->val)
            head = list2;
        else
            head = list1;

        while(list1 && list2) {
            while(list2 && (list1->val >= list2->val)) {
                t = list2;
                list2 = list2->next;
            }
            if(list2 != start)
                t->next = list1;
            if(!list2)
                return head;
            while(list1 && (list2->val > list1->val)) {
                t = list1;
                list1 = list1->next;
            }
            t->next = list2;
        }
        return head;
    }
};