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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode *new_Node = new ListNode();
        new_Node->next = head;
        ListNode *prev = new_Node;
        ListNode *curr = new_Node;
        
        for(int i=1;i<=n;++i){
            prev = prev->next;
        }
        
        while(prev->next!=NULL){
            prev=prev->next;
            curr=curr->next;
        }
        
        curr->next=curr->next->next;
        return new_Node->next;
    }
};