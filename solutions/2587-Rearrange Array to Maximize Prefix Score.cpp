class Solution {
public:
    //Time Complexity :O(nlogn) && Space Complexity :O(1)
    int maxScore(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int maxi = 0;
        long long sum = 0;
        for(int i=n-1;i>=0;i--)
        {
            sum += nums[i];
            if(sum > 0)
            {
                maxi++;
            }
        }

        return maxi;
    }
};
