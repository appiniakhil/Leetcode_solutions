class Solution {
public:
    //Time Complexity :O(steps * min(steps/2, arrLen)) && Space Complexity :O(steps * min(steps/2, arrLen))
    int MOD = 1e9 + 7;
    int numWays(int steps, int arrLen) {
        int maxi = min(steps / 2, arrLen - 1);

        vector<vector<int>> dp(steps + 1, vector<int>(maxi + 1, 0));

        dp[0][0] = 1;

        for(int i=1;i<=steps;i++) 
        {
            for(int j=0;j<=maxi;j++) 
            {
                dp[i][j] = dp[i - 1][j];
                if(j > 0) 
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                }
                if(j < maxi) 
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
                }
            }
        }

        return dp[steps][0];
    }
};
