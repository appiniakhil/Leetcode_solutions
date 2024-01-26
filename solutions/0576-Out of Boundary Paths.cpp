class Solution {
    //Time Complexity :O(m * n * maxMove) && Space Complexity :O(m * n * maxMove)
private:
    const int MOD = 1e9 + 7;
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(maxMove+1, vector<vector<int>> (m, vector<int> (n)));

        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for(int move=1;move<=maxMove;move++)
        {
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    for(auto& d : dir)
                    {
                        int ni = i + d[0];
                        int nj = j + d[1];

                        if(ni >= 0 && ni < m && nj >= 0 && nj < n)
                        {
                            dp[move][i][j] = (dp[move][i][j] + dp[move-1][ni][nj]) % MOD;
                        }
                        else
                        {
                            dp[move][i][j] = (dp[move][i][j] + 1) % MOD;
                        }
                    }
                }
            }
        }

        return dp[maxMove][startRow][startColumn];
    }
};
