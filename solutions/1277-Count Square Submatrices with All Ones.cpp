class Solution {
public:

    //Using Tabulation
    //Time Complexity :O(n * m) && Space Complexity :O(n * m)
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int> (m,0));

        for(int index1=0;index1<n;index1++)
        {
            dp[index1][0] = matrix[index1][0];
        }

        for(int index2=0;index2<m;index2++)
        {
            dp[0][index2] = matrix[0][index2];
        }

        for(int index1=1;index1<n;index1++)
        {
            for(int index2=1;index2<m;index2++)
            {
                if(matrix[index1][index2] == 0)
                {
                    dp[index1][index2] = 0;
                }
                else
                {
                    dp[index1][index2] = 1 + min(dp[index1-1][index2],min(dp[index1-1][index2-1],dp[index1][index2-1]));
                }
            }
        }

        int res = 0;
        for(int index1=0;index1<n;index1++)
        {
            for(int index2=0;index2<m;index2++)
            {
                res += dp[index1][index2];
            }
        }

        return res;
    }
};
