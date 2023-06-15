/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#include<unordered_map>
class Solution {
public:
    void insertAtTail(Node* &head, Node* &tail, int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* copyRandomList(Node* head) {
        // step 1 - clone the linked list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;

        while(temp != NULL){
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        // step 2 - create a map

        unordered_map <Node*, Node*> mappings;
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL){
            mappings[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        // step 3 - copy random pointers;
        originalNode = head;
        cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL){
            cloneNode->random = mappings[originalNode->random];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
    
        return cloneHead;
    }
};
