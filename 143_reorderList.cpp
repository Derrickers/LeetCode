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
    void reorderList(ListNode* head) {
        if(head==NULL||head->next == NULL)
            return;
        ListNode *p = head,*q = head->next;
        while(q->next!=NULL){
            p = p->next;
            q = q->next;
            if(q->next == NULL)
                break;
            q = q->next;
        }
        ListNode *tmp;
        while(p->next!=q){
            tmp = p->next;
            p->next= p->next->next;
            tmp->next = q->next;
            q->next = tmp;            
        }
        p->next = NULL;
        p = head;
        while(q!=NULL){
            tmp = q->next;
            q->next = p->next;
            p->next = q;
            q = tmp;
            p = p->next->next;
        }
    }
};