class Solution {
public:

    //Using Recursion
    //Time Complexity :exponential
    //Time Limit Exceeded
    // int helper(int index1,int index2, string& text1,string& text2)
    // {
    //     if(index1 < 0 || index2 < 0)
    //     {
    //         return 0;
    //     }

    //     if(text1[index1] == text2[index2])
    //     {
    //         return 1 + helper(index1-1,index2-1,text1,text2);
    //     }

    //     return max(helper(index1-1,index2,text1,text2), helper(index1,index2-1,text1,text2));
    // }

    // int longestCommonSubsequence(string text1, string text2) {
    //     int n = text1.size();
    //     int m = text2.size();

    //     return helper(n-1,m-1,text1,text2);
    // }


    //Using Memorisation
    //Time Complexity :O(n*m) && Space Complexity :O(n*m)  + O(n*m)
    // int helper(int index1,int index2, string& text1,string& text2,vector<vector<int>>& dp)
    // {
    //     if(index1 < 0 || index2 < 0)
    //     {
    //         return 0;
    //     }

    //     if(dp[index1][index2] != -1)
    //     {
    //         return dp[index1][index2];
    //     }

    //     if(text1[index1] == text2[index2])
    //     {
    //         return dp[index1][index2] = 1 + helper(index1-1,index2-1,text1,text2,dp);
    //     }

    //     return dp[index1][index2] = max(helper(index1-1,index2,text1,text2,dp), helper(index1,index2-1,text1,text2,dp));
    // }

    // int longestCommonSubsequence(string text1, string text2) {
    //     int n = text1.size();
    //     int m = text2.size();

    //     vector<vector<int>> dp(n,vector<int>(m,-1));

    //     return helper(n-1,m-1,text1,text2,dp);
    // }

    //Using Tabulation
    //Time Complexity :O(n*m) && Space Complexity :O(n*m)
    // int longestCommonSubsequence(string text1, string text2) {
    //     int n = text1.size();
    //     int m = text2.size();

    //     vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
    //     for(int index1=0;index1<=n;index1++)
    //     {
    //         dp[index1][0] = 0;
    //     }

    //     for(int index2=0;index2<=m;index2++)
    //     {
    //         dp[0][index2] = 0;
    //     }
        
    //     for(int index1=1;index1<=n;index1++)
    //     {
    //         for(int index2=1;index2<=m;index2++)
    //         {
    //             if(text1[index1-1] == text2[index2-1])
    //             {
    //                 dp[index1][index2] = 1 + dp[index1-1][index2-1];
    //             }
    //             else
    //             {
    //                 dp[index1][index2] = max(dp[index1-1][index2], dp[index1][index2-1]);
    //             }
    //         }
    //     }
    //     return dp[n][m];
    // }

    //Space Optimisation
    //Time Complexity :O(n*m) && Space Complexity :O(1)
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<int> prev(m+1,0),cur(m+1,0);

        for(int index2=0;index2<=m;index2++)
        {
           prev[index2] = 0;
        }
        
        for(int index1=1;index1<=n;index1++)
        {
            for(int index2=1;index2<=m;index2++)
            {
                if(text1[index1-1] == text2[index2-1])
                {
                    cur[index2] = 1 + prev[index2-1];
                }
                else
                {
                    cur[index2] = max(prev[index2], cur[index2-1]);
                }
            }
            prev = cur;
        }
        return prev[m];
    }
};
