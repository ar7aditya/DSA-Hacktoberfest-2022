// Input  :   lists = [[1,4,5],[1,3,4],[2,6]]
// Output :   lists = [1,1,2,3,4,4,5,6]


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* merge(ListNode* list1, ListNode* list2){
        if(list1==NULL && list2==NULL) return NULL;
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        if(list1->val<list2->val) {
            list1->next = merge(list1->next,list2);
            return list1;
        }
        else{
            list2->next = merge(list2->next,list1);
            return list2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        ListNode *root = lists[0];
        for(int i=1;i<lists.size();i++){
            root = merge(root,lists[i]);
        }
        return root;
            
    }
};

int main(){

    Solution MergeSolution;
    ListNode * ans = MergeSolution.mergeKLists(input_list);
    return 0;
}