class Solution {
public:

    //Time Complexity :O(log(m+n)) && Space Complexity :O(m + n)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int i = 0, j = 0;

        vector<int> ans;

        while (i < m && j < n) 
        {
            if (nums1[i] < nums2[j]) 
            {
                ans.push_back(nums1[i]);
                i++;
            }
            else 
            {
                ans.push_back(nums2[j]);
                j++;
            }
        }

        for (; i < m; i++)
        {
            ans.push_back(nums1[i]); 
        }

        for (; j < n; j++) 
        {
            ans.push_back(nums2[j]);
        }

        nums1 = ans;

        int size = nums1.size();

        if(size %2 == 1)
        {
            return nums1[size/2];
        }

        return (float)(nums1[size/2] + nums1[size/2 -1])/2;

    }
