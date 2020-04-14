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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode *h = new ListNode(-1);
        h->next = head;
        ListNode *end = h;
        while(end->next !=NULL)
            end = end->next;
        while(h->next!=end){
            ListNode *n = h->next;
            h->next = n->next;
            n->next = end->next;
            end->next = n;
        }
        return h->next;
    }
};