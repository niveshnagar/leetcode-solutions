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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        ListNode* second = head;

        int counter = 1;
        while(counter < k){
            first = first->next;
            counter++;
        }
        ListNode* Node1 = first;
        while(first->next != NULL){
            first = first->next;
            second = second->next;
        }
        ListNode* Node2 = second;
        swap(Node1->val,Node2->val);
        return head;
    }
};
