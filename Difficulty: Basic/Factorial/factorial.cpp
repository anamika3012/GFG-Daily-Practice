class Solution {
  public:
  
   int helperfunction(int n){
       if(n == 1 || n == 0) return 1;
       
        return n* helperfunction(n-1);
   }
  
    int factorial(int n) {
        int answer =  helperfunction(n);
        return answer;
    }
};