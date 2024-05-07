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
    ListNode* doubleIt(ListNode* head) {
         if (!head) return nullptr;

    // Reverse the input linked list to make operations easier
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    ListNode* reversedHead = prev;
    ListNode dummy(0);
    ListNode* ptr = &dummy;
    int carry = 0;

    // Perform doubling on reversed linked list
    while (reversedHead != nullptr || carry != 0) {
        int sum = carry + (reversedHead ? reversedHead->val : 0) * 2;
        carry = sum / 10;
        ptr->next = new ListNode(sum % 10);
        ptr = ptr->next;
        if (reversedHead) reversedHead = reversedHead->next;
    }

    // Reverse result to return it to the proper order
    prev = nullptr;
    curr = dummy.next;
    while (curr != nullptr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;


        
    }
};
