class Solution {
  public:
  
  void reversee(vector<int>& arr, int l , int r){
      if(l >= r) return ;
      
      swap(arr[l] , arr[r]);
      
      reversee(arr , l+1, r-1);
  }
  
    void reverseArray(vector<int> &arr) {
        int l = 0;
        int r = arr.size() -1;
        reversee(arr ,l ,r );
    }
};