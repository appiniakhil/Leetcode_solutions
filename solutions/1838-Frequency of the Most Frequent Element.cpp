class Solution {
public:
    //Time Complexity :O(nlogn) && Space Complexity :O(1)
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        long sum = 0;
        int res = 1, j=0;

        for(int i=0;i<n;i++)
        {
            sum += nums[i];

            while(sum + k < (long)nums[i] * (i-j+1))
            {
                sum -= nums[j];
                j++;
            }

            res = max(res, i-j+1);
        }

        return res;
    }
};
