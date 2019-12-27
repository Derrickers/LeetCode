/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * @author:Derricker
 * @date:2019/12/23
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = NULL;
        ListNode *p;
        ListNode *r = NULL;
        int psum = 0;
        int num1 = 0,num2 = 0;
        while(l1||l2){
            if(l1){
                num1 = l1->val;
                l1 = l1->next;
            }
            if(l2){
                num2 = l2->val;
                l2 = l2->next;
            }
            psum+=num1+num2;
            num1 = 0;
            num2 = 0;
            p = new ListNode(psum%10);
            if(res == NULL){
                res = p;
                r = res;
            }else{
                r->next = p;
                r = p;
            }
            psum/=10;
        }
        if(psum!= 0){
            p = new ListNode(psum);
            r->next = p;
        }
        return res;å
    }
};
