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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return head;
        int last;
        int count = 0;
        ListNode *h = new ListNode(head->val-1);
        h->next = head;
        ListNode *pre = h,*p = pre->next;
        while(p != NULL){
            last = p->val;
            count = 1;
            while(p->next!=NULL&&p->next->val == last){
                p = p->next;
                count++;
            }
            if(count>1)
                pre->next = p->next;
            else
                pre = p;
            p = pre->next;
        }
        return h->next;
    }
};