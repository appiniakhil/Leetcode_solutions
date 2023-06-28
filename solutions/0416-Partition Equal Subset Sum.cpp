class Solution {
public:

    //Using recursion
    //Time Complexity :O(2^n) && Space Complexity :O(n)
    //Time Limit Exceeded
    // bool helper(int index, int sum, vector<int>& nums)
    // {
    //     if(sum == 0)
    //     {
    //         return true;
    //     }
    //     if(index == 0)
    //     {
    //         return (nums[0] == sum);
    //     }


    //     bool notTake = helper(index-1,sum,nums);

    //     bool take = false;
    //     if(sum >= nums[index])
    //     {
    //         take = helper(index-1,sum-nums[index],nums);
    //     }

    //     return take | notTake;
    // }

    // bool canPartition(vector<int>& nums) {
    //     int n = nums.size();
    //     int totalSum = 0;
    //     for(int i=0;i<n;i++)
    //     {
    //         totalSum += nums[i];
    //     }
    //     if(totalSum % 2)
    //     {
    //         return false;
    //     }
    //     int sum = totalSum/2;
    //     return helper(n-1,sum,nums);
    // }


    //Using Memorisation
    //Time Complexity :O(n * sum) && Space Complexity :O(n * sum) + O(n)
    // bool helper(int index, int sum, vector<int>& nums,vector<vector<int>>& dp)
    // {
    //     if(sum == 0)
    //     {
    //         return true;
    //     }
    //     if(index == 0)
    //     {
    //         return (nums[0] == sum);
    //     }

    //     if(dp[index][sum] != -1)
    //     {
    //         return dp[index][sum];
    //     }
    //     bool notTake = helper(index-1,sum,nums,dp);

    //     bool take = false;
    //     if(sum >= nums[index])
    //     {
    //         take = helper(index-1,sum-nums[index],nums,dp);
    //     }

    //     return dp[index][sum] = take | notTake;
    // }

    // bool canPartition(vector<int>& nums) {
    //     int n = nums.size();
    //     int totalSum = 0;
    //     for(int i=0;i<n;i++)
    //     {
    //         totalSum += nums[i];
    //     }
    //     if(totalSum % 2)
    //     {
    //         return false;
    //     }
    //     int sum = totalSum/2;

    //     vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    //     return helper(n-1,sum,nums,dp);
    // }

};
