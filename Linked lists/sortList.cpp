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
    ListNode* merge(ListNode* first,ListNode* second){
        if(first == NULL){
            return second;
        }
        if(second == NULL){
            return first;
        }
        ListNode* answer = new ListNode(-1);
        ListNode* answerTail = answer;

        while(first != NULL && second != NULL){
            if(first->val < second->val){
                answerTail->next = first;
                answerTail = first;
                first = first->next;
            }
            else{
                answerTail->next = second;
                answerTail = second;
                second = second->next;
            }   
        }

        while(first != NULL){
            answerTail->next = first;
            answerTail = first;
            first = first->next;
        }

        while(second != NULL){
            answerTail->next = second;
            answerTail = second;
            second = second->next;
        }
        answer = answer->next;
        return answer;
    }

    ListNode* getMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        //base case
        if(head == NULL || head->next == NULL){
            return head;
        }

        // step 1 - get middle
        ListNode* middleNode = getMid(head);
        ListNode* first= head;
        ListNode* second = middleNode->next;
        middleNode->next = NULL;

        // step 2 - recursion
        first = sortList(first);
        second = sortList(second);

        // merge first and second
        ListNode* answer = merge(first,second);

        // return answer;
        return answer;
        
    }
};
