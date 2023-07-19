class Solution {
public:

    //Naive Approach
    //Time Complexity :O((m+n)log(m+n)) && Space Complexity :O(m+n)
    // void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //     int i=0,j=0;

    //     vector<int> ans;
        
    //     while(i<m)
    //     {
    //         ans.push_back(nums1[i]);
    //         i++;
    //     }
        
    //     while(j<n)
    //     {
    //         ans.push_back(nums2[j]);
    //         j++;
    //     }
        
    //     sort(ans.begin(), ans.end());

    //     nums1 = ans;
    // }

    //Optimised Approach
    //Time Complexity :O(m+n) && Space Complexity :O(m+n)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
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
    }
};
