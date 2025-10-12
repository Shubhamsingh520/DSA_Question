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
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        ListNode* i = list1;
        ListNode* j = list2;

        while(i != nullptr && j != nullptr) { 
            if(i->val <= j->val) {
                current->next = i;   
                    i = i->next;
                } else {
                    current->next = j;
                    j = j->next;
                }
                current = current->next;
            }
            if(i != nullptr) { 
                current->next = i;
            }else if (j != nullptr) {
                current->next = j;
            }
            return dummy->next;
    }

};