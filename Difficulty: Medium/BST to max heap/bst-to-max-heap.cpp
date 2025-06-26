// User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution {
  public:
  
    void inordertraversal(Node* root , vector<int>& inorder){
        if(root == NULL) return;
        
        //inorder -> LNR
        inordertraversal(root->left, inorder);
        inorder.push_back(root->data);
        inordertraversal(root->right, inorder);
    }
  
    void postordertraversal(Node* root , vector<int>& inorder , int& index){
        if(root == NULL) return;
        
        //postorder -> LRN
        postordertraversal(root->left , inorder , index);
        postordertraversal(root->right , inorder , index);
        root->data = inorder[index];
        index++;
    }
  
  
    void convertToMaxHeapUtil(Node* root) {
        //find out inorder traversal of tree
        vector<int> inorder;
        
        inordertraversal(root , inorder);
        
        // now using post order traversal , insert the values into tree -> this will create max heap
        int index = 0;
        postordertraversal(root , inorder, index);
    }
};
