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
        ListNode* root = new ListNode(-1);
        ListNode* dummy = root;
        while(list1 && list2){
            if (list1->val < list2->val){
                root->next = list1;
                list1 = list1->next;
            }else{
                root->next = list2;
                list2 = list2->next;
            }
            root = root->next;
        }
        if(list1) root->next = list1;
        else root->next = list2;
        return dummy->next;
    } 
};