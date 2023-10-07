class Solution {
public:
    //Time Complexity :O(n * m * k) && Space Complexity :O(n * m * k)
    const int MOD = 1e9+7;
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<long long>>> dp(n+1 , vector<vector<long long>>(m+1, vector<long long>(k+1, 0)));

        for(int j=1;j<=m;j++)
        {
            dp[1][j][1] = 1;
        }

        for(int i=1;i<=n;i++) 
        {
            for(int j=1;j<=m;j++) 
            {
                for (int s=0;s<=k;s++) 
                {
                    dp[i][j][s] = (dp[i][j][s] + dp[i-1][j][s] * j) % MOD;

                    if(s > 0)
                    {
                        for(int p=1;p<j;p++)
                        {
                            dp[i][j][s] = (dp[i][j][s] + dp[i-1][p][s-1]) % MOD;
                        }
                    }
                }
            }
        }

        long long  cnt = 0;
        for (int j=1;j<=m;j++) 
        {
            cnt = (cnt + dp[n][j][k]) % MOD;
        }

        return (int)cnt;
    }

};
