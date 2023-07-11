class Solution {
public:
    //Using Tabulation
    //Time Complexity :O(n*n) && Space Complexity :O(n*n)
    // int helper(string& s1, string &s2)
    // {
    //     int n = s1.size();
    //     int m = s2.size();

    //     vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

    //     for(int i=0;i<=n;i++)
    //     {
    //         dp[i][0] = 0;
    //     }

    //     for(int j=0;j<=m;j++)
    //     {
    //         dp[0][j] = 0;
    //     }

    //     for(int i=1;i<=n;i++)
    //     {
    //         for(int j=1;j<=m;j++)
    //         {
    //             if(s1[i-1] == s2[j-1])
    //             {
    //                 dp[i][j] = 1 + dp[i-1][j-1];
    //             }
    //             else
    //             {
    //                 dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    //             }
    //         }
    //     }

    //     return dp[n][m];
    // }

    // int minInsertions(string s) {
    //     int n = s.size();
    //     string s2 = s;
    //     reverse(s.begin(),s.end());

    //     return n - helper(s,s2);
    // }

    //Space Optimisation
    //Time Complexity :O(n*m) && Space Complexity :O(m)
    int helper(string& s1, string &s2)
    {
        int n = s1.size();
        int m = s2.size();

        vector<int> prev(m+1,0), cur(m+1,0);

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    cur[j] = 1 + prev[j-1];
                }
                else
                {
                    cur[j] = max(prev[j],cur[j-1]);
                }
            }
            prev = cur;
        }

        return prev[m];
    }

    int minInsertions(string s) {
        int n = s.size();
        string s2 = s;
        reverse(s.begin(),s.end());

        return n - helper(s,s2);
    }

};
