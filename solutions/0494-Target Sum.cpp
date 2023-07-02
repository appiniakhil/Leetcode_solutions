class Solution {
public:

    //Using Recursion
    //Time Complexity :O(2^n) && Space Complexity :O(n)
    // int helper(int index,int target,vector<int>& nums)
    // {
    //     if(index == 0)
    //     {
    //         if(target == 0 && nums[0] == 0)
    //         {
    //             return 2;
    //         }
    //         if(target == 0 || target == nums[0])
    //         {
    //             return 1;
    //         }
    //         return 0;
    //     }

    //     int notTake = helper(index-1,target,nums);
    //     int take = 0;
    //     if(nums[index] <= target)
    //     {
    //         take += helper(index-1,target-nums[index],nums);
    //     }
    //     return take + notTake;
    // }
    
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     int totalSum = 0;

    //     for(int i=0;i<n;i++)
    //     {
    //         totalSum += nums[i];
    //     }

    //     if(totalSum - target < 0 || (totalSum-target)%2 == 1)
    //     {
    //         return 0;
    //     } 

    //     int s2 = (totalSum - target) / 2;

    //     return helper(n-1,s2,nums);
    // }

    //Using Memorisation
    //Time Complexity : O(n * target) && Space Complexity :O(n * target) + O(n)
    // int helper(int index,int target,vector<int>& nums,vector<vector<int>>& dp)
    // {
    //     if(index == 0)
    //     {
    //         if(target == 0 && nums[0] == 0)
    //         {
    //             return 2;
    //         }
    //         if(target == 0 || target == nums[0])
    //         {
    //             return 1;
    //         }
    //         return 0;
    //     }

    //     int notTake = helper(index-1,target,nums,dp);
    //     int take = 0;
    //     if(nums[index] <= target)
    //     {
    //         take += helper(index-1,target-nums[index],nums,dp);
    //     }
    //     return dp[index][target] = take + notTake;
    // }
    
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     int totalSum = 0;

    //     for(int i=0;i<n;i++)
    //     {
    //         totalSum += nums[i];
    //     }

    //     if(totalSum - target < 0 || (totalSum-target)%2 == 1)
    //     {
    //         return 0;
    //     } 

    //     int s2 = (totalSum - target) / 2;
    //     vector<vector<int>> dp(n,vector<int>(s2 + 1,-1));

    //     return helper(n-1,s2,nums,dp);
    // }

    //Using Tabulation
    //Time Complexity : O(n * target) && Space Complexity :O(n * target)
    // int helper(vector<int> &nums, int target)
    // {
    //     int n = nums.size();

    //     vector<vector<int>> dp(n,vector<int>(target+1,0));
        
    //     if(nums[0] == 0) 
    //     {
    //         dp[0][0] = 2; 
    //     } 
    //     else 
    //     {
    //         dp[0][0] = 1;
    //     }  
        
    //     if(nums[0]!=0 && nums[0]<=target) 
    //     {
    //         dp[0][nums[0]] = 1;
    //     }
        
    //     for(int index=1;index<n;index++)
    //     {
    //         for(int tar=0;tar<=target;tar++)
    //         {
    //             int notTake = dp[index-1][tar];
    //             int take = 0;

    //             if(nums[index]<=tar)
    //             {
    //                 take = dp[index-1][tar-nums[index]];
    //             }
                
    //             dp[index][tar]= notTake + take;
    //         }
    //     }
    //     return dp[n-1][target];
    // }

    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     int totalSum = 0;

    //     for(int i=0;i<n;i++)
    //     {
    //         totalSum += nums[i];
    //     }

    //     if(totalSum - target < 0 || (totalSum-target)%2 == 1)
    //     {
    //         return 0;
    //     }
        
    //     return helper(nums,(totalSum - target) / 2);
    // }

    //Space Optimisation
    //Time Complexity : O(n * target) && Space Complexity :O(target)
    int helper(vector<int> &nums, int target)
    {
        int n = nums.size();

        vector<int> prev(target+1,0),cur(target+1,0);
        
        if(nums[0] == 0) 
        {
            prev[0] = 2; 
        } 
        else 
        {
            prev[0] = 1;
        }  
        
        if(nums[0]!=0 && nums[0]<=target) 
        {
            prev[nums[0]] = 1;
        }
        
        for(int index=1;index<n;index++)
        {
            for(int tar=0;tar<=target;tar++)
            {
                int notTake = prev[tar];
                int take = 0;

                if(nums[index]<=tar)
                {
                    take = prev[tar-nums[index]];
                }
                
                cur[tar]= notTake + take;
            }
            prev = cur;
        }
        return prev[target];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;

        for(int i=0;i<n;i++)
        {
            totalSum += nums[i];
        }

        if(totalSum - target < 0 || (totalSum-target)%2 == 1)
        {
            return 0;
        }
        
        return helper(nums,(totalSum - target) / 2);
    }
};
