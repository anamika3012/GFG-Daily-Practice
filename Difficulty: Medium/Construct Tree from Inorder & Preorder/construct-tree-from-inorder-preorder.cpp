// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to build the tree from given inorder and preorder traversals
    Node* constructTree(vector<int> &inorder , vector<int> &preorder , int &preIndex , int inorderStart , int inorderEnd , int size , map<int, int> & ValueMap){
        //base case
        if(preIndex >= size || inorderStart > inorderEnd) return NULL;
        
        //root Node is leftmost node of preorder
        int element = preorder[preIndex];
        preIndex++;
        Node* root = new Node(element);
        
        //find position of root node in inorder
        int position = ValueMap[element];
        
        //left SubTree
        root->left = constructTree(inorder , preorder , preIndex, inorderStart , position-1, size , ValueMap);
        
        //right subTree
        root->right = constructTree(inorder , preorder , preIndex, position+1, inorderEnd, size , ValueMap);
        
        return root;
    }
    
    
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int size = inorder.size();
        int preIndex = 0;
        int inorderStart = 0;
        int inorderEnd = size-1;
        
        map<int, int> ValueMap;
        for(int i=0; i<size; i++){
            ValueMap[inorder[i]] = i;
        }
        
        Node* root = constructTree(inorder , preorder , preIndex , inorderStart , inorderEnd, size , ValueMap);
        
        return root;
    }
};