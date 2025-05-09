//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    //Thought Process -> 
            //1. Focus on the leftmost digit , it should be max
    //Logic : 
        //1. swap first digit with all possible digits ,
        //then move recursively with the best solution over here.
        //2. Keep updating maxNum 
    //Optimisation :->
        //1.
    // void helperFunction(string& s, int k , string& maxNum){
    //     //base case
    //     if(k == 0 ){
    //       maxNum = max(maxNum , s);
    //       return;
    //     } 
        
    //     //keep update of maximum number string
    //     maxNum = max(maxNum , s);
        
    //     //digit swaps 
    //     for(int i=0; i<s.size(); i++){
    //         for(int j=i+1; j<s.size(); j++){
    //             swap(s[i], s[j]);
    //             //recursion-> for each digit swap check for all possiblities 
    //             helperFunction(s,k-1, maxNum);
    //             //backtrack
    //             swap(s[i], s[j]);
    //         }
    //     }
    // }
        
    // string findMaximumNum(string& s, int k) {
    //     string maxNum = s;
        
    //     helperFunction(s,k,maxNum);
    //     return maxNum;
    // }
    
    
        void helperFunction(string& s, int k , string& maxNum , int idx){
        //base case
        if(k == 0 || idx == s.size()){
          maxNum = max(maxNum , s);
          return;
        } 
        
        //digit swaps 
        for(int i=idx; i<s.length(); i++){
            if(s[i] > s[idx]){
                swap(s[i], s[idx]); //swap only if digit is greater
                //recursion
                helperFunction(s, k-1, maxNum , idx+1);
                //backtracking
                swap(s[i], s[idx]);
            }
            helperFunction(s , k, maxNum , idx+1);
        }
    }
        
    string findMaximumNum(string& s, int k) {
        string maxNum = s;
        int idx = 0;
        
        helperFunction(s,k,maxNum,idx);
        return maxNum;
    }
    
    

};


//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends