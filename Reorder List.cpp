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
    void reorderList(ListNode* head) {
          if (!head || !head->next || !head->next->next) return;
        
        // Step 1: Find the middle of the list
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        slow->next = nullptr; // Cut the list
        
        // Step 3: Merge two halves
        mergeLists(head, prev);
    }

private:
    void mergeLists(ListNode* l1, ListNode* l2) {
        while (l1 != nullptr && l2 != nullptr) {
            ListNode* l1_next = l1->next;
            ListNode* l2_next = l2->next;

            l1->next = l2;
            if (l1_next == nullptr) break;
            l2->next = l1_next;
            
            l1 = l1_next;
            l2 = l2_next;
        }
        
    }
};
