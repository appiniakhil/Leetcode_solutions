class Solution {
public:

    // Using Recursion
    // Time Complexity : O(2^n) && Space Complexity :O(n)
    // int helper(int index, vector<int>& cost)
    // {
    //     int n = cost.size();

    //     if(index <= 1)
    //     {
    //         return 0;
    //     }   

    //     int step1 = cost[index-1] + helper(index-1,cost);

    //     int step2 = cost[index-2] + helper(index-2,cost);

    //     return min(step1, step2);
    // }
    
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n = cost.size();

    //     return helper(n, cost);
    // }

    //Using Recursion
    //Time Complexity :O(n) && Space Complexity :O(n) + O(n)
    // int helper(int index, vector<int>& cost,vector<int>& dp)
    // {
    //     int n = cost.size();

    //     if(index <= 1)
    //     {
    //         return 0;
    //     }   

    //     if(dp[index] != -1)
    //     {
    //         return dp[index];
    //     }

    //     int step1 = cost[index-1] + helper(index-1,cost,dp);

    //     int step2 = cost[index-2] + helper(index-2,cost,dp);

    //     return dp[index] = min(step1, step2);
    // }
    
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n = cost.size();

    //     vector<int> dp(n+1,-1);

    //     return helper(n, cost,dp);
    // }

    //Using Tabulation
    //Time Complexity :O(n) && Space Complexity :O(n)
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n = cost.size();

    //     vector<int> dp(n+1, 0);

    //     for(int index=2;index<=n;index++)
    //     {

    //         int step1 = cost[index-1] + dp[index-1];

    //         int step2 = cost[index-2] + dp[index-2];

    //         dp[index] = min(step1, step2);
    //     }
    //     return dp[n];
    // }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int prev2 = 0;
        int prev = 0;

        for(int index=2;index<=n;index++)
        {

            int step1 = cost[index-1] + prev;

            int step2 = cost[index-2] + prev2;

            int curi = min(step1, step2);

            prev2 = prev;
            prev = curi;
        }

        return prev;
    }
};
