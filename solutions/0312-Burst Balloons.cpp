class Solution {
public:

    //Using Recursion
    //Time Complexity :exponential && Space Complexity :O(n * n)
    // int helper(int index1,int index2,vector<int>& nums)
    // {
    //     if(index1 > index2)
    //     {
    //         return 0;
    //     }

    //     int maxi = INT_MIN;

    //     for(int ind=index1;ind<=index2;ind++)
    //     {
    //         int coins = nums[index1-1] * nums[ind] * nums[index2+1] + helper(index1,ind-1,nums) + helper(ind+1,index2,nums);

    //         maxi = max(maxi, coins);
    //     }

    //     return maxi;
    // }

    // int maxCoins(vector<int>& nums) {
    //     int n = nums.size();

    //     nums.push_back(1);

    //     nums.insert(nums.begin(), 1);

    //     return helper(1,n,nums);
    // }


    //Using Memorisation
    //Time Complexity :O(n * n * n) && Space Complexity :O(n * n)  + O(n)
    // int helper(int index1,int index2,vector<int>& nums, vector<vector<int>>& dp)
    // {
    //     if(index1 > index2)
    //     {
    //         return 0;
    //     }

    //     if(dp[index1][index2] != -1)
    //     {
    //         return dp[index1][index2];
    //     }

    //     int maxi = INT_MIN;

    //     for(int ind=index1;ind<=index2;ind++)
    //     {
    //         int coins = nums[index1-1] * nums[ind] * nums[index2+1] + helper(index1,ind-1,nums,dp) + helper(ind+1,index2,nums,dp);

    //         maxi = max(maxi, coins);
    //     }

    //     return dp[index1][index2] = maxi;
    // }

    // int maxCoins(vector<int>& nums) {
    //     int n = nums.size();

    //     nums.push_back(1);

    //     nums.insert(nums.begin(), 1);

    //     vector<vector<int>> dp(n+1, vector<int> (n+1,-1));

    //     return helper(1,n,nums,dp);
    // }

    //Using Tabulation
    //Time Complexity :O(n * n * n) && Space Complexity :O(n * n)
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.push_back(1);

        nums.insert(nums.begin(), 1);

        vector<vector<int>> dp(n+2, vector<int> (n+2,0));

        for(int index1=n;index1>=1;index1--)
        {
            for(int index2=1;index2<=n;index2++)
            {
                if(index1 > index2)
                {
                    continue;
                }

                int maxi = INT_MIN;

                for(int ind=index1;ind<=index2;ind++)
                {
                    int coins = nums[index1-1] * nums[ind] * nums[index2+1] + dp[index1][ind-1] + dp[ind+1][index2];

                    maxi = max(maxi, coins);
                }

                dp[index1][index2] = maxi;
            }
        }


        return dp[1][n];
    }

};
