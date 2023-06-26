class Solution {
public:

    //Using Recursion
    //Time Complexity :O(2^m * 2^n) & Space Complexity:O(m-1 + n-1)
    //Time Limit Exceeded
    // int helper(int i, int j)
    // {
    //     if(i == 0 && j == 0)
    //     {
    //         return 1;
    //     }
    //     if(i < 0 || j < 0)
    //     {
    //         return 0;
    //     }
        
    //     int up = helper(i-1,j);
    //     int left = helper(i, j-1);

    //     return up + left;
    // }

    // int uniquePaths(int m, int n) {
    //     return helper(m-1,n-1);    
    // }

    //Using Memorisation
    //Time Complexity :O(n*m) & Space Complexity: O(m-1 + n-1) + O(n*m)
    // int helper(int i, int j,vector<vector<int>> &dp)
    // {
    //     if(i == 0 && j == 0)
    //     {
    //         return 1;
    //     }
    //     if(i < 0 || j < 0)
    //     {
    //         return 0;
    //     }
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int up = helper(i-1,j,dp);
    //     int left = helper(i, j-1,dp);

    //     return dp[i][j] = up + left;
    // }

    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m, vector<int>(n,-1));
    //     return helper(m-1,n-1,dp);    
    // }

    //Using Tabulation
    //Time Complexity :O(m*n) && Space Complexity : O(m*n)
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    int left = 0;
                    int up = 0;
                    if(i>0) 
                    {
                        up = dp[i-1][j];
                    }
                    if(j>0)
                    {
                        left = dp[i][j-1];
                    }
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];    
    }
};

