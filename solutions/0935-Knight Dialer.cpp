class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    int knightDialer(int n) {
        vector<vector<int>> moves = {{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};

        vector<vector<int>> dp(n, vector<int>(10));
        int mod = 1e9 + 7;

        for(int i=0;i<10;i++)
        {
            dp[0][i] = 1;
        }

        for(int i=1;i<n;i++) 
        {
            for(int j=0;j<10;j++) 
            {
                for(int move : moves[j]) 
                {
                    dp[i][j] = (dp[i][j] + dp[i-1][move]) % mod;
                }
            }
        }

        int cnt = 0;
        for(int i=0;i<10;i++)
        {
            cnt = (cnt + dp[n-1][i]) % mod;
        }

        return cnt;
    }
};
