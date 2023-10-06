class Solution {
public:
    //Time Complexity :O(m * n) && Space Complexity :O(m * n)
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;

        // Handle patterns like "a*", "a*bc*", "a*b*c*", etc.
        for(int j=1;j<=n;j++)
        {
            if(p[j-1] == '*')
            {
                dp[0][j] = dp[0][j-2];
            }
        }


        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1] == p[j-1] || p[j-1] == '.')
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*')
                {
                    dp[i][j] = dp[i][j-2] || (dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
                }
            }
        }

        return dp[m][n];
    }
};
