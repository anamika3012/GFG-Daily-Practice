/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    Node* constructTree(vector<int> &inorder , vector<int> &postorder , int &postIndex , int inorderStart , int inorderEnd , int size , map<int, int> & ValueMap){
        //base case
        if(postIndex < 0 || inorderStart > inorderEnd) return NULL;
        
        //root Node is leftmost node of preorder
        int element = postorder[postIndex];
        postIndex--;
        Node* root = new Node(element);
        
        //find position of root node in inorder
        int position = ValueMap[element];
        
        //right subTree first because Postorder means LRN and we are moving from back to front in postorder.
        root->right = constructTree(inorder , postorder , postIndex, position+1, inorderEnd, size , ValueMap);
        
        //left SubTree
        root->left = constructTree(inorder , postorder , postIndex, inorderStart , position-1, size , ValueMap);
        
        return root;
    }
    
    
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int size = inorder.size();
        int postIndex = size-1;
        int inorderStart = 0;
        int inorderEnd = size-1;
        
        map<int, int> ValueMap;
        for(int i=0; i<size; i++){
            ValueMap[inorder[i]] = i;
        }
        
        Node* root = constructTree(inorder , postorder , postIndex , inorderStart , inorderEnd, size , ValueMap);
        
        return root;
    }
};