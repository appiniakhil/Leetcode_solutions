//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
#include <string>
#include <vector>
// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        //code here
        int n = A.length();
        unordered_set<string> dict;
        
        for (string word : B) {
            dict.insert(word);
        }
        
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= n; ++i) 
        {
            for (int j = 0; j < i; ++j) 
            {
                if (dp[j] && dict.find(A.substr(j, i - j)) != dict.end()) 
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends