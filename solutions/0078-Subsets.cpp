class Solution {
public:
    //Time Complexity :O(2 ^ n) && Space Complexity :O(2 ^ n + n)
    void helper(vector<int>& nums, int ind, vector<int>& curr,vector<vector<int>>& res)
    {
        int n = nums.size();

        res.push_back(curr);

        for(int i=ind;i<n;i++)
        {
            curr.push_back(nums[i]);
            helper(nums,i+1,curr,res);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;

        helper(nums,0,curr,ans);

        return ans;
    }
};
