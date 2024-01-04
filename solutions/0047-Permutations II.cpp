class Solution {
public:
    //Time Complexity :o(n!) && Space Complexity :O(n)
    void helper(vector<int>& nums, vector<bool>& vis, vector<int>& currPerm, vector<vector<int>>& res)
    {
        if(currPerm.size() == nums.size())
        {
            res.push_back(currPerm);
            return ;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(vis[i] || (i>0 && nums[i] == nums[i-1] && !vis[i-1]))
            {
                continue;
            }

            vis[i] = true;

            currPerm.push_back(nums[i]);

            helper(nums, vis, currPerm, res);

            vis[i] = false;
            currPerm.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> currPerm;
        vector<bool> vis(nums.size(), false);

        helper(nums, vis, currPerm ,ans);

        return ans;
    }
};
