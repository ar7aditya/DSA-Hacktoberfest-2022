// link :- https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// Time Complexity - O(nlog(n))
class Solution {
public:
    class Pair {
        public:
        TreeNode * node;
        int d;
        int w;
        Pair(TreeNode * node , int w , int d) {
            this->node = node;
            this->d = d;
            this->w = w;
        }
    };
    // Comparable 
    struct comp {
        bool operator()(Pair a , Pair b) {
            if(a.d == b.d) {
                return a.node->val <= b.node->val;
            }else{
                return a.d <= b.d;
            }
        }
    };
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<Pair> q;
        q.push(Pair(root , 0 , 1));
        map<int , vector<Pair>> map;
        int lw = 0;
        int rw = 0;
        while(q.size() > 0) {
            Pair front = q.front();
            q.pop();
            
            if(front.w < lw) {
                lw = front.w;
            }
            if(front.w > rw){
                rw = front.w;
            }
            
            map[front.w].push_back(front);
            
            if(front.node->left != NULL){
                q.push(Pair(front.node->left , front.w - 1 , front.d + 1));
            }
            if(front.node->right != NULL) {
                q.push(Pair(front.node->right , front.w + 1 , front.d + 1));
            }
            
        }
        
        for(int i = lw ; i <= rw ; i++){
            vector<int> partOfAns;
            vector<Pair> unsortedList = map[i];
            sort(unsortedList.begin() , unsortedList.end() , comp());
            for(Pair temp : unsortedList) {
                partOfAns.push_back(temp.node->val);
            }
            ans.push_back(partOfAns);
        }
        return ans;
        
    }
};
