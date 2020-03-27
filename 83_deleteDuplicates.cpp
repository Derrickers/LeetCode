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
        if(head == NULL||head->next == NULL)
            return head;
        int last;
        ListNode *h = new ListNode(-1);
        h->next = head;
        ListNode *pre = h,*p = pre->next;
        while(p!=NULL){
            last = p->val;
            while(p->next!=NULL&&p->next->val == last)
                p = p->next;
            pre->next = p;
            pre = p;
            p = p->next;
        }
        return h->next;
    }
};