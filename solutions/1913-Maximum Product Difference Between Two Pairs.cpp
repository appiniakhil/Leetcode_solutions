class Solution {
public:
    //Time Complexity :O(nlogn) && Space Complexity :O(1)
    // int maxProductDifference(vector<int>& nums) {
    //     int n = nums.size();
    //     sort(nums.begin(), nums.end());

    //     return nums[n-1] * nums[n-2] - nums[0] * nums[1];
    // }

    //Time Complexity :O(n) && Space Complexity :O(1)
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        int maxi1 = INT_MIN;
        int maxi2 = INT_MIN;
        int mini1 = INT_MAX;
        int mini2 = INT_MAX;

        for(int i=0;i<n;i++)
        {
            if(nums[i] >= maxi1)
            {
                maxi2 = maxi1;
                maxi1 = nums[i];
            }
            else if(nums[i] >= maxi2)
            {
                maxi2 = nums[i];
            }

            if(nums[i] <= mini1)
            {
                mini2 = mini1;
                mini1 = nums[i];
            }
            else if(nums[i] <= mini2)
            {
                mini2 = nums[i];
            }
        }

        return maxi1 * maxi2 - mini1 * mini2;
    }
};
