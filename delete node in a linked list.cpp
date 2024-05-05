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
    void deleteNode(ListNode* node) {
         if (node == nullptr || node->next == nullptr)
        return; // Edge case, but by problem definition node is not the last node.

    ListNode* nextNode = node->next;
    node->val = nextNode->val; // Copy the value of the next node to this node
    node->next = nextNode->next; // Link to skip the next node

    delete nextNode; // Free the memory of the skipped node
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a new linked list node
ListNode* newNode(int value) {
    return new ListNode(value);
        
    }
};
