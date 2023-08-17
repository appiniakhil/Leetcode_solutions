class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    vector<int> shuffle(vector<int>& nums, int n) {
        int m = nums.size();
        vector<int> ans;

        int i = 0;
        int j = n;
        while(i < n && j < m)
        {
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            i++;
            j++;
        }
        
        return ans;
    }
};
