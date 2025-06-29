class Solution {
  public:
  
   void findMedian(double&  median , priority_queue<int>& maxi , priority_queue<int , vector<int>, greater<int>> &mini, int element){
      //case 1 -> 
      if(maxi.size() ==  mini.size()){
         if(element > median){
             mini.push(element);
             median = mini.top();
         }
         else{
             maxi.push(element);
             median = maxi.top();
         }
      }
      //case 2 ->
      else if(maxi.size() == mini.size()+1){
          if(element > median){
             mini.push(element);
         }
         else{
             int maxTop = maxi.top();
             maxi.pop();
             mini.push(maxTop);
             maxi.push(element);
         }
         median = (mini.top() + maxi.top())/2.0;
      }
      //case 3 ->
      else if(mini.size() ==  maxi.size() + 1){
          if(element > median){
              int minTop = mini.top();
             mini.pop();
             maxi.push(minTop);
             mini.push(element);
         }
         else{
             maxi.push(element);             
         }
         median = (mini.top() + maxi.top())/2.0;
      }
   }
  
    vector<double> getMedian(vector<int> &arr) {
        vector<double> medianAns;
        double median = 0;
        priority_queue<int> maxi;
        priority_queue<int , vector<int>, greater<int>> mini;
        
        for(int i=0; i<arr.size(); i++){
            int element = arr[i];
            findMedian(median , maxi , mini , element);
            medianAns.push_back(median);
        }
        
        return medianAns;
    }
};
