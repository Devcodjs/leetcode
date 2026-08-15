/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    ListNode f(ListNode l1 , ListNode l2){
        if(l1 == null && l2 == null) return null;
        ListNode temp = new ListNode(-1);
        ListNode dummy = temp;
        while(l1 != null && l2 != null){
            if(l1.val < l2.val){
                temp.next = l1;
                l1 = l1.next;
            }else{
                temp.next = l2;
                l2 = l2.next;
            }
            temp = temp.next;
        }
        if(l1 != null)temp.next = l1;
        else if(l2 != null) temp.next = l2;
        return dummy.next;
    }
    public ListNode mergeKLists(ListNode[] lists) {
        int n = lists.length;
        if(n == 0) return null;
        ListNode l1 = lists[0];
        for(int i = 1 ; i < n ; i++){
            ListNode l2 = lists[i];
            l1 = f(l1 , l2);
        }
        return l1;
    }
}