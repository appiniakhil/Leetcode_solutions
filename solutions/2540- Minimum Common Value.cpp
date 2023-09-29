class Solution {
public:
    //Time Limit Exceeded
    //Time Complexity :O(n * m) && Spsce Complexity :O(1)
    // int getCommon(vector<int>& nums1, vector<int>& nums2) {
    //     int n = nums1.size();
    //     int m = nums2.size();

    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<m;j++)
    //         {
    //             if(nums1[i] == nums2[j])
    //             {
    //                 return nums1[i];
    //             }
    //         }
    //     }

    //     return -1;
    // }

    //Time Complexity :O(n + m) && Spsce Complexity :O(1)
    // int getCommon(vector<int>& nums1, vector<int>& nums2) {
    //     int n = nums1.size();
    //     int m = nums2.size();

    //     int i=0, j=0;

    //     while(i<n && j < m)
    //     {
    //         if(nums1[i] == nums2[j])
    //         {
    //             return nums1[i];
    //         }
    //         else if (nums1[i] < nums2[j])
    //         {
    //             i++;
    //         }
    //         else
    //         {
    //             j++;
    //         }
    //     }

    //     return -1;
    // }

    //Time Complexity :O(nlogm) && Spsce Complexity :O(1)
    bool helper(vector<int>& nums, int target)
    {
        int n = nums.size();

        int l = 0, h = n-1;

        while(l <= h)
        {
            int mid = l + (h-l)/2;

            if(nums[mid] == target)
            {
                return true;
            }
            else if(nums[mid] < target)
            {
                l = mid+1;
            }
            else
            {
                h = mid-1;
            }
        }

        return false;
    }

    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        for(int i=0;i<n;i++)
        {
            if(helper(nums2, nums1[i]))
            {
                return nums1[i];
            }
        }

        return -1;
    }
};
