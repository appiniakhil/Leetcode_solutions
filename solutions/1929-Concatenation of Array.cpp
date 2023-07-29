class Solution {
public:

    //Time Complexity :O(n) && Space Complexity :O(1)
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            nums.push_back(nums[i]);
        }

        return nums;
    }
};
