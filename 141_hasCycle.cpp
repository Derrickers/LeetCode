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
    bool hasCycle(ListNode *head) {
        ListNode *p = head,*q = head;
        while(q!=NULL){
            p = p->next;
            q = q->next;
            if(q == NULL)
                break;
            q = q->next;
            if(q == p)
                break;
        }
        if(q == NULL)
            return false;
        else
            return true;
    }
};