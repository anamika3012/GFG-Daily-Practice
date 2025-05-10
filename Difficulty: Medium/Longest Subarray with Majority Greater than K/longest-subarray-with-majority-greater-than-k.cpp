//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    //Logic ->
        //1. prefixSum = 0 initialise krenge and 
             //a. agar arr[i] > k , then prefixsum+=1 krenge
             //b. if arr[i] <k , then prefixsum -= 1;
             //Why ? -> zisse hme pata chelega ki kisi index pr agar prefixsum > 0 h , then that would mean ki 
                    // (+1) zyada baar hua h , that means ki greater elements ki majority h
                    
        //2. if prefixsum > 0 h , then that means ki avi tk greater elements are in majority , so maxlength += 1;
        
        //3. At every index , we will first check that prefixsum is already prsent in map or not ,
            // if it is present , then move to step 3. 
            //if not present already , then store the prefix sum in map  along with the index at which the sum is
            
        //4. Then map me check krenge if prefixsum -1 value is present or not . If present then that means ki
             // avi current index i se lekr pichhe jis index pr prefixsum-1 value tha , wahan tk greater element
             //ka majority hoga .
             // WHY ? -> arr = [1,2,3,4,1] , isme jb i=3 hoga tb prefixsum = -1 , which is already present in the map
                     // so the maxLength of subarray required will be = [(current index i) - (that index where value was prefixsum-1)]
  
    int longestSubarray(vector<int> &arr, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        int prefixsum = 0;
        int maxlength = 0;
        
        for(int i=0; i<arr.size(); i++){
            //update prefissum
            if(arr[i] > k) prefixsum += 1;
            else prefixsum -=1;
            
            //if prefixsum  > 0 , then just increment maxlength by 1
            if(prefixsum > 0) maxlength += 1;
            
            // check if prefisum -1 is present or not 
            if(mp.count(prefixsum-1)){
                maxlength = max(maxlength , (i - mp[prefixsum-1]));
            }
            
            //if prefixsum is not in mp , then update 
            if(!mp.count(prefixsum)) mp[prefixsum ] = i;
        }
        
        return maxlength;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends