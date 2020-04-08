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
        int lenA = 0,lenB = 0;
        ListNode *p = headA,*q = headB;
        while(p!=NULL||q!=NULL){
            if(p!=NULL){
                lenA++;
                p = p->next;
            }
            if(q!=NULL){
                lenB++;
                q = q->next;
            }
        }
        if(lenA>lenB){
            for(int i = 0;i<lenA-lenB;i++)
                headA = headA->next;
        }else{
            for(int i = 0;i<lenB-lenA;i++)
                headB = headB->next;
        }
        while(headA!=headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};