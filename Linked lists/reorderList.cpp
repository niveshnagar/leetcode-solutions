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
    ListNode* reverseList(ListNode* head){
        // if (head->next == NULL){
        //     return head;
        // }
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        while(curr!= NULL){
            forward =  curr->next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        // step 1 -  reverse list after middle node;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* middleNode = slow;
        ListNode* temp = middleNode->next;

        middleNode->next = reverseList(temp);

        // step 2 - rearrange Nodes;
        ListNode* p = head;
        ListNode* pn = head->next;

        ListNode* t = middleNode->next;
        ListNode* tn;
        if(t!=NULL)
            tn = t->next;

        // cut the list after middle;
        middleNode->next = NULL;
        
        while(p != NULL){
            // start connecting links
            p->next = t;
            if(t!=NULL)
                t->next = pn;

            // update pointers;
            p = pn;
            if(pn != NULL)
                pn = pn->next;
            t = tn;
            if(tn != NULL)
                tn =tn->next;
        }


    }
};
