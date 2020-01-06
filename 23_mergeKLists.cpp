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
    ListNode* merge(ListNode *l1,ListNode *l2){
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode *head,*pre,*p;
        if(l1->val<l2->val){
            p = new ListNode(l1->val);
            l1 = l1->next;
        }else{
            p = new ListNode(l2->val);
            l2 = l2->next;
        }
        head = p;
        pre = p;
        while(l1&&l2){
            if(l1->val<l2->val){
                p = new ListNode(l1->val);
                l1 = l1->next;
            }else{
                p = new ListNode(l2->val);
                l2 = l2->next;
            }
            pre->next = p;
            pre = p;
        }
        if(l1)
            pre->next = l1;
        if(l2)
            pre->next = l2;
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        queue<ListNode*> q;
        for(int i = 0;i<lists.size();i++){
            q.push(lists[i]);
        }
        ListNode *a,*b;
        while(q.size()!=1){
            a = q.front();
            q.pop();
            b = q.front();
            q.pop();
            q.push(merge(a,b));
        }
        return q.front();
    }
};
