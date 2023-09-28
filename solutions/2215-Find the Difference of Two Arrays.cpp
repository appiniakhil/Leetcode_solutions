class Solution {
public:

    //Time Complexity :O(n + m) && Space Complexity :O(n + m)
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());

        vector<int> ans1;
        vector<int> ans2;

        int n = nums1.size();
        int m = nums2.size();

        for(int i : s1)
        {
            if(s2.find(i) == s2.end())
            {
                ans1.push_back(i);
            }
        }

        for(int i : s2)
        {
            if(s1.find(i) == s1.end())
            {
                ans2.push_back(i);
            }
        }

        return {ans1, ans2};
    }
};
