class Solution {
public:
    //Time Complexity :O(m * n) && Space Complexity :O(m * n)
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<long long>> dp(m+1, vector<long long>(n+1, INT_MIN));

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                long long currProd = (long long)nums1[i-1] * (long long)nums2[j-1];

                dp[i][j] = max(currProd, max(dp[i-1][j], dp[i][j-1]));

                // If both subsequences end at this position
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + currProd);
            }
        }

        return dp[m][n];
    }
};
