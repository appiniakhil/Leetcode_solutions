class Solution {
public:

    //Time Complexity :O(n) && Space Complexity :O(n)
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i] < pivot)
            {
                ans.push_back(nums[i]);
            }
        }

        for(int i=0;i<n;i++)
        {
            if(nums[i] == pivot)
            {
                ans.push_back(nums[i]);
            }
        }

        for(int i=0;i<n;i++)
        {
            if(nums[i] > pivot)
            {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};
