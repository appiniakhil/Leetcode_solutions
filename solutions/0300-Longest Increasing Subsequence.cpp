class Solution {
public:

    //Using Recursion
    //Time Complexity :O(2^n) && Space Complexity :O(n)
    // int helper(int index,int previndex,vector<int>& nums)
    // {
    //     int n = nums.size();

    //     if(index == n)
    //     {
    //         return 0;
    //     }

    //     int notPick = helper(index+1,previndex,nums);

    //     int pick = 0;
    //     if(previndex == -1 || nums[index] > nums[previndex])
    //     {
    //         pick = 1 + helper(index+1,index,nums);
    //     }

    //     return max(notPick, pick);
    // }

    // int lengthOfLIS(vector<int>& nums) {
    //     return helper(0,-1,nums);
    // }


    //Using Memorisation
    //Time Complexity :O(n * n) && Space Complexity :O(n * n) + O(n)
    // int helper(int index,int previndex,vector<int>& nums,vector<vector<int>>& dp)
    // {
    //     int n = nums.size();

    //     if(index == n)
    //     {
    //         return 0;
    //     }

    //     if(dp[index][previndex+1] != -1)
    //     {
    //         return dp[index][previndex+1];
    //     }

    //     int notPick = helper(index+1,previndex,nums,dp);

    //     int pick = 0;
    //     if(previndex == -1 || nums[index] > nums[previndex])
    //     {
    //         pick = 1 + helper(index+1,index,nums,dp);
    //     }

    //     return dp[index][previndex+1] = max(notPick, pick);
    // }

    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();

    //     vector<vector<int>> dp(n,vector<int>(n+1,-1));
    //     return helper(0,-1,nums,dp);
    // }

    //Using Tabulation
    //Time Complexity :O(n * n) && Space Complexity :O(n * n)
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();

    //     vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    //     for(int index=n-1;index>=0;index--)
    //     {
    //         for(int previndex = index-1;previndex>=-1;previndex--)
    //         {
    //             int notPick = dp[index+1][previndex+1];

    //             int pick = 0;
    //             if(previndex == -1 || nums[index] > nums[previndex])
    //             {
    //                 pick = 1 + dp[index+1][index+1];
    //             }

    //             dp[index][previndex+1] = max(notPick, pick);
    //         }
    //     }

    //     return dp[0][0];
    // }

    //Using Space Optimisation
    //Time Complexity :O(n * n) && Space Complexity :O(1)
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();

    //     vector<int> cur(n+1,0), front(n+1,0);

    //     for(int index=n-1;index>=0;index--)
    //     {
    //         for(int previndex = index-1;previndex>=-1;previndex--)
    //         {
    //             int notPick = front[previndex+1];

    //             int pick = 0;
    //             if(previndex == -1 || nums[index] > nums[previndex])
    //             {
    //                 pick = 1 + front[index+1];
    //             }

    //            cur[previndex+1] = max(notPick, pick);
    //         }

    //         front = cur;
    //     }

    //     return front[0];
    // }

    //Using 1d dp
    //Time Complexity :O(n * n) && Space Complexity :O(n)
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n,1);

        int maxi = 1;

        for(int index=1;index<n;index++)
        {
            for(int previndex=0;previndex<index;previndex++)
            {
                if(nums[previndex] < nums[index])
                {
                    dp[index] = max(dp[index], 1 + dp[previndex]);
                }

                maxi = max(maxi,dp[index]);
            }
        }

        return maxi;
    }
};
