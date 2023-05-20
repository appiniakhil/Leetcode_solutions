class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Naive Approach
        //Time Complexity : O(n^2)
        // vector<int> ans;
        // int n = nums.size();
        // for(int i =0;i<n;i++)
        // {
        //     for(int j =i+1;j<n;j++)
        //     {
        //         if(nums[i] + nums[j] == target)
        //         {
        //             ans.push_back(i);
        //             ans.push_back(j);
        //         }
        //     }
        // }
        // return ans;

        //Optimised Approach
        //Time Complexity : O(n) 
        unordered_map<int, int> hash;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) 
        {
            int remaining = target - nums[i];
            if (hash.find(remaining) != hash.end()) 
            {
                ans.push_back(hash[remaining]);
                ans.push_back(i);
                break;
            }
            hash[nums[i]] = i;
        }
        return ans;

    }
};
