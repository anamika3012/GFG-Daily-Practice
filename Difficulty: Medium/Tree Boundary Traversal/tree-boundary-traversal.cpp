/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
  bool isleafnode(Node* root){
      if(root->left== NULL && root->right == NULL) return true;
      return false;
  }
  
   void leftnodes(Node* root , vector<int>& output){
       //base case
       if(isleafnode(root)) return;
       
       output.push_back(root->data);
       
       if(root->left) {
           leftnodes(root->left, output);
       }
       else {
           leftnodes(root->right , output);
       }
   }
  
  
    void leafnodes(Node* root , vector<int>& output){
        if(isleafnode(root)){
            output.push_back(root->data);
            return;
        }
        
        if(root->left) leafnodes(root->left, output);
        if(root->right) leafnodes(root->right, output);
    }
  
   void rightnodes(Node* root , vector<int>& output){
       if(isleafnode(root)) return;
      
       
       if(root->right){
           rightnodes(root->right , output);
       }
       else{
           rightnodes(root->left , output);
       }
       
        output.push_back(root->data);
   }
  
    vector<int> boundaryTraversal(Node *root) {
        
        vector<int> output;
        
        //push root node
        if(!isleafnode(root))  output.push_back(root->data);
        
        //recursive call for left boundary node
        if(root->left)  leftnodes(root->left , output);
        
        //recursive call for leaf nodes
        leafnodes(root, output);
        
        //recursive call for right boundary nodes
        if(root->right)  rightnodes(root->right , output);
        
      return output;
    }
};