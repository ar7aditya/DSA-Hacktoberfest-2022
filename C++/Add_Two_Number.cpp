
#include <bits/stdc++.h>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* result = new ListNode(-1);
        ListNode* dummy = result;
        while(p1 || p2 || carry){
            if(!p1 && carry == 0){
                result->next = p2;
                break;
            }
            if(!p2 && carry == 0){
                result->next = p1;
                break;
            }
            int digit1 = p1 ? p1->val : 0;
            int digit2 = p2 ? p2->val : 0;
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            sum %= 10;
            result->next = new ListNode(sum);
            if(p1)  p1 = p1->next;
            if(p2)  p2 = p2->next;
            result = result->next;
        }
        result = dummy->next;
        delete dummy;
        return result;
    }
};







