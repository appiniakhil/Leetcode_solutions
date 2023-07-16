class Solution {
public:
    bool palindrome(int index1,int index2,string& s)
    {
        while(index1 < index2)
        {
            if(s[index1] != s[index2])
            {
                return false;
            }

            index1++;
            index2--;
        }

        return true;
    }

    //Using Recursion 
    //Time Complexity :exponential && Space Complexity :O(n*n)
    //Time Limit Exceeded
    // int helper(int index1, string s)
    // {
    //     int n = s.size();

    //     if(index1 == n)
    //     {
    //         return 0;
    //     }

    //     int mini = INT_MAX;

    //     for(int index2=index1;index2<n;index2++)
    //     {
    //         if(isPalindrome(index1,index2,s))
    //         {
    //             int cut = 1 + helper(index2+1,s);
    //             mini = min(mini, cut);
    //         }
    //     }

    //     return mini;
    // }

    // int minCut(string s) {
    //     int n = s.size();

    //     return helper(0,s)-1;
    // }
    
    //Using Memorisation
    //Time Complexity :O(n*n) && Space Complexity :O(n) + O(n)
    //Time Limit Exceeded
    // int helper(int index1,string &s,vector<int>&dp)
    // {
    //     int n = s.length();
    //     if(index1 == n)
    //     {
    //         return 0;
    //     }
        
    //     if(dp[index1] != -1)
    //     {
    //         return dp[index1];
    //     }
        
    //     int mini=INT_MAX;

    //     for(int index2=index1;index2<n;index2++)
    //     {
    //         if(palindrome(index1,index2,s))
    //         {
    //             int cut = 1+helper(index2+1,s,dp);

    //             mini=min(mini, cut);   
    //         }
    //     }

    //     return dp[index1] = mini;
    // }

    // int minCut(string s) {
    //     int n=s.length();

    //     vector<int>dp(n,-1);

    //     return helper(0,s,dp)-1;  // subtracted 1 because it will also consider partition after last character  like  suppose   a|bb|c| 
    // }

    //Using Tabulation
    //Time Complexity :O(n*n) && Space Complexity :O(n)
    int minCut(string s) {
        int n=s.length();

        vector<int>dp(n+1, 0);

        for(int index1=n-1;index1>=0;index1--)
        {
            int mini=INT_MAX;

            for(int index2=index1;index2<n;index2++)
            {
                if(palindrome(index1,index2,s))
                {
                    int cut = 1 + dp[index2+1];

                    mini=min(mini, cut);   
                }
            }
            dp[index1] = mini;
        }

        return dp[0] - 1;  // subtracted 1 because it will also consider partition after last character  like  suppose   a|bb|c| 
    }
};
