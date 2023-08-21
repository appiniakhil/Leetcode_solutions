class Solution {
public:
    //Time Complecity :O(n) && Space Complexity :O(n)
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        int cnt = 0;

        unordered_map<int, bool> mp;

        for(int i=0;i<n;i++)
        {
            mp[nums[i]] = true;
        }

        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]-diff]== true && mp[nums[i] + diff] == true)
            {
                cnt++;
            }
        }

        return cnt;
    }
};
