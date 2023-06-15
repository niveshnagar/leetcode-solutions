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
    ListNode* swapPairs(ListNode* head) {
        // base case
        if(head == NULL || head->next == NULL){
            return head; 
        }

        // declaring curr, prev;
        ListNode* curr = head;
        ListNode* prev = NULL;

        int counter = 0;
        while( counter < 2 ){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            counter++;
        }
        head->next = swapPairs(curr);
    
        return prev;
        
        
    }
};
