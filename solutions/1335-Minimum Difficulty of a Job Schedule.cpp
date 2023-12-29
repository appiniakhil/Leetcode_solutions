class Solution {
public:
    //Time Complexity :O(d*n*n) && Space Complexity :O(d*n)
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        if(n < d) 
        {
            return -1;
        }

        vector<vector<int>> dp(d + 1, vector<int>(n + 1, INT_MAX / 2));

        dp[0][0] = 0;

        for(int day = 1; day <= d; ++day) 
        {
            for(int i = 1; i <= n; ++i) 
            {
                int max_difficulty = 0;

                for(int j = i; j > 0; --j) 
                {
                    max_difficulty = max(max_difficulty, jobDifficulty[j - 1]);
                    if(dp[day - 1][j - 1] != INT_MAX / 2) 
                    {
                        dp[day][i] = min(dp[day][i], dp[day - 1][j - 1] + max_difficulty);
                    }
                }
            }
        }

        int result = dp[d][n];

        return (result == INT_MAX / 2) ? -1 : result;
    }
};
