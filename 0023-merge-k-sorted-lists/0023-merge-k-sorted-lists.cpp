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
    ListNode* f(ListNode* l1 , ListNode* l2){
        if(!l1 && !l2) return NULL;
        ListNode* temp = new ListNode(-1);
        ListNode* dummy = temp;
        while(l1 && l2){
            if(l1->val < l2->val){
                temp->next = l1;
                l1 = l1->next;
            }else{
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        if(l1) temp->next = l1;
        else if(l2) temp->next = l2;
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists){
        int n = lists.size();
        if(n == 0) return NULL;
        ListNode* l1 = lists[0];
        for(int i = 1 ; i < n ; i++){
            ListNode* l2 = lists[i];
            l1 = f(l1 , l2);
        }
        return l1;
    }
};