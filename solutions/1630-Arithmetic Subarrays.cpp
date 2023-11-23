class Solution {
public:
    //Time Complexity :O(mnlogn) && Space Complexity :O(n) where m is the number of queries and n is the average length of the subarrays
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;

        for(int i = 0;i<l.size();i++) 
        {
            vector<int> v(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(v.begin(), v.end());
            int diff = v[1] - v[0];
            int j = 2;
            while (j < v.size() && v[j] - v[j - 1] == diff)
            {
                ++j;
            }
            res.push_back(j == v.size());
        }
        return res;
    }
};
