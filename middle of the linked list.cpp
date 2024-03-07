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
    ListNode* middleNode(ListNode* head) {
          if (head == NULL) return head;
    ListNode *slow = head, *fast = head;
    // Move fast pointer two steps and slow pointer one step at a time
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // When fast pointer reaches the end, slow pointer will be at the middle
    return slow;
}

// Helper function to create a list from an array
ListNode* createList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode *head = new ListNode(nums[0]);
    ListNode *tail = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        tail->next = new ListNode(nums[i]);
        tail = tail->next;
    }
    return head;
        
    }
};
