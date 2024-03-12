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
    ListNode* removeZeroSumSublists(ListNode* head) {
         ListNode dummy(0), *cur = &dummy;
        dummy.next = head;
        int prefixSum = 0;
        unordered_map<int, ListNode*> seen;

        // First pass: record the last occurrence of each prefix sum
        while (cur) {
            prefixSum += cur->val;
            seen[prefixSum] = cur;
            cur = cur->next;
        }

        // Second pass: remove nodes between duplicated prefix sums
        cur = &dummy;
        prefixSum = 0;
        while (cur) {
            prefixSum += cur->val;
            cur->next = seen[prefixSum]->next;
            cur = cur->next;
        }

        return dummy.next;
        
    }
};
