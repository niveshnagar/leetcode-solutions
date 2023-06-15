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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // base case
        if(head==NULL){
            return NULL;
        }

        // declaring curr, prev;
        ListNode* curr = head;
        ListNode* prev = NULL;

        // finding length of remaining list;
        int length = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            temp= temp->next;
            length++;
        }
        if(length<k){
            return head;
        }
        
        // if there are more than k elements in remaining list
        if(length >= k){
            int counter = 0;
            while( counter < k ){
                ListNode* forward = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forward;
                counter++;
            }
            head->next = reverseKGroup(curr,k);
        }
        
        return prev;
        
    }
};
