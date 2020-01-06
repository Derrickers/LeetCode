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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
            return head;
        ListNode *pre = head,*a = head,*b = head;
        while(n>0&&b!=NULL){
            b = b->next;
            n--;
        }
        if(n != 0)
            return head;
        if(b == NULL)
            return head->next;
        while(b!=NULL){
            pre = a;
            a = a->next;
            b = b->next;
        }
        pre->next = a->next;
        return head;
    }
};
