class Solution {
public:
    //Time Complexity :O(nlogn) && Space Complexity :O(1)
    int minPairSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int maxi = INT_MIN;
        int i=0,j=n-1;

        while(i < j)
        {
            maxi = max(maxi, nums[i] + nums[j]);
            i++;
            j--;
        }

        return maxi;
    }
};
