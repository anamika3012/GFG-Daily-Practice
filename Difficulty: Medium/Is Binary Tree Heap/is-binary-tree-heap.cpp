// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
  
  pair<int, bool> solveheap(Node* tree){
      //base case ->leaf node h toh return true
       if(tree == NULL) {
           return {INT_MIN, true};
       }
       //left subTree
       pair<int, bool> leftAns = solveheap(tree->left);
       
       //right subTree
       pair<int, bool> rightAns = solveheap(tree->right);
       
       if(leftAns.second == true && rightAns.second == true && leftAns.first < tree->data && rightAns.first < tree->data){
           return {tree->data , true};
       }
       int largest = max(tree->data , max(leftAns.first , rightAns.first));
       return {largest ,false};
  }
  
  
   bool checkheap_property(Node* tree){
       pair<int , bool > answer = solveheap(tree);
       
       if(answer.second == true) return true;
       
     return false;
   }
  
    
   bool checkCompleteness(Node* tree){
       queue<Node*> q;
       q.push(tree);
       
       bool nullFound = false;
       
       while(!q.empty()){
           Node* front = q.front();
           q.pop();
           
           if(front == NULL){
               nullFound = true;
           }
           else{
               if(nullFound ==  true) return false;
               q.push(front->left);
               q.push(front->right);
           }
       }
      return true;
   }
  
    bool isHeap(Node* tree) {
        bool isCompleteBT = checkCompleteness(tree);
        
        bool isheap = checkheap_property(tree);
        
        if(isCompleteBT && isheap) return true;
        
        return false;
    }
};