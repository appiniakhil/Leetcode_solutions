class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = 0;

        for(int i=0;i<n;i++) 
        {
            if(m < nums[i].size())
            {
                m = nums[i].size();
            }
        }

        vector<vector<int>> dummy(m+n);
        vector<int> ans;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                dummy[i+j].push_back(nums[i][j]);
            }
        }

        for(int i=0;i<m+n;i++)
        {
            reverse(dummy[i].begin(), dummy[i].end());
        }

        for(int i=0;i<m+n;i++)
        {
            for(int j=0;j<dummy[i].size();j++)
            {
                ans.push_back(dummy[i][j]);
            }
        }

        return ans;
    }
};
