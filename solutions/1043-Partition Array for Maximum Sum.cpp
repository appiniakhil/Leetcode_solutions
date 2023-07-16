class Solution {
public:

    //Using Recursion
    //Time Complexity :exponential && Space Complexity :O(n) + O(n) 
    //Time Limit Exceeded
    // int helper(int index1,vector<int>& arr,int k)
    // {
    //     int n = arr.size();
    //     if(index1 == n)
    //     {
    //         return 0;
    //     }

    //     int maxi = INT_MIN;
    //     int len = 0,res=INT_MIN;

    //     for(int index2 = index1;index2<min(n,index1+k);index2++)
    //     {
    //         len++;
    //         maxi = max(maxi, arr[index2]);

    //         int sum = (len * maxi) + helper(index2+1,arr,k);

    //         res = max(res, sum);
    //     }

    //     return res;
    // }

    // int maxSumAfterPartitioning(vector<int>& arr, int k) {
    //     return helper(0,arr,k);
    // }

    //Using Memorisation
    //Time Complexity :O(n) * O(k) && Space Complexity :O(n) + O(n)
    // int helper(int index1,vector<int>& arr,int k,vector<int>& dp)
    // {
    //     int n = arr.size();
    //     if(index1 == n)
    //     {
    //         return 0;
    //     }

    //     if(dp[index1] != -1)
    //     {
    //         return dp[index1];
    //     }

    //     int maxi = INT_MIN;
    //     int len = 0,res=INT_MIN;

    //     for(int index2 = index1;index2<min(n,index1+k);index2++)
    //     {
    //         len++;
    //         maxi = max(maxi, arr[index2]);

    //         int sum = (len * maxi) + helper(index2+1,arr,k,dp);

    //         res = max(res, sum);
    //     }

    //     return dp[index1] = res;
    // }

    // int maxSumAfterPartitioning(vector<int>& arr, int k) {
    //     int n = arr.size();

    //     vector<int> dp(n+1,-1);

    //     return helper(0,arr,k,dp);
    // }

    //Using Tabulation
    //Time Complexity :O(n) * O(k) && Space Complexity :O(k)
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> dp(n+1, 0);

        for(int index1=n-1;index1>=0;index1--)
        {
            int maxi = INT_MIN;
            int len = 0,res=INT_MIN;

            for(int index2 = index1;index2<min(n,index1+k);index2++)
            {
                len++;
                maxi = max(maxi, arr[index2]);

                int sum = (len * maxi) + dp[index2+1];

                res = max(res, sum);
            }

            dp[index1] = res;
        }

        return dp[0];
    }
};
