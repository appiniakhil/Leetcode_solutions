class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    // int maximumCount(vector<int>& nums) {
    //     int n = nums.size();

    //     int pos = 0;
    //     int neg = 0;

    //     for(int i=0;i<n;i++)
    //     {
    //         if(nums[i] > 0)
    //         {
    //             pos++;
    //         }
    //         else if(nums[i] < 0)
    //         {
    //             neg++;
    //         }
    //     }

    //     return max(pos, neg);
    // }

    //Time Complexity :O(2logn) && Space Complexity :O(1)
    int binaryneg(vector<int>& nums)
    {
        int n = nums.size();
        int l = 0, h = n-1;

        int neg = 0;
        while(l <= h)
        {
            int mid = l + (h-l)/2;
            if(nums[mid] < 0)
            {
                neg = mid+1;
                l = mid+1;
            }
            else
            {
                h = mid-1;
            }
        }

        return neg;
    }

    int binarypos(vector<int>& nums)
    {
        int n = nums.size();
        int l = 0, h = n-1;

        int pos = 0;
        while(l <= h)
        {
            int mid = l + (h-l)/2;
            if(nums[mid] > 0)
            {
                pos = n - mid;
                h = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }

        return pos;
    }

    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        int neg = binaryneg(nums);
        int pos = binarypos(nums);

        return max(pos, neg);
    }
};
