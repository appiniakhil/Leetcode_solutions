class Solution {
public:
    //Time Complecity :O(nlogn) && Space Complexity : O(1)
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> ans;

        for(int i=0;i<n;i++)
        {
            if(nums[i] == target)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
