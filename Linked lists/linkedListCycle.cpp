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
    bool hasCycle(ListNode *head) {
        // if ll has zero element or ll has one element point to NULL
        if(head == NULL || head->next == NULL ){
            return false;
        }
        // if ll has 1 element that is pointing to iteself;
        if(head->next == head){
            return true;
        }
        
        ListNode * slow = head;
        ListNode * fast = head->next;

        while(fast != NULL && fast != slow){
            slow = slow ->next;
            fast = fast->next;
            if (fast==slow){
                return true;
            }
            if (fast != NULL){
                fast = fast->next;
            }
        }
        return fast!= NULL;   
    }
};
