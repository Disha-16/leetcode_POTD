class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;

        // Step 1: Find the middle of the linked list.
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the linked list.
        slow->next = reverseList(slow->next);
        slow = slow->next;

        // Step 3: Compare the first half with the reversed second half.
        while(slow != NULL) {
            if(head->val != slow->val) return false;
            head = head->next;
            slow = slow->next;
        }

        // The list is a palindrome.
        return true;
    }

private:
    // Helper function to reverse a linked list.
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(head != NULL) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
        
    }
};
