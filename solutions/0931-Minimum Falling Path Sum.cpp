class Solution {
public:

    //Using Recursion
    //Time Complexity :O(3^(m)) && Space Complexity :O(n)
    //Time Limit Exceeded
    // int helper(int i, int j,vector<vector<int>>& matrix,int m)
    // {
    //     if(j>=m || j>=m || i < 0 || j<0)
    //     {
    //         return 1e9;
    //     }
    //     if(i == m-1)
    //     {
    //         return matrix[i][j];
    //     }

    //     int straight = matrix[i][j] + helper(i+1,j,matrix,m);
    //     int leftDiagonal = matrix[i][j] + helper(i+1,j-1,matrix,m);
    //     int rightDiagonal = matrix[i][j] + helper(i+1,j+1,matrix,m);

    //     return min(straight,min(leftDiagonal,rightDiagonal));
    // }

    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int m = matrix.size();
    //     int ans = INT_MAX;
    //     for(int i=0;i<m;i++)
    //     {
    //         ans = min(ans,helper(0,i,matrix,m));
    //     }

    //     return ans;
    // }

    //Using Memorisation
    //Time Complexity : O(m * m) + O(m) && Space Complexity :O(m*m) + O(m)
    //Time Limit Exceeded
    // int helper(int i, int j,vector<vector<int>>& matrix,int m,vector<vector<int>>& dp)
    // {
    //     if(j>=m || i>=m || i < 0 || j<0)
    //     {
    //         return 1e9;
    //     }
    //     if(i == m-1)
    //     {
    //         return matrix[i][j];
    //     }
    //     if(dp[i][j] != -1)
    //     {
    //         return dp[i][j];
    //     }

    //     int straight = matrix[i][j] + helper(i+1,j,matrix,m,dp);
    //     int leftDiagonal = matrix[i][j] + helper(i+1,j-1,matrix,m,dp);
    //     int rightDiagonal = matrix[i][j] + helper(i+1,j+1,matrix,m,dp);

    //     return dp[i][j] = min(straight,min(leftDiagonal,rightDiagonal));
    // }
    
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int m = matrix.size();
    //     int ans = INT_MAX;
    //     vector<vector<int>>dp(m,vector<int>(m,-1));

    //     for(int i=0;i<m;i++)
    //     {
    //         ans = min(ans,helper(0,i,matrix,m,dp));
    //     }

    //     return ans;
    // }

    //Using Tabulation
    //Time Complexity : O(m * m) + O(m) && Space Complexity :O(m*m)
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int m=matrix.size();
    //     int ans=INT_MAX;
    //     vector<vector<int>>dp(m,vector<int>(m,0));
    //     for(int i=0;i<m;i++)
    //     {
    //         dp[m-1][i]=matrix[m-1][i];
    //     }
    //     for(int i=m-2;i>=0;i--)
    //     {
    //         for(int j=0;j<m;j++)
    //         {
    //                 int straight = matrix[i][j] + dp[i+1][j];
    //                 int leftDiagonal = matrix[i][j];
    //                 if(j-1 >= 0)
    //                 {
    //                     leftDiagonal += dp[i+1][j-1];
    //                 }
    //                 else
    //                 {
    //                     leftDiagonal += 1e9;
    //                 }
    //                 int rightDiagonal = matrix[i][j];
    //                 if(j <m-1)
    //                 {
    //                     rightDiagonal += dp[i+1][j+1];
    //                 }
    //                 else
    //                 {
    //                     rightDiagonal += 1e9;
    //                 }

    //                 dp[i][j]=min(straight,min(leftDiagonal,rightDiagonal));
    //         }
    //     }
       
    //     for(int i=0;i<m;i++)
    //     {
    //         ans=min(ans,dp[0][i]);
    //     }
    //      return ans;
    // }
    
    //Space Optimisation
    //Time Complexity : O(m * m) + O(m) && Space Complexity :O(m)
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int ans=INT_MAX;
        vector<int> front(m,0);
        for(int i = 0; i < m; i++) 
        {
            front[i] = matrix[m - 1][i];
        }
        for(int i=m-2;i>=0;i--)
        {
            vector<int> cur(m,0);
            for(int j=0;j<m;j++)
            {
                    int straight = matrix[i][j] + front[j];
                    int leftDiagonal = matrix[i][j];
                    if(j-1 >= 0)
                    {
                        leftDiagonal += front[j-1];
                    }
                    else
                    {
                        leftDiagonal += 1e9;
                    }
                    int rightDiagonal = matrix[i][j];
                    if(j <m-1)
                    {
                        rightDiagonal += front[j+1];
                    }
                    else
                    {
                        rightDiagonal += 1e9;
                    }
                    cur[j]=min(straight,min(leftDiagonal,rightDiagonal));
            }
            front = cur;
        }
       
        for(int i=0;i<m;i++)
        {
            ans=min(ans,front[i]);
        }
         return ans;
    }
};
