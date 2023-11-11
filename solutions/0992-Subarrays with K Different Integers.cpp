class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    int helper(vector<int>& nums, int k) 
    {
        int i = 0, res = 0;
        unordered_map<int, int> cnt;

        for(int j=0;j<nums.size();j++) 
        {
            if(!cnt[nums[j]]++)
            {
                k--;
            } 

            while(k < 0) 
            {
                if (!--cnt[nums[i]]) 
                {
                    k++;
                }
                i++;
            }

            res += j - i + 1;
        }

        return res;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    }
};
