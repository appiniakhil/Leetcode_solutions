class Solution {
public:
    // int helper(int n , vector<int> &dp)
    // {
    //     if(n <= 1) return 1;
    //     if(dp[n] != -1) return dp[n];
    //     return dp[n] = helper(n-1,dp) + helper(n-2,dp);
    // }
    int climbStairs(int n) {
        //Using Memorisation
        //Time Complexity :O(n) && Space Complexity :O(n)+O(n)
        // vector<int> dp(n+1,-1);
        // return helper(n,dp);

        //Using Tabulation
        //Time Complexity :O(n) && Space Complexity :O(n)
        // vector<int> dp(n+1,0);
        // dp[0] = dp[1] = 1;
        // for(int i =2;i<=n;i++)
        // {
        //     dp[i] = dp[i-1] + dp[i-2];
        // }
        // return dp[n];

        //Space Optimisation
        //Time Complexity :O(n) && Space Complexity :O(1)
        int prev2 = 1;
        int prev = 1;
        for(int i =2;i<=n;i++)
        {
            int curi = prev2 + prev;
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
};
