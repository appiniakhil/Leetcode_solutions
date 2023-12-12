class Solution {
public:
    //Time Complexity :O(n + m) && Space Complexity :O(n + m)
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m=nums2.size();
        
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        
        int cnt1 = 0, cnt2 = 0;

        for(int num : nums1) 
        {
            if(s2.count(num) > 0) 
            {
                cnt1++;
            }
        }

        for(int num : nums2) 
        {
            if(s1.count(num) > 0) 
            {
                cnt2++;
            }
        }

        return {cnt1, cnt2};
    }
};
