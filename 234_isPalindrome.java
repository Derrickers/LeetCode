/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head == null)
            return true;
        ListNode h = new ListNode(-1);
        h.next = head;
        ListNode slow = h,quick = h;
        while(quick!=null&&quick.next!=null){
            slow = slow.next;
            quick = quick.next;
            if(quick != null)
                quick = quick.next;
        }
        quick = slow.next;
        slow.next = null;
        while(quick!=null){
            ListNode tmp = quick.next;
            quick.next = slow.next;
            slow.next = quick;
            quick = tmp;
        }
        quick = slow.next;
        slow = h.next;
        while(quick!=null){
            if(quick.val !=slow.val)
                return false;
            quick = quick.next;
            slow = slow.next;
        }
        return true;
    }
}