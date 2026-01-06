class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int max_i = 0;
        int sum = 0;
        int n= arr.size();
        for(int i=0; i<n; i++){
            if(i>=k) sum = sum^arr[i-k];
            sum = sum^arr[i];
            if(i>=k-1){
            max_i = max(max_i,sum);
        }
        }
        return max_i;
    }
};