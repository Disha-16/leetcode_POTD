class Solution {
    

   
         public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
            ListNode dummy = new ListNode(0);
        dummy.next = list1;
        
        ListNode preA = dummy; // Node before the 'a'th node
        for (int i = 0; i < a; i++) {
            preA = preA.next;
        }
        
        ListNode postB = preA; // Finding the 'b'th node
        for (int i = a; i <= b + 1; i++) {
            postB = postB.next;
        }
        
        // Connect 'preA' to the head of 'list2'
        preA.next = list2;
        
        // Traverse 'list2' until the end
        ListNode tailList2 = list2;
        while (tailList2.next != null) {
            tailList2 = tailList2.next;
        }
        
        // Connect the last node of 'list2' to 'postB'
        tailList2.next = postB;
        
        return dummy.next;
        
    
    }
}
