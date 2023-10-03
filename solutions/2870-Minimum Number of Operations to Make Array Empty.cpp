class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(auto& i : nums)
        {
            mp[i]++;
        }

        int cnt = 0;

        for(auto& i : mp)
        {
            int freq = i.second;
            if(freq == 1)
            {
                return -1;
            }
            else if(freq %3 == 0)
            {
                cnt += freq/3;
            }
            else
            {
                cnt += freq/3;
                cnt++;
            }
        }

        return cnt;
    }
};
