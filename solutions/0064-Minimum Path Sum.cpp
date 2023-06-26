class Solution {
public:

    //Using Recursion
    //Time Complexity :O(2^m * 2^n) && Space Complexity :O(m-1 + n-1)
    // int helper(int i, int j,vector<vector<int>>& grid)
    // {
    //     if(i == 0 && j == 0)
    //     {
    //         return grid[i][j];
    //     }
    //     if(i<0 || j<0)
    //     {
    //         return 1e9;
    //     }

    //     int up = grid[i][j] + helper(i-1,j,grid);
    //     int left = grid[i][j] + helper(i,j-1,grid);

    //     return min(up,left);
    // }

    // int minPathSum(vector<vector<int>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();
        
    //     return helper(m-1,n-1,grid);
    // }

    //Using Memorisation
    //Time Complexity :O(m * n) && Space Complexity :O(m-1 + n-1) + O(m*n)
    // int helper(int i, int j,vector<vector<int>>& grid,vector<vector<int>>& dp)
    // {
    //     if(i == 0 && j == 0)
    //     {
    //         return grid[i][j];
    //     }
    //     if(i<0 || j<0)
    //     {
    //         return 1e9;
    //     }
    //     if(dp[i][j] != -1)
    //     {
    //         return dp[i][j];
    //     }

    //     int up = grid[i][j] + helper(i-1,j,grid,dp);
    //     int left = grid[i][j] + helper(i,j-1,grid,dp);

    //     return dp[i][j] = min(up,left);
    // }

    // int minPathSum(vector<vector<int>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     vector<vector<int>> dp(m, vector<int>(n,-1));

    //     return helper(m-1,n-1,grid,dp);
    // }

    //Using Tabulation
    //Time Complexity :O(m * n) && Space Complexity :O(m * n)
    // int minPathSum(vector<vector<int>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     vector<vector<int>>dp(m,vector<int>(n,0));

    //     for(int i=0;i<m;i++)
    //     {
    //         for(int j=0;j<n;j++)
    //         {
    //             if(i == 0 && j == 0)
    //             {
    //                 dp[i][j] = grid[i][j];
    //             }
    //             else
    //             {
    //                 int up = grid[i][j];
    //                 if(i>0)
    //                 {
    //                     up += dp[i-1][j];
    //                 }
    //                 else
    //                 {
    //                     up += 1e9;
    //                 }
    //                 int left = grid[i][j];
    //                 if(j>0)
    //                 {
    //                     left += dp[i][j-1];
    //                 }
    //                 else
    //                 {
    //                     left += 1e9;
    //                 }
 
    //                 dp[i][j] = min(up,left);
    //             }
    //         }
    //     }

    //     return dp[m-1][n-1];
    // }

    //Space Optimisation
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        vector<int> prev(m,0);
        for(int i=0;i<m;i++)
        {
            vector<int> cur(n,0);
            for(int j=0;j<n;j++)
            {
                if(i == 0 && j == 0)
                {
                    cur[j] = grid[i][j];
                }
                else
                {
                    int up = grid[i][j];
                    if(i>0)
                    {
                        up += prev[j];
                    }
                    else
                    {
                        up += 1e9;
                    }
                    int left = grid[i][j];
                    if(j>0)
                    {
                        left += cur[j-1];
                    }
                    else
                    {
                        left += 1e9;
                    }
 
                    cur[j] = min(up,left);
                }
            }
            prev = cur;
        }

        return prev[n-1];
    }
};
