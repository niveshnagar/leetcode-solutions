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
    ListNode* midNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast!= NULL && fast->next!= NULL){
            slow = slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        if (head==NULL || head->next == NULL)
            return head;
        
        ListNode* curr = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;

        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {

        if(head->next == NULL){
            return true;
        }
        ListNode* middle = midNode(head);
        ListNode* temp = middle->next;
        middle->next = reverse(temp);

        ListNode* ptr1 = head;
        ListNode* ptr2 = middle->next;
        while(ptr2!=NULL){
            if(ptr1->val != ptr2->val){
                return false;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        temp = middle->next;
        middle->next = reverse(temp);
        return true; 
    }
};
