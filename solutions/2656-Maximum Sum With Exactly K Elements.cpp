class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    int maximizeSum(vector<int>& nums, int k) {
        int maxi = 0;
        int n = nums.size();

        for(int i =0;i<n;i++)
        {
            maxi = max(maxi, nums[i]);
        }

        return k*(maxi) + (k * (k - 1))/2;
    }
};
