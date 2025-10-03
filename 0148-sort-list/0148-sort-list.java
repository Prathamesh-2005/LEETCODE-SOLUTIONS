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
    public ListNode find_m(ListNode head)
    {
        ListNode slow=head;
        ListNode fast=head.next;

        while(fast!=null && fast.next!=null)
        {
            slow=slow.next;
            fast=fast.next.next;
        }
        return slow;
    }
    public ListNode merge(ListNode left,ListNode right)
    {
        if(left==null)
        {
            return right;
        }
        if(right==null)
        {
            return left;
        }

        if(left.val<=right.val)
        {
            left.next=merge(left.next,right);
            return left;
        }
        else 
        {
            right.next=merge(left,right.next);
            return right;
        }
    }
    public ListNode sortList(ListNode head) {
        if(head==null || head.next==null)
        {
            return head;
        }
        ListNode middle=find_m(head);
        ListNode left=head;
        ListNode right=middle.next;
        middle.next=null;
        left=sortList(left);
        right=sortList(right);
        return merge(left,right);
    }
}