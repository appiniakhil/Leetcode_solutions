class Solution {
public:
    //Using Recursion
    //Time Complexity :O(n!*n) && Space Complexity :O(n)+O(n)
    void recurPermute(vector<int> &ds, vector<int> &arr, vector<vector<int>> &ans, int freq[])
    {
        if(ds.size() == arr.size())
        {
            ans.push_back(ds);
            return;
        }

        for(int i =0;i<arr.size();i++)
        {
            if(!freq[i])
            {
                ds.push_back(arr[i]);
                freq[i] = 1;
                recurPermute(ds,arr,ans,freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        for(int i =0;i<nums.size();i++) freq[i] = 0;
        recurPermute(ds,nums,ans,freq);
        return ans;
    }
};
