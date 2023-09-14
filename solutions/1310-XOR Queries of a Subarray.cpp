class Solution {
public:
    //Time Complexity :O(n * m) && Space Complexity :O(1) where n is the number of queries and m is the maximum subarray size within the queries
    // int helper(vector<int>& arr, int left, int right)
    // {
    //     int xorop = arr[left];
    //     for(int i=left+1;i<=right;i++)
    //     {
    //         xorop ^= arr[i];
    //     }

    //     return xorop;
    // }

    // vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    //     vector<int> ans;
    //     int n = queries.size();

    //     for(int i=0;i<n;i++)
    //     {
    //         ans.push_back(helper(arr,queries[i][0],queries[i][1]));
    //     }

    //     return ans;
    // }

    //Time Complexity :O(n + q) && Space Complexity :O(n) where n is the size of the input array and q is the number of queries.
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();

        vector<int> prefixXor(n+1, 0);

        for(int i=0;i<n;i++)
        {
            prefixXor[i+1] = prefixXor[i] ^ arr[i];
        }

        int m = queries.size();

        vector<int> ans(m, 0);

        for(int i=0;i<m;i++)
        {
            int left = queries[i][0];
            int right = queries[i][1];

            ans[i] = prefixXor[right+1] ^ prefixXor[left];
        }

        return ans;
    }
};
