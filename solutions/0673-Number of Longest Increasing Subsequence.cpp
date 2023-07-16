class Solution {
public:

    //Time Complexity :O(n * n) && Space Complecity :O(n)
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n,1), count(n,1);

        int maxi = 1;

        for(int index=0;index<n;index++)
        {
            for(int previndex=0;previndex<index;previndex++)
            {
                if(nums[previndex] < nums[index] && 1 + dp[previndex] > dp[index])
                {
                    dp[index] = 1 + dp[previndex];
                    count[index] = count[previndex];
                }
                else if(nums[previndex] < nums[index] &&  1 + dp[previndex] == dp[index])
                {
                    count[index] += count[previndex];
                }
            }
            maxi = max(maxi,dp[index]);
        }

        int cnt = 0;
        for(int index=0;index<n;index++)
        {
            if(dp[index] == maxi)
            {
                cnt += count[index];
            }
        }

        return cnt;
    }
};
