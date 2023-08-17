class Solution {
public:
    //Using Built in function
    //Time Complexity :O(n * n) && Space Complexity :O(n)
    // vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    //     int n = nums.size();
    //     vector<int> ans;

    //     for(int i=0;i<n;i++)
    //     {
    //         ans.insert(ans.begin() + index[i],nums[i]);
    //     }

    //     return ans;
    // }

    //Time Complexity :O(n * n) && Space Complexity :O(n)
    void helper(vector<int>& ans,int value,int pos)
    {
        int n = ans.size();
        for(int i=n-1;i>pos;i--)
        {
            ans[i] = ans[i-1];
        }

        ans[pos] = value;
    }

    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int> ans(n, -1);
        
        for(int i=0;i<n;i++)
        {
            helper(ans, nums[i], index[i]);
        }

        return ans;
    }
};
