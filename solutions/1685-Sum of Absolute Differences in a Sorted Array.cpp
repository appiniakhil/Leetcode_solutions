class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixSum(n+1);

        for(int i=0;i<n;i++)
        {
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }

        vector<int> res(n);

        for(int i=0;i<n;i++)
        {
            res[i] = nums[i]*i - prefixSum[i] + prefixSum[n] - prefixSum[i] - nums[i]*(n-i);
        }

        return res;
    }
};
