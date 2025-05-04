//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>& a) {
        vector<int> v;
        
        int start_row = 0;
        int start_col = 0;
        int end_row = R-1;
        int end_col = C-1;
        
        int total = R * C;
        int count = 0;
        
        while(count < total){
            //starting row 
            for(int j=start_col; j<= end_col  && count < total; j++){
                v.push_back(a[start_row][j]);
                count++;
            }
            start_row++;
            
            //ending column
            for(int i=start_row; i<=end_row && count<total; i++){
                v.push_back(a[i][end_col]);
                count++;
            }
            end_col--;
            
            //ending row
            for(int j=end_col; j>=start_col && count<total; j--){
                v.push_back(a[end_row][j]);
                count++;
            }
            end_row--;
            
            //starting column
            for(int i=end_row; i>= start_row && count < total; i--){
                v.push_back(a[i][start_col]);
                  count++;
            }
            start_col++;
        }
        
     reverse(v.begin(), v.end());
     return v;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends