// https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1#
class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        bool found = false;
        Node * curr = root;
        Node * succ = NULL;
        while(curr != NULL){
            if(curr->left == NULL) {
                // print
                if(found == true) {
                    succ = curr;
                    break;
                }
                if(curr == x) {
                    found = true;
                }
                
                curr = curr->right;
            }else{
                Node * iop = curr->left;
                while(iop->right != NULL && iop->right != curr) {
                    iop = iop->right;
                }
                if(iop->right == NULL){
                    iop->right = curr;
                    curr = curr->left;
                }else{
                    // print
                    if(found == true) {
                        succ = curr;
                        break;
                    }
                    if(curr == x) {
                        found = true;
                    }
                    
                    iop->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return succ;
    }
};

///********************(ALTERNATE SOLUTION)****************************////////////////////////////////
class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node * succ = NULL;
        if(x->right != NULL) {
            succ = x->right;
            while(succ->left != NULL) {
                succ = succ -> left;
            }
            return succ;
        }
        
        while(root != NULL) {
            if(x->data > root->data) {
                root = root->right;
            }
            else if(x->data < root->data) {
                succ = root;
                root = root->left;
            }else{
                break;
            }
        }
        return succ;
    }
};
