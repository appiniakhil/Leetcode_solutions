class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    // int singleNumber(vector<int>& nums) {
    //     int n = nums.size();

    //     unordered_map<int, int> mp;

    //     for(int i=0;i<n;i++)
    //     {
    //         mp[nums[i]]++;
    //     }

    //     for(auto& i : mp)
    //     {
    //         if(i.second == 1)
    //         {
    //             return i.first;
    //         }
    //     }

    //     return -1;
    // }

    //Time Complexity :O(n) && Space Complexity :O(1)
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        int ones = 0, twos = 0;

        for(int i=0;i<n;i++)
        {
            ones = (ones ^ nums[i]) & ~twos;

            twos = (twos ^ nums[i]) & ~ones;
        }
        
        return ones;
    }
};
