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
        ListNode* slow = head , *fast = head ;
        while(fast && fast->next){
            slow  = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = NULL , *second = slow->next;
        slow->next = NULL;
        while(second){
            ListNode* temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }
        fast = head;
        second = prev;
        while(second){
            ListNode* p1 = fast->next , *p2 = second->next;

            fast->next = second;
            second->next = p1;
            
            fast =  p1;
            second = p2;
        }
    }
};