class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> ans;

        for(auto& i : nums)
        {
            mp[i]++;
        }

        for(int i=1;i<=n;i++)
        {
            if(mp[i] == 2)
            {
                ans.push_back(i);
            }
        }

        for(int i=1;i<=n;i++)
        {
            if(mp[i] == 0)
            {
                ans.push_back(i);
                break;
            }
        }

        return ans;
    }
};
