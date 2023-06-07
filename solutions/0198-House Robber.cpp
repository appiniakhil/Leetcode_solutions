class Solution {
public:
    // int helper(int ind, vector<int> &nums)
    // {
    //     if(ind == 0) return nums[ind];
    //     if(ind < 0) return 0;

    //     int pick = nums[ind] + helper(ind-2, nums);
    //     int notpick = helper(ind-1, nums);

    //     return max(pick, notpick);
    // }

    // int helper1(int ind, vector<int> &nums, vector<int> &dp)
    // {
    //     if(ind == 0) return nums[ind];
    //     if(ind < 0) return 0;
    //     if(dp[ind] != -1) return dp[ind];
    //     int pick = nums[ind] + helper1(ind-2, nums, dp);
    //     int notpick = helper1(ind-1, nums, dp);

    //     return dp[ind] = max(pick, notpick);
    // }

    int rob(vector<int>& nums) {
        //Using Recursion
        //Time Complexity :O(2^n) && Space Complexity :O(n)
        //Time Limit Exceeded
        // int n = nums.size();
        // return helper(n-1, nums);

        //Using Memorisation
        //Time Complexity :O(n) && Space Complexity :O(n) + O(n)
        // int n = nums.size();
        // vector<int> dp(n+1,-1);
        // return helper1(n-1, nums, dp);

        //Using Tabulation
        //Time Complexity :O(n) && Space Complexity :O(n)
        // int n = nums.size();
        // vector<int> dp(n,0);
        // dp[0] = nums[0];
        // for(int i =1;i<n;i++)
        // {
        //     int pick = nums[i];
        //     if(i>1) 
        //         pick += dp[i-2];
        //     int notpick = dp[i-1];
        //     dp[i] = max(pick, notpick);
        // }
        // return dp[n-1];

        //Space Optimisation
        //Time Complexity :O(n) && Space Complexity :O(1)
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for(int i =1;i<n;i++)
        {
            int pick = nums[i];
            if(i>1) 
                pick += prev2;
            int notpick = prev;
            int curi = max(pick, notpick);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
};
