
class Solution {
  public:
    int gcd(int a, int b) {
        //base case
        if(b == 0) return a;
        
        return gcd(b , a%b);
    }
};
