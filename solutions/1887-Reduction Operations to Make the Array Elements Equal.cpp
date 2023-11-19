class Solution {
public:
    //Time Complexity :O(nlogn) && Space Complexity :O(1)
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = 0;
        for(int i=n-1;i>0;i--)
        {
            if(nums[i-1] != nums[i])
            {
                ans += n-i;
            }
        }

        return ans;
    }
};
