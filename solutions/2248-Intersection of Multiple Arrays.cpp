class Solution {
public:
    //Time Complexity :O(m*nlogn) && Space Complexity :O(m*nlogn)
    vector<int> intersection(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        
        for(int i=0;i<m;i++)
        {
            sort(nums[i].begin(), nums[i].end());
        }
        
        vector<int> ans;
        
        for(int j = 0; j < n; j++) 
        {
            bool commonElement = true;
            for(int i = 1; i < m; i++) 
            {
                auto it = lower_bound(nums[i].begin(), nums[i].end(), nums[0][j]);
                if (it == nums[i].end() || *it != nums[0][j]) 
                {
                    commonElement = false;
                    break;
                }
            }
            if (commonElement) {
                ans.push_back(nums[0][j]);
            }
        }
        
        return ans;
    }
};
