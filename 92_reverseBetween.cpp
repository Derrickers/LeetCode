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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *b = new ListNode(-1),*e = b;
        b->next = head;
        for(int i = 1;i<=n;i++){
            if(i<m)
                b = b->next;
            e = e->next;
        }
        ListNode *p = b->next;
        while(p!=e){
            b->next = p->next;
            p->next = e->next;
            e->next = p;
            p = b->next;
        }
        return m == 1?b->next:head;
    }
};