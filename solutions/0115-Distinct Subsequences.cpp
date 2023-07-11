class Solution {
public:

    //Using Recursion
    //Time Complexity :exponential && Space Complexity :O(n*m)
    //Time Limit Exceeded
    // int helper(int index1,int index2,string s,string t)
    // {
    //    if(index2 < 0) 
    //    {
    //        return 1;
    //    }

    //    if(index1 < 0)
    //    {
    //        return 0;
    //    }

    //    if(s[index1] == t[index2])
    //    {
    //        return helper(index1-1,index2-1,s,t)  + helper(index1-1,index2,s,t);
    //    }

    //     return helper(index1-1,index2,s,t);
    // }

    // int numDistinct(string s, string t) {
    //     int n = s.size();
    //     int m = t.size();
    //     return helper(n-1,m-1,s,t);
    // }

    //Using Memrisation
    //Time Complexity :O(n*m) && Space Complexity :O(n*m) + O(n+m)
    // int helper(int index1,int index2,string s,string t,vector<vector<int>>& dp)
    // {
    //     if(index2 < 0) 
    //     {
    //         return 1;
    //     }

    //     if(index1 < 0)
    //     {
    //         return 0;
    //     }
    //     if(dp[index1][index2] != -1)
    //     {
    //         return dp[index1][index2];
    //     }
    
    //     if(s[index1] == t[index2])
    //     {
    //         return dp[index1][index2] = helper(index1-1,index2-1,s,t,dp)  + helper(index1-1,index2,s,t,dp);
    //     }

    //     return dp[index1][index2] = helper(index1-1,index2,s,t,dp);
    // }

    // int numDistinct(string s, string t) {
    //     int n = s.size();
    //     int m = t.size();
    //     vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    //     return helper(n-1,m-1,s,t,dp);
    // }

    //Using Tabulation
    //Time Complexity :O(n*m) && Space Complexity :O(n*m)
    // int numDistinct(string s, string t) {
    //     int n = s.size();
    //     int m = t.size();

    //     vector<vector<double>> dp(n+1,vector<double>(m+1,0));

    //     for(int index2=1;index2<=m;index2++)
    //     {
    //         dp[0][index2] = 0;
    //     }

    //     for(int index1=0;index1<=n;index1++)
    //     {
    //         dp[index1][0] = 1;
    //     }

    //     for(int index1=1;index1<=n;index1++)
    //     {
    //         for(int index2=1;index2<=m;index2++)
    //         {
    //             if(s[index1-1] == t[index2-1])
    //             {
    //                 dp[index1][index2] = dp[index1-1][index2-1] + dp[index1-1][index2];
    //             }
    //             else
    //             {
    //                 dp[index1][index2] = dp[index1-1][index2];
    //             }
    //         }
    //     }
    //     return dp[n][m];
    // }

    //Space Optimisation
    //Time Complexity :O(n*m) && Space Complexity : O(m+m)
    // int numDistinct(string s, string t) {
    //     int n = s.size();
    //     int m = t.size();

    //     vector<double> prev(m+1,0),cur(m+1,0);

    //     prev[0] = cur[0] = 1;

    //     for(int index1=1;index1<=n;index1++)
    //     {
    //         for(int index2=1;index2<=m;index2++)
    //         {
    //             if(s[index1-1] == t[index2-1])
    //             {
    //                 cur[index2] = prev[index2-1] + prev[index2];
    //             }
    //             else
    //             {
    //                 cur[index2] = prev[index2];
    //             }
    //         }
    //         prev = cur;
    //     }

    //     return prev[m];
    // }

    //Space Optimisation Using 1D Array
    //Time Complexity :O(n*m) && Space Complexity : O(m+m)
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<double> prev(m+1,0);

        prev[0] = 1;

        for(int index1=1;index1<=n;index1++)
        {
            for(int index2=m;index2>=1;index2--)
            {
                if(s[index1-1] == t[index2-1])
                {
                    prev[index2] = prev[index2-1] + prev[index2];
                }
            }
        }

        return prev[m];
    }
};
