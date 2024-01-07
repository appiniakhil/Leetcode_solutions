class Solution {
public:
    //Time Complexity :O(n * n) && Space Complexity :O(n * n)
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();

        vector<unordered_map<long long, int>> dp(n);

        int cnt = 0;
        for(int i=0;i<n;i++) 
        {
            for(int j=0;j<i;j++) 
            {
                long long diff = (long long)nums[i] - nums[j];
                int seqCnt = dp[j].count(diff) ? dp[j][diff] : 0;

                cnt += seqCnt;

                dp[i][diff] += seqCnt + 1;
            }
        }

        return cnt;
    }
};
