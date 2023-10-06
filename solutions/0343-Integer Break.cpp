class Solution {
public:
    //Time Complexity :O(n * n) && Space Complexity :O(n)
    // int helper(vector<int>& arr,int n,int target)
    // {
    //     if(n == 0)
    //     {
    //         return target;
    //     }

    //     int maxiprod = 0;

    //     for(int i=0;i<arr.size();i++)
    //     {
    //         if(n-arr[i] >= 0)
    //         {
    //             int pick = helper(arr,n-arr[i],target * arr[i]);
    //             maxiprod = max(maxiprod, pick);
    //         }
    //     }

    //     return maxiprod;
    // }

    // int integerBreak(int n) {
    //     vector<int> arr;
    //     for(int i=0;i<n-1;i++)
    //     {
    //         arr.push_back(i+1);
    //     }

    //     return helper(arr,n,1);
    // }

    //Time Complexity :O(n) && Space Complexity :O(n)
    int integerBreak(int n) {
        if(n <= 3)
        {
            return n-1;
        }

        vector<int> dp(n+1, 0);

        dp[2] = 2;
        dp[3] = 3;

        for(int i=4;i<=n;i++)
        {
            dp[i] = max(2 * dp[i-2], 3 * dp[i-3]);
        }

        return dp[n];
    }
};
