class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    // vector<int> singleNumber(vector<int>& nums) {
    //     int n = nums.size();

    //     vector<int> ans;
    //     unordered_map<int, int> mp;

    //     for(int i=0;i<n;i++)
    //     {
    //         mp[nums[i]]++;
    //     }

    //     for(auto& i : mp)
    //     {
    //         if(i.second == 1)
    //         {
    //             ans.push_back(i.first);
    //         }
    //     }

    //     return ans;
    // }

    //Time Complexity :O(n) && Space Complexity :O(1)
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();

        int bitmask = 0;

        for(int num : nums) 
        {
            bitmask ^= num;
        }

        int diff = bitmask & (~(static_cast<unsigned int>(bitmask) - 1));

        int x = 0;
        for(int num : nums) 
        {
            if((num & diff) != 0) 
            {
                x ^= num;
            }
        }

        return {x, bitmask ^ x};
    }
};
