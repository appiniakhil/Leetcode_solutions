class Solution {
public:

    //Two pointer
    //Time Complexity :O(nlogn) && Space Complexity :O(n)
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;

        int i = 0,j = 0;
        int n = nums1.size();
        int m = nums2.size();

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        while(i<n && j<m)
        {
            if(nums1[i] > nums2[j])
            {
                j++;
            }
            else if(nums1[i] < nums2[j])
            {
                i++;
            }
            else
            {
                s.insert(nums1[i]);
                i++;
                j++;
            }
        }

        vector<int> res;
        for(auto i: s)
        {
            res.push_back(i);
        }

        return res;
    }
};
