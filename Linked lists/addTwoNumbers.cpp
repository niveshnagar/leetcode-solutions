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
    void insertAtTail(ListNode* &head, ListNode* &tail, int digit){
        ListNode* temp = new ListNode(digit);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }

    ListNode* addLists(ListNode* first, ListNode* second){
        int sum = 0;
        int carry = 0;
        ListNode* head1 = first;
        ListNode* head2 = second;

        ListNode* answerHead = NULL;
        ListNode* answerTail = NULL; 
        
        while( head1!=NULL || head2 != NULL || carry != 0){
            int num1 = 0; 
            if(head1 !=NULL){
                num1 = head1->val;
            }
            int num2 = 0; 
            if(head2 != NULL){
                num2 = head2->val;
            }

            sum = carry + num1 + num2;
            int digit = sum%10;
            insertAtTail(answerHead, answerTail, digit);
            carry = sum/10;

            
            if(head1 != NULL){
                head1 = head1->next;
            }
            if(head2 != NULL){
                head2 = head2->next;
            }
        }
        return answerHead;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer =  addLists (l1,l2);
        return answer;
    }
};
