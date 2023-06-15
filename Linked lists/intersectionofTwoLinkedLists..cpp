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
        ListNode* head1 = headA;
        ListNode* head2 = headB;
        unordered_map <ListNode*, ListNode*> mapp;
        while(head1!= NULL){
            mapp[head1] = head1;
            head1 = head1->next;
        }
        while(head2!=NULL){
            if(mapp.count(head2)){
                return head2;
            }
            else{
                head2= head2->next;
            }
        }
        return NULL;
    }
};
