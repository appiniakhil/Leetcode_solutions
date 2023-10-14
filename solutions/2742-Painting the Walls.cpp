class Solution {
public:
    int helper(int index, int costVal,vector<int>& cost, vector<int>& time, vector<vector<int>>& dp)
    {
        int n = cost.size();
        if(costVal <= 0)
        {
            return 0;
        }

        if(index >= n)
        {
            return 1e9;
        }

        if(dp[index][costVal] != -1)
        {
            return dp[index][costVal];
        }
        int notfree = cost[index] + helper(index+1, costVal - time[index]-1, cost, time, dp);

        int free = helper(index+1, costVal, cost, time, dp);

        return dp[index][costVal] = min(notfree, free);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return helper(0, n, cost, time, dp);
    }
};
