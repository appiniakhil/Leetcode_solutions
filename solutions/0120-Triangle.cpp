class Solution {
public:

    //Using Recursion
    //Time Complexity : O(2^(n(n+1)/2))) && Space Complexity : O(n)
    // int helper(int i, int j,vector<vector<int>>& triangle)
    // {
    //     int m = triangle.size();
    //     if(i == m-1)
    //     {
    //         return triangle[m-1][j];
    //     }

    //     int down = triangle[i][j] + helper(i+1,j,triangle);
    //     int right = triangle[i][j] + helper(i+1,j+1,triangle);

    //     return min(down,right);
    // }
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int m = triangle.size();
    //     int n = triangle[0].size();

    //     return helper(0,0,triangle);
    // }

    //Using Memorisation
    //Time Complexity O(m * m) && Space Complexity :O(m * m) where m is the no of rows
    // int helper(int i, int j,vector<vector<int>>& triangle,int m,vector<vector<int>>& dp)
    // {
    //     if(i == m-1)
    //     {
    //         return triangle[m-1][j];
    //     }
    //     if(dp[i][j] != -1) 
    //     {
    //         return dp[i][j];
    //     }
    //     int down = triangle[i][j] + helper(i+1,j,triangle,m,dp);
    //     int right = triangle[i][j] + helper(i+1,j+1,triangle,m,dp);

    //     return dp[i][j] = min(down,right);
    // }

    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int m = triangle.size();
    //     vector<vector<int>>dp(m, vector<int>(m,-1));
    //     return helper(0,0,triangle,m,dp);
    // }

    //Using Tabulation
    //Time Complexity O(m * m) && Space Complexity :O(m * m) where m is the no of rows
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int m = triangle.size();
    //     vector<vector<int>>dp(m, vector<int>(m,0));
    //     for(int j = 0;j<m;j++)
    //     {
    //         dp[m-1][j] = triangle[m-1][j];
    //     }
    //     for(int i =m-2;i>=0;i--)
    //     {
    //         for(int j=i;j>=0;j--)
    //         {
    //             int down = triangle[i][j] + dp[i+1][j];
    //             int right = triangle[i][j] + dp[i+1][j+1];

    //             dp[i][j] = min(down,right);
    //         }
    //     }
    //     return dp[0][0];
    // }

    //Space Optimisation
    //Time Complexity O(m * m) && Space Complexity :O(m) where m is the no of rows
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<int>front(m,0), cur(m,0);
        for(int j = 0;j<m;j++)
        {
            front[j] = triangle[m-1][j];
        }
        for(int i =m-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int down = triangle[i][j] + front[j];
                int right = triangle[i][j] + front[j+1];

                cur[j] = min(down,right);
            }
            front = cur;
        }
        return front[0];
    }

};
