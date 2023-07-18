class Solution {
public:

    //Using Recursion
    //Time Complexity :O(2^n) && Space Complexity :O(n)
    //Time Limit Exceeded
    // int helper(int index)
    // {
    //     if(index <= 1)
    //     {
    //         return 1;
    //     }

    //     int oneStep = helper(index-1);
    //     int secondStep = helper(index-2);

    //     return oneStep + secondStep;
    // }

    // int climbStairs(int n) {
    //     return helper(n);
    // }

    //Using Memorisation
    //Time Complexity :O(n) && Space Complexity :O(n) + O(n)
    // int helper(int index,vector<int>& dp)
    // {
    //     if(index <= 1)
    //     {
    //         return 1;
    //     }

    //     if(dp[index] != -1)
    //     {
    //         return dp[index];
    //     }

    //     int oneStep = helper(index-1,dp);
    //     int secondStep = helper(index-2,dp);

    //     return dp[index] = oneStep + secondStep;
    // }

    // int climbStairs(int n) {
    //     vector<int> dp(n+1,-1);

    //     return helper(n,dp);
    // }

    //Using Tabulation
    //Time Complexity :O(n) && Space Complexity :O(n)
    // int climbStairs(int n) {
    //     vector<int> dp(n+1, 0);

    //     dp[0] = dp[1] = 1;

    //     for(int index=2;index<=n;index++)
    //     {
    //         int oneStep = dp[index-1];
    //         int secondStep = dp[index-2];

    //         dp[index] = oneStep + secondStep;
    //     }

    //     return dp[n];
    // }

    //Using Space Optimisation
    //Time Complexity :O(n) && Space Complexity :O(1)
    int climbStairs(int n) {
        int prev2 = 1, prev = 1;

        for(int index=2;index<=n;index++)
        {
            int oneStep = prev;
            int secondStep = prev2;

            int curi = oneStep + secondStep;

            prev2 = prev;
            prev = curi;
        }

        return prev;
    }
};
