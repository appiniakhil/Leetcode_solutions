class Solution {
public:

    //Sliding Window Approach
    //Time Complexity :O(n) && Space Complexity :O(1)
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        
        int j = 0;
        int mini = INT_MAX;
        for(int i=0;i<n;i++)
        {
            target -= nums[i];
            while(target <= 0)
            {
                mini = min(mini, i-j+1);
                target += nums[j];
                j++;
            }
        }

        if(mini != INT_MAX)
        {
            return mini;
        }

        return 0;
    }
};
