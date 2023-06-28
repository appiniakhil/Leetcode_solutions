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
    //Time Complexity :O(n * sum) + O(m) && Space Complexity :O(n * sum) + O(n)
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

    //Using Tabulation
    //Time Complexity :O(n * sum) + O(n) &&  Space Complexity :O(n * sum)
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
    //     else
    //     {
    //         int sum = totalSum/2;
    //         vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        
    //         for(int i=0;i<n;i++)
    //         {
    //             dp[i][0] = true;
    //         }
            
    //         if(nums[0]<=sum)
    //         {
    //             dp[0][nums[0]] = true;
    //         }
            
    //         for(int index=1;index<n;index++)
    //         {
    //             for(int target=1;target<=sum;target++)
    //             {
                    
    //                 bool notTake = dp[index-1][target];
            
    //                 bool take = false;
    //                 if(nums[index]<=target)
    //                 {
    //                     take = dp[index-1][target-nums[index]];
    //                 }
                
    //                 dp[index][target]= notTake || take;
    //             }
    //         }
            
    //         return dp[n-1][sum];
    //     }
    // }

    //Space Optimisation
    //Time Complexity :O(n * sum) + O(n) &&  Space Complexity :O(sum)
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i=0;i<n;i++)
        {
            totalSum += nums[i];
        }
        if(totalSum % 2)
        {
            return false;
        }
        else
        {
            int sum = totalSum/2;
            vector<bool> prev(sum+1, false);
        
            prev[0] = true;
        
            if(nums[0]<=sum)
            {
                prev[nums[0]] = true;
            }
            
            for(int index=1;index<n;index++)
            {
                vector<bool> cur(sum+1,false);
                cur[0] = true;
                for(int target=1;target<=sum;target++)
                {
                    bool notTake = prev[target];
            
                    bool take = false;
                    if(nums[index]<=target)
                    {
                        take = prev[target-nums[index]];
                    }
                
                    cur[target]= notTake || take;
                }
                prev = cur;
            }
            
            return prev[sum];
        }
    }
};
