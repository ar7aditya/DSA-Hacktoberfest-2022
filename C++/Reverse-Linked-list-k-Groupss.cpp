
#include <bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
    //   Function that can create new node 
      ListNode() : val(0), next(NULL) {}
      ListNode(int x) : val(x), next(NULL) {}
     
  };
 
ListNode *revKGroups(ListNode *head, ListNode *prev, int k, int n)
{
    if (!head)
        return prev;
    ListNode *pre = prev;
    ListNode *curr = head;
    ListNode *nxt = head;

    int cnt = 0;
    ListNode *temp = head;
    ListNode *x = nxt;
    // simple reversal of linked list until  cnt<k
    while (nxt && cnt < k)
    {
        nxt = nxt->next;
        x = x->next;
        curr->next = pre;
        pre = curr;

        curr = nxt;
        cnt++;
    }
    n--;

    temp->next = x;
    if (n <= 0)
        return pre;
    if (temp->next)
    {
        temp->next = revKGroups(x, temp, k, n);
    }
    if (cnt < k)
        return temp;
    // returning  reverse liked list head
    return pre;
    
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *prev = NULL;
    ListNode *h = head;
    int cnt = 0;
    // Counting total numbers of node in linked list in cnt
    while (h)
    {
        cnt++;
        h = h->next;
    }
    // calling functin revKGroups to reverse in k Groups
    head = revKGroups(head, prev, k, cnt / k);
    return head;
}
void display(ListNode* head){
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main()
{
    struct ListNode* head;
    head->val=-1;
    ListNode* curr=head;
    // Creating linked list
    while(1){
        printf("Do you want to add new node:1/0 ");
        int choice;
        scanf("%d",&choice);
        if(choice==0) break;
        int data;
        printf("Enter data of node ");
        scanf("%d",&data);
         ListNode* temp=new ListNode(data);
         curr->next=temp;
         curr=temp;

    }
    display(head->next);
    printf("Enter group size: ");
    int k;
    scanf("%d",&k);
    head->next=reverseKGroup(head->next,k);
    display(head->next);
    return 0;
}