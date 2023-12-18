class Solution {
public:
    //Time Complexity :O(nlogn) && Space Complexity :O(n*n)
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i+=3)
        {
            if(i+2 < n && nums[i+2] - nums[i] <= k)
            {
                ans.push_back({nums[i],nums[i+1],nums[i+2]});
            }
            else
            {
                return {};
            }
        }
        
        return ans;
    }
};
