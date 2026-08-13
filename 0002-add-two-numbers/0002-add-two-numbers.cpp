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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return 0;
        int carry = 0;
        ListNode* temp = new ListNode(-1);
        ListNode* dummy = temp;
        while(l1 && l2){
            int val = l1->val + l2->val + carry;
            l1->val = val % 10;
            temp->next = l1;
            carry = val / 10;
            l1 = l1->next;
            l2 = l2->next;
            temp = temp->next;
        }
        while(l1){
            int val = l1->val + carry;
            l1->val = val % 10;
            carry = val / 10;
            temp->next = l1;
            l1 = l1->next;
            temp = temp->next;
        }
        while(l2){
            int val = l2->val + carry;
            l2->val = val % 10;
            carry = val / 10;
            temp->next = l2;
            l2 = l2->next;
            temp = temp->next;
        }
        if(carry){
            temp->next = new ListNode(carry);
            temp = temp->next;
        }
        return dummy->next;
    }
};