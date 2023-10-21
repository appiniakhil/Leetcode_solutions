class Solution {
public:
    //Time Complexity :O(nlogn) && Space Complexity :O(n)
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> dp(n);
        priority_queue<pair<int, int>> pq;

        int ans = INT_MIN;
        for(int i=0;i<n;i++)
        {
            while(!pq.empty() && pq.top().second < i - k)
            {
                pq.pop();
            }

            dp[i] = nums[i];
            if(!pq.empty())
            {
                dp[i] = max(dp[i], pq.top().first + nums[i]);
            }

            ans = max(ans, dp[i]);
            pq.push({dp[i], i});
        }

        return ans;
    }
};
