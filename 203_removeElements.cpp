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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *h = new ListNode(-1);
        h->next = head;
        ListNode *pre = h,*p = head;
        while(p!=NULL){
            if(p->val == val)
                pre->next = p->next;
            else
                pre = p;
            p = pre->next;
        }
        return h->next;
    }
};