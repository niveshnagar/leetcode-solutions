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

    ListNode* removeNthFromEnd(ListNode* head, int n){

        // step 1 - reverse the linked list;
        head = reverseList(head);

        // step 2 - delete the node;
        if(n == 1){
            ListNode* nodeToDelete = head;
            head = head->next;
            nodeToDelete->next = NULL;
            delete(nodeToDelete);
        }
        else{
            int counter = 1;
            ListNode* temp = head;
            while(counter < n-1){
                temp = temp->next;
                counter++;
            }
            ListNode* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            nodeToDelete->next = NULL;
            delete(nodeToDelete);
        }

        // step 3 - revert the changes made in first step;
        head = reverseList(head);

        return head;
    }
};
