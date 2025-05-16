//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        int start = 0;
        int end = arr.size() - 1;
        int index = -1;
        
        while(start <= end){
            int mid = start + ( end - start)/2;
            
            //if arr[i] is greater than k, move left
            if(arr[mid] > k) end = mid -1;
            //if arr[i] is smaller than k, move right
            else if(arr[mid] < k) start = mid+1;
            //otherwise return that indexx
            else{
                index = mid;
                end = mid -1;
            } 
        }
    return index;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<int> arr;
        string input;
        cin.ignore();
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int res = ob.binarysearch(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends