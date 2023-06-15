/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return NULL;
        }
        ListNode* curr = head;
        ListNode* prev = new ListNode(-1);
        prev->next = head;
        ListNode* temp = prev;
        while(curr!= NULL){
            
            if(curr->val == val){
                ListNode*nodeToDelete = curr;
                prev->next = curr->next;
                curr = curr->next;
                nodeToDelete->next = NULL;
                delete(nodeToDelete);
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
       head = temp->next;
       return head;
    }
};
