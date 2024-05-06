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
    ListNode* removeNodes(ListNode* head) {
         if (!head || !head->next) return head; // If list is empty or has one element

        // Reverse the linked list
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* next = NULL;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        // `prev` is now the new head of the reversed list
        ListNode* reversedHead = prev;
        
        // Filter the nodes
        ListNode* node = reversedHead;
        ListNode* newHead = NULL; // Head of the final result list
        ListNode* last = NULL;  // Track the last node in result
        int maxVal = INT_MIN;   // Initialize maxVal with the smallest integer
        
        while (node) {
            if (node->val >= maxVal) { // Keep node only if it's greater than any node seen so far
                maxVal = node->val;
                if (!newHead) {
                    newHead = node;
                    last = node;
                } else {
                    last->next = node;
                    last = node;
                }
            }
            node = node->next;
        }
        
        // Ensure the next of last is null
        if (last) {
            last->next = NULL;
        }
        
        // Reverse the list again to restore original order of kept elements
        prev = NULL;
        current = newHead;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        // `prev` is now the new head of the correct list
        return prev;
        
    }
};
