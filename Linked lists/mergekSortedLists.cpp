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
ListNode* solve(ListNode* first, ListNode* second){
        ListNode* curr1 = first;
        ListNode* next1 = first->next;
        ListNode* curr2 = second;
        ListNode* next2 = second->next;
        
        if(first->next == NULL){
            first->next=second;
            return first;
        }

        while(next1 != NULL && curr2 != NULL){
            if((curr1->val <= curr2->val) && (curr2->val <= next1->val)){
                
                // inserting element
                next2 = curr2->next;
                curr2->next = next1;
                curr1->next = curr2;


                // updating pointers;
                curr1 = curr2;
                curr2 = next2;
            }
            else{
                curr1=curr1->next;
                next1=next1->next;
                if(next1 ==NULL){
                    curr1->next=curr2;
                    return first;
                }
            }
        }
        return first;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1==NULL){
            return list2;
        }

        if(list2==NULL){
            return list1;
        }

        if(list1->val < list2->val){
            return solve(list1, list2);
        }
        else{
            return solve(list2, list1);
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        // case 1 -  if the array is empty;
        if(n == 0){
            return NULL;
        }

        // case 2 - if the array has only one list inside;
        if(n == 1){
            return lists[0];
        }

        // case 3 - if there are two or more lists in the array;
        while(lists.size() != 1){
            ListNode* firstList = lists[lists.size()-1];
            ListNode* secondList = lists[lists.size()-2];
            ListNode* mergedList = mergeTwoLists(firstList, secondList);
            lists.pop_back();
            lists.pop_back();
            lists.push_back(mergedList);
        }
        
        ListNode* answerHead = lists[0];
        return answerHead;
    }
};
