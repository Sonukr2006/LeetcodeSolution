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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode leftNode = null;
        ListNode curr = head;
        int cnt = 1;
        while(cnt < left){
            leftNode = curr;
            curr = curr.next;
            cnt++;

        }


        ListNode pre = null;
        ListNode nextNode = null;
        ListNode startNodeAtLeft = curr;

        cnt = 1;
        while(cnt <= (right - left)+1){
            nextNode = curr.next;
            curr.next = pre;
            pre = curr;
            curr = nextNode;
            cnt++;
        }

        startNodeAtLeft.next = nextNode;

        if(leftNode != null)
            leftNode.next = pre;
        else
            head = pre;


        return head;
    }
}