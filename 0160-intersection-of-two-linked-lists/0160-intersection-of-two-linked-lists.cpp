/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == headB) return headA;
        unordered_map<ListNode*, int> mp;
        int i =1;
        ListNode* curr = headA;
        while(curr != NULL){
            mp[curr] = i++;
            curr = curr->next;
        }
        curr = headB;
        while(curr != NULL){
            if(mp[curr] > 0){
                return curr;
            }
            curr = curr->next;
        }

        return NULL;
    }
};