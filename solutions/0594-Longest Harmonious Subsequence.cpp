class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    int findLHS(vector<int>& nums) {
        map<int, int> mp;

        for(int i : nums)
        {
            mp[i]++;
        }

        int cnt = 0;

        for(auto it : mp)
        {
            if(mp.count(it. first + 1))
            {
                cnt = max(cnt, it.second + mp[it.first + 1]);
            }
        }

        return cnt;
    }
};
