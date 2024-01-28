class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    //Time Complexity :O(n * k) && Space Complexity :O(n * k)
    int kInversePairs(int n, int k) {
        int dp[1001][1001];
        
        for(int i=1;i<=n;i++)
        {
            dp[i][0] = 1;

            for(int j=1;j<=min(i * (i-1)/2, k);j++)
            {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;

                if(j >= i)
                {
                    dp[i][j] = (dp[i][j] - dp[i-1][j-i] + MOD) % MOD;
                }
            }
        }

        return dp[n][k];

    }
};
