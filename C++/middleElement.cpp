          // In the Tortoise-Hare approach,
// Create two pointers slow and fast and initialize them to a head pointer.
// Move slow ptr by one step and simultaneously fast ptr by two steps until fast ptr is NULL or next of fast ptr is NULL.
// When the above condition is met, we can see that the slow ptr is pointing towards the middle of Linked List and 
// hence we can return the slow pointer.


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        struct ListNode *slow, *fast;
        slow=head;
        fast=head;
        
        while(fast && fast->next)
            slow=slow->next, fast=fast->next->next;
            return slow;
    }
};

