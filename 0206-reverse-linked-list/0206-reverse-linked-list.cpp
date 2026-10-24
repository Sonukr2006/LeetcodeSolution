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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* curr = head; 
        ListNode* pre = NULL; 
        ListNode* nextNode = NULL;

        while(curr != NULL){
            nextNode = curr->next; // point out the next Node bacause if we mark curr->next to pre(which is denoted as head of ans list), so we lost refence of curr->next that why we are storing reference
            curr->next = pre; // pre being as ans head 
            pre = curr; // after add a new list to ans list we have to mark new pre as head of the list
            curr = nextNode; 
        }

        return pre;
    }
};