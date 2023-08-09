class Solution {
public: 

    //Two pointer Approach
    //Time Complexity :O(nlogn + mlogm) && Space Complexity :O(min(n,m))
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> ans;
        int i=0,j=0;

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

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
                ans.push_back(nums1[i]);
                j++;
                i++;
            }
        }

        return ans;
    }
};
