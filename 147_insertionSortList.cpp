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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode *p = head->next,*q,*tmp;
        ListNode *h = new ListNode(0);
        h->next = head;
        head->next = NULL;
        while(p!=NULL){
            q = h;
            while(q->next!=NULL&&p->val>q->next->val)
                q = q->next;
            tmp = q->next;
            q->next = p;
            p = p->next;
            q->next->next = tmp;
        }
        return h->next;
    }
};