class Solution {
public:
    //Time Complexity :O(n * n) && Space Complexity :O(n)
    vector<int> decompressRLElist(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;
        for(int i=0;i<n;i += 2)
        {
            int j = 0;
            while(j <  nums[i])
            {
                ans.push_back(nums[i + 1]);
                j++;
            }
        }

        return ans;
    }
};
