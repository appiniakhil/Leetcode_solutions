class Solution {
public:
    //Time Complexity :O(n*n*k) && Space Complexity :O(n*k)
    int getlength(int cnt)
    {
        if(cnt == 1)
        {
            return 1;
        }
        else if(cnt < 10)
        {
            return 2;
        }
        else if(cnt < 100)
        {
            return 3;
        }
        else
        {
            return 4;
        }
    }

    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();

        int dp[n+1][k+1];

        for(int i=n;i>=0;i--)
        {
            for(int j=0;j<=k;j++)
            {
                if(i == n)
                {
                    dp[n][j] = 0;
                    continue;
                }

                if(j > 0)
                {
                    dp[i][j] = dp[i+1][j-1];
                }
                else
                {
                    dp[i][j] = INT_MAX;
                }

                int pos_del=j, cnt=0;
                for(int e=i;e<n && pos_del>=0;e++)
                {
                    if(s[e] == s[i])
                    {
                        cnt++;

                        dp[i][j] = min(dp[i][j], getlength(cnt) + dp[e+1][pos_del]);
                    }
                    else
                    {
                        pos_del--;
                    }
                }
            }
        }

        return dp[0][k];
    }
};
