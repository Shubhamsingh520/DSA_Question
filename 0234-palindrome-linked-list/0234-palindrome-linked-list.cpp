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
    ListNode* front;
    bool isrecursive(ListNode* node) {
        if(node == nullptr) {
            return true;
        }
        bool ispal = isrecursive(node->next); 
        if(!ispal) { 
            return false;
        }
        if(front->val != node->val) return false;
        front = front->next;
        return true;
    } 
    bool isPalindrome(ListNode* head) {
        front = head;
        return isrecursive(head); 
         
    }
        
};