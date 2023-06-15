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

    int pairSum(ListNode* head) {
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
        ListNode* ptr1 = head;
        ListNode* ptr2 = middleNode->next;

        int answer = INT_MIN;
        while(ptr2!=NULL){
            int sum = ptr1->val + ptr2->val;
            answer = max(answer,sum);
            ptr1= ptr1->next;
            ptr2= ptr2->next;
        }
        return answer;

        
    }
};
